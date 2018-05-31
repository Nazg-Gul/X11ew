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

#include "x11ew_private.h"

static DynamicLibrary* library;

/* Function implementation definitions. */
tXGetXCBConnection* XGetXCBConnection_impl;
tXSetEventQueueOwner* XSetEventQueueOwner_impl;

/* Function wrappers. */
xcb_connection_t* XGetXCBConnection(Display *dpy) {
  return XGetXCBConnection_impl(dpy);
}

void XSetEventQueueOwner(Display* dpy, enum XEventQueueOwner owner) {
  return XSetEventQueueOwner_impl(dpy, owner);
}

int __x11ew_init_xlib_xcb(void) {
  /* Library paths. */
#ifdef _WIN32
  const char *paths[] = {NULL};
#elif defined(__APPLE__)
  const char *paths[] = {NULL};
#else
  const char *paths[] = {"libX11-xcb.so", "libX11-xcb.so.1"};
#endif
  /* Load library. */
  library = x11ew_dynamic_library_open_find(paths);
  if (library == NULL) {
    return X11EW_ERROR_OPEN_FAILED;
  }
  /* Fetch all function pointers. */
  _LIBRARY_FIND(library, XGetXCBConnection);
  _LIBRARY_FIND(library, XSetEventQueueOwner);
  return X11EW_SUCCESS;
}

void __x11ew_exit_xlib_xcb(void) {
  if (library != NULL) {
    dynamic_library_close(library);
    library = NULL;
  }
}

