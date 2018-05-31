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

#ifndef __X11EW_XLIB_XCB_H__
#define __X11EW_XLIB_XCB_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Types. */
typedef struct xcb_connection_t xcb_connection_t;
enum XEventQueueOwner {
  XlibOwnsEventQueue = 0,
  XCBOwnsEventQueue
};

/* Function prototypes. */
xcb_connection_t* XGetXCBConnection(Display* dpy);
void XSetEventQueueOwner(Display* dpy, enum XEventQueueOwner owner);

/* Function types. */
typedef xcb_connection_t* tXGetXCBConnection(Display* dpy);
typedef void tXSetEventQueueOwner(Display* dpy, enum XEventQueueOwner owner);

/* Function implementation declarations. */
extern tXGetXCBConnection* XGetXCBConnection_impl;
extern tXSetEventQueueOwner* XSetEventQueueOwner_impl;

/* Private methods, only used by wrangler. */
int __x11ew_init_xlib_xcb(void);
void __x11ew_exit_xlib_xcb(void);

#ifdef __cplusplus
}
#endif

#endif  /* __X11EW_XLIB_XCB_H__ */
