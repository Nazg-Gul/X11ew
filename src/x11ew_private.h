/*
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

#ifndef __X11EW_PRIVATE_H__
#define __X11EW_PRIVATE_H__

#ifdef _MSC_VER
#  if _MSC_VER < 1900
#    define snprintf _snprintf
#  endif
#  define popen _popen
#  define pclose _pclose
#  define _CRT_SECURE_NO_WARNINGS
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#ifdef _WIN32
#  define WIN32_LEAN_AND_MEAN
#  define VC_EXTRALEAN
#  include <windows.h>

/* Utility macros. */

typedef HMODULE DynamicLibrary;

#  define dynamic_library_open(path)         LoadLibraryA(path)
#  define dynamic_library_close(lib)         FreeLibrary(lib)
#  define dynamic_library_find(lib, symbol)  GetProcAddress(lib, symbol)
#else
#  include <dlfcn.h>

typedef void* DynamicLibrary;

#  define dynamic_library_open(path)         dlopen(path, RTLD_NOW)
#  define dynamic_library_close(lib)         dlclose(lib)
#  define dynamic_library_find(lib, symbol)  dlsym(lib, symbol)
#endif

#define GLUE_IMPL(A, B) A ## B
#define GLUE(A, B) GLUE_IMPL(A, B)

#define IMPL_SUFFIX _impl

#define _LIBRARY_FIND_CHECKED(lib, name) \
        GLUE(name, IMPL_SUFFIX) = (t##name *)dynamic_library_find(lib, #name); \
        assert(name);

#define _LIBRARY_FIND(lib, name) \
        GLUE(name, IMPL_SUFFIX) = (t##name *)dynamic_library_find(lib, #name);

DynamicLibrary x11ew_dynamic_library_open_find(const char** paths);

#endif  /* __X11EW_PRIVATE_H__ */
