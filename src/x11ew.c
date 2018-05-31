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

#include <x11ew.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "x11ew_private.h"

DynamicLibrary x11ew_dynamic_library_open_find(const char** paths) {
  int i = 0;
  while (paths[i] != NULL) {
      DynamicLibrary lib = dynamic_library_open(paths[i]);
      if (lib != NULL) {
        return lib;
      }
      ++i;
  }
  return NULL;
}

static void x11ewExit(void) {
  __x11ew_exit_xlib();
  __x11ew_exit_xlibint();
  __x11ew_exit_xlib_xcb();
}

int x11ewInit(void) {
#define INIT_LIBRARY(name)            \
  do {                                \
    result = __x11ew_init_##name();   \
    if (result != X11EW_SUCCESS) {    \
      return result;                  \
    }                                 \
  } while (0)

  static int initialized = 0;
  static int result = 0;
  int error;
  /* Only initialize once. */
  if (initialized) {
    return result;
  }
  /* Install atexit hook. */
  error = atexit(x11ewExit);
  if (error) {
    result = X11EW_ERROR_ATEXIT_FAILED;
    return result;
  }
  initialized = 1;
  /* Load libraries. */
  INIT_LIBRARY(xlib);
  INIT_LIBRARY(xlibint);
  INIT_LIBRARY(xlib_xcb);
  /* We are al done. */
  return result;

#undef INIT_LIBRARY
}

const char* x11ewErrorString(int error) {
  switch (error) {
    case X11EW_SUCCESS: return "SUCCESS";
    case X11EW_ERROR_OPEN_FAILED: return "OPEN_FAILED";
    case X11EW_ERROR_ATEXIT_FAILED: return "ATEXIT_FAILED";
  }
  return "UNKNOWN";
}
