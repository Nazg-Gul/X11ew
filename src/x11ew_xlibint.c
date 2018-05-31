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
t_XGetRequest *_XGetRequest_impl;
t_XFlushGCCache *_XFlushGCCache_impl;
t_XData32 *_XData32_impl;
t_XRead32 *_XRead32_impl;
t_XDeqAsyncHandler *_XDeqAsyncHandler_impl;
tData *Data_impl;
t_XError *_XError_impl;
t_XIOError *_XIOError_impl;
t_XEatData *_XEatData_impl;
t_XEatDataWords *_XEatDataWords_impl;
t_XAllocScratch *_XAllocScratch_impl;
t_XAllocTemp *_XAllocTemp_impl;
t_XFreeTemp *_XFreeTemp_impl;
t_XVIDtoVisual *_XVIDtoVisual_impl;
t_XSetLastRequestRead *_XSetLastRequestRead_impl;
t_XGetHostname *_XGetHostname_impl;
t_XScreenOfWindow *_XScreenOfWindow_impl;
t_XAsyncErrorHandler *_XAsyncErrorHandler_impl;
t_XGetAsyncReply *_XGetAsyncReply_impl;
t_XGetAsyncData *_XGetAsyncData_impl;
t_XFlush *_XFlush_impl;
t_XEventsQueued *_XEventsQueued_impl;
t_XReadEvents *_XReadEvents_impl;
t_XRead *_XRead_impl;
t_XReadPad *_XReadPad_impl;
t_XSend *_XSend_impl;
t_XReply *_XReply_impl;
t_XEnq *_XEnq_impl;
t_XDeq *_XDeq_impl;
t_XUnknownWireEvent *_XUnknownWireEvent_impl;
t_XUnknownWireEventCookie *_XUnknownWireEventCookie_impl;
t_XUnknownCopyEventCookie *_XUnknownCopyEventCookie_impl;
t_XUnknownNativeEvent *_XUnknownNativeEvent_impl;
t_XWireToEvent *_XWireToEvent_impl;
t_XDefaultWireError *_XDefaultWireError_impl;
t_XPollfdCacheInit *_XPollfdCacheInit_impl;
t_XPollfdCacheAdd *_XPollfdCacheAdd_impl;
t_XPollfdCacheDel *_XPollfdCacheDel_impl;
t_XAllocID *_XAllocID_impl;
t_XAllocIDs *_XAllocIDs_impl;
t_XFreeExtData *_XFreeExtData_impl;
tXESetCreateGC *XESetCreateGC_impl;
tXESetCopyGC *XESetCopyGC_impl;
tXESetFlushGC *XESetFlushGC_impl;
tXESetFreeGC *XESetFreeGC_impl;
tXESetCreateFont *XESetCreateFont_impl;
tXESetFreeFont *XESetFreeFont_impl;
tXESetCloseDisplay *XESetCloseDisplay_impl;
tXESetError *XESetError_impl;
tXESetErrorString *XESetErrorString_impl;
tXESetPrintErrorValues *XESetPrintErrorValues_impl;
tXESetWireToEvent *XESetWireToEvent_impl;
tXESetWireToEventCookie *XESetWireToEventCookie_impl;
tXESetCopyEventCookie *XESetCopyEventCookie_impl;
tXESetEventToWire *XESetEventToWire_impl;
tXESetWireToError *XESetWireToError_impl;
tXESetBeforeFlush *XESetBeforeFlush_impl;
t_XRegisterInternalConnection *_XRegisterInternalConnection_impl;
t_XUnregisterInternalConnection *_XUnregisterInternalConnection_impl;
t_XProcessInternalConnection *_XProcessInternalConnection_impl;
t__XOS2RedirRoot *__XOS2RedirRoot_impl;
t_XTextHeight *_XTextHeight_impl;
t_XTextHeight16 *_XTextHeight16_impl;
t_XOpenFile *_XOpenFile_impl;
t_XOpenFileMode *_XOpenFileMode_impl;
t_XFopenFile *_XFopenFile_impl;
t_XAccessFile *_XAccessFile_impl;
t_XEventToWire *_XEventToWire_impl;
t_XF86LoadQueryLocaleFont *_XF86LoadQueryLocaleFont_impl;
t_XProcessWindowAttributes *_XProcessWindowAttributes_impl;
t_XDefaultError *_XDefaultError_impl;
t_XDefaultIOError *_XDefaultIOError_impl;
t_XSetClipRectangles *_XSetClipRectangles_impl;
t_XIsEventCookie *_XIsEventCookie_impl;
t_XFreeEventCookies *_XFreeEventCookies_impl;
t_XStoreEventCookie *_XStoreEventCookie_impl;
t_XFetchEventCookie *_XFetchEventCookie_impl;
t_XCopyEventCookie *_XCopyEventCookie_impl;
txlocaledir *xlocaledir_impl;

/* Function wrappers. */
void* _XGetRequest(Display* dpy, CARD8 type, size_t len) {
  return _XGetRequest_impl(dpy, type, len);
}

void _XFlushGCCache(Display* dpy, GC gc) {
  return _XFlushGCCache_impl(dpy, gc);
}

int _XData32(Display* dpy, register _Xconst long* data, unsigned len) {
  return _XData32_impl(dpy, data, len);
}

void _XRead32(Display* dpy, register long* data, long len) {
  return _XRead32_impl(dpy, data, len);
}

void _XDeqAsyncHandler(Display* dpy, _XAsyncHandler* handler) {
  return _XDeqAsyncHandler_impl(dpy, handler);
}

#ifdef DataRoutineIsProcedure
void Data(Display* dpy, char* data, long len) {
  return Data_impl(dpy, data, len);
}
#endif

int _XError(Display* dpy, xError* rep) {
  return _XError_impl(dpy, rep);
}

int _XIOError(Display* dpy) {
  _XIOError_impl(dpy);
  abort();
}

void _XEatData(Display* dpy, unsigned long n) {
  return _XEatData_impl(dpy, n);
}

void _XEatDataWords(Display* dpy, unsigned long n) {
  return _XEatDataWords_impl(dpy, n);
}

char* _XAllocScratch(Display* dpy, unsigned long nbytes) {
  return _XAllocScratch_impl(dpy, nbytes);
}

char* _XAllocTemp(Display* dpy, unsigned long nbytes) {
  return _XAllocTemp_impl(dpy, nbytes);
}

void _XFreeTemp(Display* dpy, char* buf, unsigned long nbytes) {
  return _XFreeTemp_impl(dpy, buf, nbytes);
}

Visual* _XVIDtoVisual(Display* dpy, VisualID id) {
  return _XVIDtoVisual_impl(dpy, id);
}

unsigned long _XSetLastRequestRead(Display* dpy, xGenericReply* rep) {
  return _XSetLastRequestRead_impl(dpy, rep);
}

int _XGetHostname(char* buf, int maxlen) {
  return _XGetHostname_impl(buf, maxlen);
}

Screen* _XScreenOfWindow(Display* dpy, Window w) {
  return _XScreenOfWindow_impl(dpy, w);
}

Bool _XAsyncErrorHandler(Display* dpy, xReply* rep, char* buf, int len, XPointer data) {
  return _XAsyncErrorHandler_impl(dpy, rep, buf, len, data);
}

char* _XGetAsyncReply(Display* dpy, char* replbuf, xReply* rep, char* buf, int len, int extra, Bool discard) {
  return _XGetAsyncReply_impl(dpy, replbuf, rep, buf, len, extra, discard);
}

void _XGetAsyncData(Display* dpy, char* data, char* buf, int len, int skip, int datalen, int discardtotal) {
  return _XGetAsyncData_impl(dpy, data, buf, len, skip, datalen, discardtotal);
}

void _XFlush(Display* dpy) {
  return _XFlush_impl(dpy);
}

int _XEventsQueued(Display* dpy, int mode) {
  return _XEventsQueued_impl(dpy, mode);
}

void _XReadEvents(Display* dpy) {
  return _XReadEvents_impl(dpy);
}

int _XRead(Display* dpy, char* data, long size) {
  return _XRead_impl(dpy, data, size);
}

void _XReadPad(Display* dpy, char* data, long size) {
  return _XReadPad_impl(dpy, data, size);
}

void _XSend(Display* dpy, _Xconst char* data, long size) {
  return _XSend_impl(dpy, data, size);
}

Status _XReply(Display* dpy, xReply* rep, int extra, Bool discard) {
  return _XReply_impl(dpy, rep, extra, discard);
}

void _XEnq(Display* dpy, xEvent* event) {
  return _XEnq_impl(dpy, event);
}

void _XDeq(Display* dpy, _XQEvent* prev, _XQEvent* qelt) {
  return _XDeq_impl(dpy, prev, qelt);
}

Bool _XUnknownWireEvent(Display* dpy, XEvent* re, xEvent* event) {
  return _XUnknownWireEvent_impl(dpy, re, event);
}

Bool _XUnknownWireEventCookie(Display* dpy, XGenericEventCookie* re, xEvent* event) {
  return _XUnknownWireEventCookie_impl(dpy, re, event);
}

Bool _XUnknownCopyEventCookie(Display* dpy, XGenericEventCookie* in, XGenericEventCookie* out) {
  return _XUnknownCopyEventCookie_impl(dpy, in, out);
}

Status _XUnknownNativeEvent(Display* dpy, XEvent* re, xEvent* event) {
  return _XUnknownNativeEvent_impl(dpy, re, event);
}

Bool _XWireToEvent(Display* dpy, XEvent* re, xEvent* event) {
  return _XWireToEvent_impl(dpy, re, event);
}

Bool _XDefaultWireError(Display* display, XErrorEvent* he, xError* we) {
  return _XDefaultWireError_impl(display, he, we);
}

Bool _XPollfdCacheInit(Display* dpy) {
  return _XPollfdCacheInit_impl(dpy);
}

void _XPollfdCacheAdd(Display* dpy, int fd) {
  return _XPollfdCacheAdd_impl(dpy, fd);
}

void _XPollfdCacheDel(Display* dpy, int fd) {
  return _XPollfdCacheDel_impl(dpy, fd);
}

XID _XAllocID(Display* dpy) {
  return _XAllocID_impl(dpy);
}

void _XAllocIDs(Display* dpy, XID* ids, int count) {
  return _XAllocIDs_impl(dpy, ids, count);
}

int _XFreeExtData(XExtData* extension) {
  return _XFreeExtData_impl(extension);
}

int (* XESetCreateGC(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , GC /* gc */ , XExtCodes* /* codes */ ))) ( Display* , GC , XExtCodes* ) {
  return XESetCreateGC_impl(display, extension, proc);
}

int (* XESetCopyGC(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , GC /* gc */ , XExtCodes* /* codes */ ))) ( Display* , GC , XExtCodes* ) {
  return XESetCopyGC_impl(display, extension, proc);
}

int (* XESetFlushGC(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , GC /* gc */ , XExtCodes* /* codes */ ))) ( Display* , GC , XExtCodes* ) {
  return XESetFlushGC_impl(display, extension, proc);
}

int (* XESetFreeGC(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , GC /* gc */ , XExtCodes* /* codes */ ))) ( Display* , GC , XExtCodes* ) {
  return XESetFreeGC_impl(display, extension, proc);
}

int (* XESetCreateFont(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , XFontStruct* /* fs */ , XExtCodes* /* codes */ ))) ( Display* , XFontStruct* , XExtCodes* ) {
  return XESetCreateFont_impl(display, extension, proc);
}

int (* XESetFreeFont(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , XFontStruct* /* fs */ , XExtCodes* /* codes */ ))) ( Display* , XFontStruct* , XExtCodes* ) {
  return XESetFreeFont_impl(display, extension, proc);
}

int (* XESetCloseDisplay(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , XExtCodes* /* codes */ ))) ( Display* , XExtCodes* ) {
  return XESetCloseDisplay_impl(display, extension, proc);
}

int (* XESetError(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , xError* /* err */ , XExtCodes* /* codes */ , int* /* ret_code */ ))) ( Display* , xError* , XExtCodes* , int* ) {
  return XESetError_impl(display, extension, proc);
}

char* (* XESetErrorString(
    Display* display,
    int extension,
    char* (*proc) ( Display* /* display */ , int /* code */ , XExtCodes* /* codes */ , char* /* buffer */ , int /* nbytes */ ))) ( Display* , int , XExtCodes* , char* , int ) {
  return XESetErrorString_impl(display, extension, proc);
}

void (* XESetPrintErrorValues(
    Display* display,
    int extension,
    void (*proc) ( Display* /* display */ , XErrorEvent* /* ev */ , void* /* fp */ ))) ( Display* , XErrorEvent* , void* ) {
  return XESetPrintErrorValues_impl(display, extension, proc);
}

Bool (* XESetWireToEvent(
    Display* display,
    int event_number,
    Bool (*proc) ( Display* /* display */ , XEvent* /* re */ , xEvent* /* event */ ))) ( Display* , XEvent* , xEvent* ) {
  return XESetWireToEvent_impl(display, event_number, proc);
}

Bool (* XESetWireToEventCookie(
    Display* display,
    int extension,
    Bool (*proc) ( Display* /* display */ , XGenericEventCookie* /* re */ , xEvent* /* event */ ))) ( Display* , XGenericEventCookie* , xEvent* ) {
  return XESetWireToEventCookie_impl(display, extension, proc);
}

Bool (* XESetCopyEventCookie(
    Display* display,
    int extension,
    Bool (*proc) ( Display* /* display */ , XGenericEventCookie* /* in */ , XGenericEventCookie* /* out */ ))) ( Display* , XGenericEventCookie* , XGenericEventCookie* ) {
  return XESetCopyEventCookie_impl(display, extension, proc);
}

Status (* XESetEventToWire(
    Display* display,
    int event_number,
    Status (*proc) ( Display* /* display */ , XEvent* /* re */ , xEvent* /* event */ ))) ( Display* , XEvent* , xEvent* ) {
  return XESetEventToWire_impl(display, event_number, proc);
}

Bool (* XESetWireToError(
    Display* display,
    int error_number,
    Bool (*proc) ( Display* /* display */ , XErrorEvent* /* he */ , xError* /* we */ ))) ( Display* , XErrorEvent* , xError* ) {
  return XESetWireToError_impl(display, error_number, proc);
}

void (* XESetBeforeFlush(
    Display* display,
    int error_number,
    void (*proc) ( Display* /* display */ , XExtCodes* /* codes */ , _Xconst char* /* data */ , long /* len */ ))) ( Display* , XExtCodes* , _Xconst char* , long ) {
  return XESetBeforeFlush_impl(display, error_number, proc);
}

Status _XRegisterInternalConnection(Display* dpy, int fd, _XInternalConnectionProc callback, XPointer call_data) {
  return _XRegisterInternalConnection_impl(dpy, fd, callback, call_data);
}

void _XUnregisterInternalConnection(Display* dpy, int fd) {
  return _XUnregisterInternalConnection_impl(dpy, fd);
}

void _XProcessInternalConnection(Display* dpy, struct _XConnectionInfo* conn_info) {
  return _XProcessInternalConnection_impl(dpy, conn_info);
}

char* __XOS2RedirRoot(char* arg) {
  return __XOS2RedirRoot_impl(arg);
}

int _XTextHeight(XFontStruct* font_struct, _Xconst char* string, int count) {
  return _XTextHeight_impl(font_struct, string, count);
}

int _XTextHeight16(XFontStruct* font_struct, _Xconst XChar2b* string, int count) {
  return _XTextHeight16_impl(font_struct, string, count);
}

#if defined(WIN32)
int _XOpenFile(_Xconst char* path, int flags) {
  return _XOpenFile_impl(path, flags);
}
#endif

#if defined(WIN32)
int _XOpenFileMode(_Xconst char* path, int flags, mode_t mode) {
  return _XOpenFileMode_impl(path, flags, mode);
}
#endif

#if defined(WIN32)
void* _XFopenFile(_Xconst char* path, _Xconst char* mode) {
  return _XFopenFile_impl(path, mode);
}
#endif

#if defined(WIN32)
int _XAccessFile(_Xconst char* path) {
  return _XAccessFile_impl(path);
}
#endif

Status _XEventToWire(Display* dpy, XEvent* re, xEvent* event) {
  return _XEventToWire_impl(dpy, re, event);
}

int _XF86LoadQueryLocaleFont(Display* dpy, _Xconst char* name, XFontStruct** xfp, Font* fidp) {
  return _XF86LoadQueryLocaleFont_impl(dpy, name, xfp, fidp);
}

void _XProcessWindowAttributes(
    register Display* dpy,
    xChangeWindowAttributesReq* req,
    register unsigned long valuemask,
    register XSetWindowAttributes* attributes) {
  return _XProcessWindowAttributes_impl(dpy, req, valuemask, attributes);
}

int _XDefaultError(Display* dpy, XErrorEvent* event) {
  return _XDefaultError_impl(dpy, event);
}

int _XDefaultIOError(Display* dpy) {
  return _XDefaultIOError_impl(dpy);
}

void _XSetClipRectangles(
    register Display* dpy,
    GC gc,
    int clip_x_origin,
    int clip_y_origin,
    XRectangle* rectangles,
    int n,
    int ordering) {
  return _XSetClipRectangles_impl(dpy, gc, clip_x_origin, clip_y_origin, rectangles, n, ordering);
}

Bool _XIsEventCookie(Display* dpy, XEvent* ev) {
  return _XIsEventCookie_impl(dpy, ev);
}

void _XFreeEventCookies(Display* dpy) {
  return _XFreeEventCookies_impl(dpy);
}

void _XStoreEventCookie(Display* dpy, XEvent* ev) {
  return _XStoreEventCookie_impl(dpy, ev);
}

Bool _XFetchEventCookie(Display* dpy, XGenericEventCookie* ev) {
  return _XFetchEventCookie_impl(dpy, ev);
}

Bool _XCopyEventCookie(Display* dpy, XGenericEventCookie* in, XGenericEventCookie* out) {
  return _XCopyEventCookie_impl(dpy, in, out);
}

void xlocaledir(char* buf, int buf_len) {
  return xlocaledir_impl(buf, buf_len);
}


int __x11ew_init_xlibint(void) {
  /* Library paths. */
#ifdef _WIN32
  const char *paths[] = {NULL};
#elif defined(__APPLE__)
  const char *paths[] = {NULL};
#else
  const char *paths[] = {"libX11.so", "libX11.so.6"};
#endif
  /* Load library. */
  library = x11ew_dynamic_library_open_find(paths);
  if (library == NULL) {
    return X11EW_ERROR_OPEN_FAILED;
  }
  /* Fetch all function pointers. */
  _LIBRARY_FIND(library, _XGetRequest);
  _LIBRARY_FIND(library, _XFlushGCCache);
  _LIBRARY_FIND(library, _XData32);
  _LIBRARY_FIND(library, _XRead32);
  _LIBRARY_FIND(library, _XDeqAsyncHandler);
  _LIBRARY_FIND(library, Data);
  _LIBRARY_FIND(library, _XError);
  _LIBRARY_FIND(library, _XIOError);
  _LIBRARY_FIND(library, _XEatData);
  _LIBRARY_FIND(library, _XEatDataWords);
  _LIBRARY_FIND(library, _XAllocScratch);
  _LIBRARY_FIND(library, _XAllocTemp);
  _LIBRARY_FIND(library, _XFreeTemp);
  _LIBRARY_FIND(library, _XVIDtoVisual);
  _LIBRARY_FIND(library, _XSetLastRequestRead);
  _LIBRARY_FIND(library, _XGetHostname);
  _LIBRARY_FIND(library, _XScreenOfWindow);
  _LIBRARY_FIND(library, _XAsyncErrorHandler);
  _LIBRARY_FIND(library, _XGetAsyncReply);
  _LIBRARY_FIND(library, _XGetAsyncData);
  _LIBRARY_FIND(library, _XFlush);
  _LIBRARY_FIND(library, _XEventsQueued);
  _LIBRARY_FIND(library, _XReadEvents);
  _LIBRARY_FIND(library, _XRead);
  _LIBRARY_FIND(library, _XReadPad);
  _LIBRARY_FIND(library, _XSend);
  _LIBRARY_FIND(library, _XReply);
  _LIBRARY_FIND(library, _XEnq);
  _LIBRARY_FIND(library, _XDeq);
  _LIBRARY_FIND(library, _XUnknownWireEvent);
  _LIBRARY_FIND(library, _XUnknownWireEventCookie);
  _LIBRARY_FIND(library, _XUnknownCopyEventCookie);
  _LIBRARY_FIND(library, _XUnknownNativeEvent);
  _LIBRARY_FIND(library, _XWireToEvent);
  _LIBRARY_FIND(library, _XDefaultWireError);
  _LIBRARY_FIND(library, _XPollfdCacheInit);
  _LIBRARY_FIND(library, _XPollfdCacheAdd);
  _LIBRARY_FIND(library, _XPollfdCacheDel);
  _LIBRARY_FIND(library, _XAllocID);
  _LIBRARY_FIND(library, _XAllocIDs);
  _LIBRARY_FIND(library, _XFreeExtData);
  _LIBRARY_FIND(library, XESetCreateGC);
  _LIBRARY_FIND(library, XESetCopyGC);
  _LIBRARY_FIND(library, XESetFlushGC);
  _LIBRARY_FIND(library, XESetFreeGC);
  _LIBRARY_FIND(library, XESetCreateFont);
  _LIBRARY_FIND(library, XESetFreeFont);
  _LIBRARY_FIND(library, XESetCloseDisplay);
  _LIBRARY_FIND(library, XESetError);
  _LIBRARY_FIND(library, XESetErrorString);
  _LIBRARY_FIND(library, XESetPrintErrorValues);
  _LIBRARY_FIND(library, XESetWireToEvent);
  _LIBRARY_FIND(library, XESetWireToEventCookie);
  _LIBRARY_FIND(library, XESetCopyEventCookie);
  _LIBRARY_FIND(library, XESetEventToWire);
  _LIBRARY_FIND(library, XESetWireToError);
  _LIBRARY_FIND(library, XESetBeforeFlush);
  _LIBRARY_FIND(library, _XRegisterInternalConnection);
  _LIBRARY_FIND(library, _XUnregisterInternalConnection);
  _LIBRARY_FIND(library, _XProcessInternalConnection);
  _LIBRARY_FIND(library, __XOS2RedirRoot);
  _LIBRARY_FIND(library, _XTextHeight);
  _LIBRARY_FIND(library, _XTextHeight16);
  _LIBRARY_FIND(library, _XOpenFile);
  _LIBRARY_FIND(library, _XOpenFileMode);
  _LIBRARY_FIND(library, _XFopenFile);
  _LIBRARY_FIND(library, _XAccessFile);
  _LIBRARY_FIND(library, _XEventToWire);
  _LIBRARY_FIND(library, _XF86LoadQueryLocaleFont);
  _LIBRARY_FIND(library, _XProcessWindowAttributes);
  _LIBRARY_FIND(library, _XDefaultError);
  _LIBRARY_FIND(library, _XDefaultIOError);
  _LIBRARY_FIND(library, _XSetClipRectangles);
  _LIBRARY_FIND(library, _XIsEventCookie);
  _LIBRARY_FIND(library, _XFreeEventCookies);
  _LIBRARY_FIND(library, _XStoreEventCookie);
  _LIBRARY_FIND(library, _XFetchEventCookie);
  _LIBRARY_FIND(library, _XCopyEventCookie);
  _LIBRARY_FIND(library, xlocaledir);
  return X11EW_SUCCESS;
}

void __x11ew_exit_xlibint(void) {
  if (library != NULL) {
    dynamic_library_close(library);
    library = NULL;
  }
}

