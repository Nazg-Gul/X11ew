#!/usr/bin/env python

from __future__ import print_function

import clang.cindex
import os
import sys

from clang.cindex import TokenKind


COPYRIGHT = """/*
 * Copyright 2017 Blender Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License
 */
"""


LIBRARIES = {"Xlib.h": "libX11.so",
             "Xlibint.h": "libX11.so",
             "Xlib-xcb.h": "libX11-xcb.so"}


def isFunctionPrototype(tokens):
    """
    Check whether sequence of tokens denotes a function prototype.
    """
    # Simple heuristic: if there is no punctuation, this is not a
    # function prototype.
    for token in tokens:
        if token.kind == TokenKind.PUNCTUATION:
            return True
    return False


def joinTypeTokens(tokens):
    result = ""
    for token in tokens:
        if result and token.spelling != '*':
            result += " "
        result += token.spelling
    return result


def getFunctionReturnType(tokens):
    """
    Get a function return type from sequence of tokens.
    """
    got_type = False
    got_name = False
    inside_argument_list = 0
    done_argument_list = False
    result = []
    for token in tokens:
        if token.spelling == "_X_SENTINEL":
            break
        if token.kind == TokenKind.KEYWORD:
            if token.spelling != 'extern':
                got_type = True
        elif token.kind == TokenKind.IDENTIFIER:
            if got_type:
                got_name = True
            else:
                got_type = True
        elif token.kind == TokenKind.PUNCTUATION:
            if token.spelling == "(":
                if got_name:
                    inside_argument_list += 1
            elif token.spelling == ")":
                if got_name:
                    inside_argument_list -= 1
                    if inside_argument_list == 0:
                        done_argument_list = True
                        continue
        if token.spelling != "extern" and (not got_name or done_argument_list):
            result.append(token)
    result = joinTypeTokens(result)
    result = result.replace("(* )", "(*)")
    return result


def getFunctionName(tokens):
    """
    Get a function name from sequence of tokens.
    """
    got_type = False
    for token in tokens:
        if token.kind == TokenKind.KEYWORD:
            if token.spelling != 'extern':
                got_type = True
        elif token.kind == TokenKind.IDENTIFIER:
            if got_type:
                return token.spelling
            else:
                got_type = True
    return ""


def getArgumentNameFromComment(comment):
    return comment          \
        .replace("/*", "")  \
        .replace("*/", "")  \
        .strip()


def getArgumentInfoFromTokens(tokens):
    name = ""
    type_tokens = tokens
    if tokens[-1].kind == TokenKind.COMMENT:
        name = getArgumentNameFromComment(tokens[-1].spelling)
        type_tokens = tokens[:-1]
    else:
        # TODO(sergey): Make the check more reliable.
        if tokens[-1].spelling in ("len", "str"):
            name = tokens[-1].spelling
            type_tokens = tokens[:-1]
        elif len(tokens) >= 2 and tokens[-2].spelling == '*':
            name = tokens[-1].spelling
            type_tokens = tokens[:-1]
        elif len(tokens) >= 2 and tokens[-2].kind == TokenKind.KEYWORD \
                              and tokens[-1].kind != TokenKind.KEYWORD \
                              and tokens[-1].kind != TokenKind.PUNCTUATION:
            name = tokens[-1].spelling
            type_tokens = tokens[:-1]
        elif len(tokens) == 2 and \
             tokens[-1].kind not in (TokenKind.KEYWORD,
                                     TokenKind.PUNCTUATION):
            name = tokens[-1].spelling
            type_tokens = tokens[:-1]
        elif tokens[-1].spelling not in ('void', '...'):
            name = 'arg'
            type_tokens = tokens[:]
    argument_type = joinTypeTokens(type_tokens)
    argument_type = argument_type.replace("(* )", "(*)")
    argument_type = argument_type.replace("[ ", "[").replace(" ]", "]")
    if name in ("class", "delete", ):
        name += "_"
    return {"name": name,
            "type": argument_type}


def analyzeArgumentTokens(arguments, tokens):
    if not tokens:
        return
    arg = getArgumentInfoFromTokens(tokens)
    if arg["type"] == "unsigned int":
        if "keycode" in arg["name"]:
            return
    arguments.append(arg)


def getFunctionArguments(tokens):
    arguments = []
    got_type = False
    got_name = False
    inside_arglist_interior = 0
    inside_preprocessor = None
    argument_tokens = []
    for token in tokens:
        if got_name:
            if inside_arglist_interior > 0:
                if inside_preprocessor is not None:
                    if inside_preprocessor == '#':
                        if token.spelling == 'if':
                            inside_preprocessor = 'if'
                        elif token.spelling == 'else':
                            inside_preprocessor = None
                        elif token.spelling == 'endif':
                            inside_preprocessor = None
                    elif inside_preprocessor == 'if':
                        inside_preprocessor = None
                    continue
                elif token.kind == TokenKind.PUNCTUATION:
                    if token.spelling == ')':
                        inside_arglist_interior -= 1
                        if inside_arglist_interior == 0:
                            analyzeArgumentTokens(arguments, argument_tokens)
                            break
                    elif token.spelling == '(':
                        inside_arglist_interior += 1
                    elif token.spelling == ',':
                        if inside_arglist_interior == 1:
                            analyzeArgumentTokens(arguments, argument_tokens)
                            argument_tokens = []
                            continue
                    elif token.spelling == '#':
                        inside_preprocessor = '#'
                        continue
                argument_tokens.append(token)
            elif token.kind == TokenKind.PUNCTUATION:
                if token.spelling == '(':
                    inside_arglist_interior += 1
        elif token.kind == TokenKind.KEYWORD:
            if token.spelling != 'extern':
                got_type = True
        elif token.kind == TokenKind.IDENTIFIER:
            if got_type:
                got_name = True
            else:
                got_type = True
    return arguments


def analyzeExternTokens(functions, tokens):
    """
    Analyze tokens sequence between extern and ;.
    """
    if not isFunctionPrototype(tokens):
        return
    return_type = getFunctionReturnType(tokens)
    name = getFunctionName(tokens)
    arguments = getFunctionArguments(tokens)
    functions.append({"name": name,
                      "return_type": return_type,
                      "arguments": arguments})



def functionHasVarargs(function):
    for argument in function["arguments"]:
        if argument["type"] == "...":
            return True
    return False


def generateFunctionArgumentsDeclaration(function, start_column=0):
    arguments = function["arguments"]
    num_arguments = len(arguments)
    argument_index = 0
    result = ""
    single_line = True
    # FIrst, check if we can put everything in a single line.
    total_length = start_column + 2
    for argument in arguments:
        if argument["type"] == "KeyCode":
            single_line = False
            break
        total_length += len(argument["type"]) + len(argument["name"])
        if total_length >= 80:
            single_line = False
            break
    # Setup padding and EOL, used to join arguments together.
    if single_line:
        EOL = " "
        padding = ""
    else:
        EOL = "\n"
        padding = "    "
        result = "\n"
    # Combine actual result.
    for argument in arguments:
        is_last_argument = (argument_index == num_arguments - 1)
        current = "{}{} {}" . format(padding,
                                     argument["type"],
                                     argument["name"])
        if not is_last_argument:
            current += ",{}" . format(EOL)
        if argument["type"] == "KeyCode":
            alt_current = "{}unsigned int {}" . format(padding,
                                                       argument["name"])
            if not is_last_argument:
                alt_current += ",\n"
            current = ("#if NeedWidePrototypes\n" +
                       "{}\n" +
                       "#else\n" +
                       "{}\n" +
                       "#endif\n") . format(alt_current.rstrip(),
                                            current.rstrip())
        elif "(*)" in argument["type"]:
            current = padding + argument["type"].replace(
                    "(*)", "(*" + argument["name"] + ")")
            if not is_last_argument:
                current += ",{}" . format(EOL)
        elif "[" in argument["type"]:
            arg = argument["type"].replace("[", argument["name"] + "[")
            current = "{}{}" . format(padding, arg)
        result += current
        argument_index += 1
    return result


def wrapCodeWithIfdef(function_name, code):
    """
    For a given funtion name, wraps code with corresponding ifdef.

    This is annoying manual way to deal with functions delcared
    inside of if-def blocks/
    """
    if function_name in ("_XOpenFileMode",
                         "_XOpenFile",
                         "_XFopenFile",
                         "_XAccessFile"):
        return "#if defined(WIN32)\n" + code +"#endif\n"
    elif function_name == "Data":
        return "#ifdef DataRoutineIsProcedure\n" + code +"#endif\n"
    return code


def generateFunctionDeclaration(function):
    """
    Generate declaration for the function.
    """
    if "(*)" in function["return_type"]:
        arguments = generateFunctionArgumentsDeclaration(function, 80)
        type_name_with_arguments = "(* {}({}))".format(function["name"],
                                                       arguments)
        type_with_return = function["return_type"].replace(
                "(*)",
                type_name_with_arguments)
        result = type_with_return
    else:
        result = "{} {}(" . format(function["return_type"],
                                   function["name"])
        arguments = generateFunctionArgumentsDeclaration(function)
        result += arguments + ")"
    return result


def generateTypedefs(functions):
    """
    Generate type definitions for symbols which we dlsym() from
    library.
    """
    result = ""
    for function in functions:
        if "(*)" in function["return_type"]:
            arguments = generateFunctionArgumentsDeclaration(function, 80)
            type_name_with_arguments = "(* t{}({}))".format(function["name"],
                                                            arguments)
            type_with_return = function["return_type"].replace(
                    "(*)",
                    type_name_with_arguments)
            typedef = "typedef {};" . format(type_with_return)
        else:
            typedef = "typedef {} t{}(" . format(function["return_type"],
                                                 function["name"])
            arguments = generateFunctionArgumentsDeclaration(function,
                                                             len(typedef))
            typedef += arguments + ");"
        if result:
            result += "\n"
        result += typedef
    return result


def generateImplDeclarations(functions):
    """
    Generate declaration for implementation functions.
    """
    result = ""
    for function in functions:
        name = function["name"]
        result += "extern t{} *{}_impl;\n" . format(name, name)
    return result


def generateImplDefinitions(functions):
    """
    Generate definition for implementation functions.
    """
    result = ""
    for function in functions:
        name = function["name"]
        result += "t{} *{}_impl;\n" . format(name, name)
    return result


def generateFunctionWrappers(functions):
    result = ""
    for function in functions:
        if functionHasVarargs(function):
            continue
        argument_names = [ arg["name"] for arg in function["arguments"] ]
        joined_arguments = ", ".join(argument_names)
        declaration = generateFunctionDeclaration(function)
        code = declaration + " {\n"
        call = "{}_impl({})" . format(function["name"],
                               joined_arguments)
        if function["name"] == "_XIOError":
            call = "  " + call + ";\n"
            call += "  abort();\n"
        else:
            call = "  return " + call + ";\n"
        code += call
        code += "}\n"
        result += wrapCodeWithIfdef(function["name"], code) + "\n"
    return result


def generateFunctionLoaders(functions):
    result = ""
    for function in functions:
        result += "  _LIBRARY_FIND(library, {});\n" . format(function["name"])
    return result


def getLibrariesListCode(filename):
    header_name = os.path.basename(filename)
    library = LIBRARIES[header_name]
    libraries = ('"' + library + '"',
                 '"' + library + ".6\"", )
    result = """#ifdef _WIN32
  const char *paths[] = {NULL};
#elif defined(__APPLE__)
  const char *paths[] = {NULL};
#else
  const char *paths[] = {""" + ", ".join(libraries) + """};
#endif
"""

    return result


def identifier(str):
    """
    Make string usable a an identifier
    """
    result = str.replace('-', "_")
    return result


def saveWranglerFiles(filename,
                      function_typedefs,
                      function_impl_declarations,
                      function_impl_definitions,
                      function_wrappers,
                      function_loaders):
    # Contruct name prefix for wrangler.
    library_name = os.path.basename(filename).split('.')[0].lower()
    base_name = "x11ew_" + library_name
    # Get project root directory,
    root_dir = os.path.dirname(os.path.realpath(__file__))
    root_dir = os.path.dirname(root_dir)
    # Write header.
    header_filename = os.path.join(root_dir, "include", base_name + ".h")
    header_guard = "__" + identifier(base_name.upper()) + "_H__"
    with open(header_filename, "w") as f:
        f.write(COPYRIGHT)
        f.write("\n#ifndef {}\n#define {}\n\n" . format(header_guard,
                                                        header_guard))
        f.write("#ifdef __cplusplus\n")
        f.write("extern \"C\" {\n")
        f.write("#endif\n\n")
        f.write("/* Function types. */\n")
        f.write(function_typedefs)
        f.write("\n\n/* Function implementation declarations. */\n")
        f.write(function_impl_declarations)
        f.write("\n/* Private methods, only used by wrangler. */\n" .
                format(library_name))
        f.write("int __x11ew_init_{}(void);\n" .
                format(identifier(library_name)))
        f.write("void __x11ew_exit_{}(void);\n" .
                format(identifier(library_name)))
        f.write("\n#ifdef __cplusplus\n")
        f.write("}\n")
        f.write("#endif\n\n")
        f.write("#endif  /* {} */\n" . format(header_guard))
    # Write implementation.
    impl_filename = os.path.join(root_dir, "src", base_name + ".c")
    with open(impl_filename, "w") as f:
        f.write(COPYRIGHT)
        f.write("\n#include <x11ew.h>\n")
        f.write("\n#include \"x11ew_private.h\"\n")
        f.write("\nstatic DynamicLibrary* library;\n\n")
        f.write("/* Function implementation definitions. */\n")
        f.write(function_impl_definitions)
        f.write("\n/* Function wrappers. */\n")
        f.write(function_wrappers)
        f.write("\nint __x11ew_init_{}(void)" .
                 format(identifier(library_name)) + " {\n")
        f.write("  /* Library paths. */\n")
        f.write(getLibrariesListCode(filename))
        f.write("  /* Load library. */\n")
        f.write("  library = x11ew_dynamic_library_open_find(paths);\n")
        f.write("  if (library == NULL) {\n")
        f.write("    return X11EW_ERROR_OPEN_FAILED;\n")
        f.write("  }\n")
        f.write("  /* Fetch all function pointers. */\n")
        f.write(function_loaders)
        f.write("  return X11EW_SUCCESS;\n")
        f.write("}\n\n")
        f.write("void __x11ew_exit_{}(void)" .
                format(identifier(library_name)) + " {\n")
        f.write("  if (library != NULL) {\n")
        f.write("    dynamic_library_close(library);\n")
        f.write("    library = NULL;\n")
        f.write("  }\n")
        f.write("}\n\n")


def main(filename):
    functions = []
    # Initialize state machine.
    in_extern = False
    extern_tokens = []
    is_first_opening_bracket = False
    is_expecting_no_star = False
    need_check_for_function = False
    # Initialize parser.
    idx = clang.cindex.Index.create()
    tu = idx.parse(filename)
    for token in tu.get_tokens(extent=tu.cursor.extent):
        if token.spelling == "#define":
            continue
        if token.kind == TokenKind.KEYWORD:
            if token.spelling == 'extern':
                in_extern = True
                is_first_opening_bracket = True
                is_expecting_no_star = False
                extern_tokens.append(token)
            elif in_extern:
                extern_tokens.append(token)
                is_expecting_no_star = False
        elif token.kind == TokenKind.PUNCTUATION:
            if token.spelling == ';':
                if len(extern_tokens) > 1:
                    analyzeExternTokens(functions, extern_tokens)
                    if need_check_for_function:
                        function = functions[-1]
                        if function["name"].endswith("_fn")  or \
                           function["name"].endswith("Function"):
                            functions = functions[:-1]
                extern_tokens = []
                in_extern = False
                need_check_for_function = False
            elif in_extern:
                if token.spelling == '(':
                    if is_first_opening_bracket:
                        is_expecting_no_star = True
                    else:
                        is_expecting_no_star = False
                    is_first_opening_bracket = False
                elif token.spelling == '*':
                    if is_expecting_no_star:
                        need_check_for_function = True
                else:
                    is_expecting_no_star = False
                extern_tokens.append(token)
        elif in_extern:
            is_expecting_no_star = False
            spelling = token.spelling
            if spelling in ('_XLIB_COLD', '_X_NORETURN'):
                continue
            extern_tokens.append(token)
    # Now we have list of all functions and can do some real
    # wrangler geenration now.
    function_typedefs = generateTypedefs(functions)
    function_impl_declarations = generateImplDeclarations(functions)
    function_impl_definitions = generateImplDefinitions(functions)
    function_wrappers = generateFunctionWrappers(functions)
    function_loaders = generateFunctionLoaders(functions)
    saveWranglerFiles(filename,
                      function_typedefs,
                      function_impl_declarations,
                      function_impl_definitions,
                      function_wrappers,
                      function_loaders)


if __name__ == "__main__":
    headers = ["/usr/include/X11/Xlib.h",
               "/usr/include/X11/Xlibint.h",
              ]
    if len(sys.argv) == 2:
        headers = [sys.argv[1]]
    for header in headers:
        main(header)
