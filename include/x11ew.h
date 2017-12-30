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

#ifndef __X11EW_H__
#define __X11EW_H__

#include <X11/Xlib.h>

#include "x11ew_xlib.h"

#ifdef __cplusplus
extern "C" {
#endif

/* X11 extension wrangler API. */

enum {
  X11EW_SUCCESS = 0,
  X11EW_ERROR_OPEN_FAILED = -1,
  X11EW_ERROR_ATEXIT_FAILED = -2,
};

int x11ewInit(void);

#ifdef __cplusplus
}
#endif

#endif  /* __XX11EW_H__ */
