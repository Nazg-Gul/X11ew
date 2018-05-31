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

#ifndef __X11EW_XLIBINT_H__
#define __X11EW_XLIBINT_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Function types. */
typedef void* t_XGetRequest(Display* dpy, CARD8 type, size_t len);
typedef void t_XFlushGCCache(Display* dpy, GC gc);
typedef int t_XData32(Display* dpy, register _Xconst long* data, unsigned len);
typedef void t_XRead32(Display* dpy, register long* data, long len);
typedef void t_XDeqAsyncHandler(Display* dpy, _XAsyncHandler* handler);
typedef void tData(Display* dpy, char* data, long len);
typedef int t_XError(Display* dpy, xError* rep);
typedef int t_XIOError(Display* dpy);
typedef void t_XEatData(Display* dpy, unsigned long n);
typedef void t_XEatDataWords(Display* dpy, unsigned long n);
typedef char* t_XAllocScratch(Display* dpy, unsigned long nbytes);
typedef char* t_XAllocTemp(Display* dpy, unsigned long nbytes);
typedef void t_XFreeTemp(Display* dpy, char* buf, unsigned long nbytes);
typedef Visual* t_XVIDtoVisual(Display* dpy, VisualID id);
typedef unsigned long t_XSetLastRequestRead(Display* dpy, xGenericReply* rep);
typedef int t_XGetHostname(char* buf, int maxlen);
typedef Screen* t_XScreenOfWindow(Display* dpy, Window w);
typedef Bool t_XAsyncErrorHandler(
    Display* dpy,
    xReply* rep,
    char* buf,
    int len,
    XPointer data);
typedef char* t_XGetAsyncReply(
    Display* dpy,
    char* replbuf,
    xReply* rep,
    char* buf,
    int len,
    int extra,
    Bool discard);
typedef void t_XGetAsyncData(
    Display* dpy,
    char* data,
    char* buf,
    int len,
    int skip,
    int datalen,
    int discardtotal);
typedef void t_XFlush(Display* dpy);
typedef int t_XEventsQueued(Display* dpy, int mode);
typedef void t_XReadEvents(Display* dpy);
typedef int t_XRead(Display* dpy, char* data, long size);
typedef void t_XReadPad(Display* dpy, char* data, long size);
typedef void t_XSend(Display* dpy, _Xconst char* data, long size);
typedef Status t_XReply(Display* dpy, xReply* rep, int extra, Bool discard);
typedef void t_XEnq(Display* dpy, xEvent* event);
typedef void t_XDeq(Display* dpy, _XQEvent* prev, _XQEvent* qelt);
typedef Bool t_XUnknownWireEvent(Display* dpy, XEvent* re, xEvent* event);
typedef Bool t_XUnknownWireEventCookie(
    Display* dpy,
    XGenericEventCookie* re,
    xEvent* event);
typedef Bool t_XUnknownCopyEventCookie(
    Display* dpy,
    XGenericEventCookie* in,
    XGenericEventCookie* out);
typedef Status t_XUnknownNativeEvent(Display* dpy, XEvent* re, xEvent* event);
typedef Bool t_XWireToEvent(Display* dpy, XEvent* re, xEvent* event);
typedef Bool t_XDefaultWireError(Display* display, XErrorEvent* he, xError* we);
typedef Bool t_XPollfdCacheInit(Display* dpy);
typedef void t_XPollfdCacheAdd(Display* dpy, int fd);
typedef void t_XPollfdCacheDel(Display* dpy, int fd);
typedef XID t_XAllocID(Display* dpy);
typedef void t_XAllocIDs(Display* dpy, XID* ids, int count);
typedef int t_XFreeExtData(XExtData* extension);
typedef int (* tXESetCreateGC(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , GC /* gc */ , XExtCodes* /* codes */ ))) ( Display* , GC , XExtCodes* );
typedef int (* tXESetCopyGC(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , GC /* gc */ , XExtCodes* /* codes */ ))) ( Display* , GC , XExtCodes* );
typedef int (* tXESetFlushGC(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , GC /* gc */ , XExtCodes* /* codes */ ))) ( Display* , GC , XExtCodes* );
typedef int (* tXESetFreeGC(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , GC /* gc */ , XExtCodes* /* codes */ ))) ( Display* , GC , XExtCodes* );
typedef int (* tXESetCreateFont(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , XFontStruct* /* fs */ , XExtCodes* /* codes */ ))) ( Display* , XFontStruct* , XExtCodes* );
typedef int (* tXESetFreeFont(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , XFontStruct* /* fs */ , XExtCodes* /* codes */ ))) ( Display* , XFontStruct* , XExtCodes* );
typedef int (* tXESetCloseDisplay(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , XExtCodes* /* codes */ ))) ( Display* , XExtCodes* );
typedef int (* tXESetError(
    Display* display,
    int extension,
    int (*proc) ( Display* /* display */ , xError* /* err */ , XExtCodes* /* codes */ , int* /* ret_code */ ))) ( Display* , xError* , XExtCodes* , int* );
typedef char* (* tXESetErrorString(
    Display* display,
    int extension,
    char* (*proc) ( Display* /* display */ , int /* code */ , XExtCodes* /* codes */ , char* /* buffer */ , int /* nbytes */ ))) ( Display* , int , XExtCodes* , char* , int );
typedef void (* tXESetPrintErrorValues(
    Display* display,
    int extension,
    void (*proc) ( Display* /* display */ , XErrorEvent* /* ev */ , void* /* fp */ ))) ( Display* , XErrorEvent* , void* );
typedef Bool (* tXESetWireToEvent(
    Display* display,
    int event_number,
    Bool (*proc) ( Display* /* display */ , XEvent* /* re */ , xEvent* /* event */ ))) ( Display* , XEvent* , xEvent* );
typedef Bool (* tXESetWireToEventCookie(
    Display* display,
    int extension,
    Bool (*proc) ( Display* /* display */ , XGenericEventCookie* /* re */ , xEvent* /* event */ ))) ( Display* , XGenericEventCookie* , xEvent* );
typedef Bool (* tXESetCopyEventCookie(
    Display* display,
    int extension,
    Bool (*proc) ( Display* /* display */ , XGenericEventCookie* /* in */ , XGenericEventCookie* /* out */ ))) ( Display* , XGenericEventCookie* , XGenericEventCookie* );
typedef Status (* tXESetEventToWire(
    Display* display,
    int event_number,
    Status (*proc) ( Display* /* display */ , XEvent* /* re */ , xEvent* /* event */ ))) ( Display* , XEvent* , xEvent* );
typedef Bool (* tXESetWireToError(
    Display* display,
    int error_number,
    Bool (*proc) ( Display* /* display */ , XErrorEvent* /* he */ , xError* /* we */ ))) ( Display* , XErrorEvent* , xError* );
typedef void (* tXESetBeforeFlush(
    Display* display,
    int error_number,
    void (*proc) ( Display* /* display */ , XExtCodes* /* codes */ , _Xconst char* /* data */ , long /* len */ ))) ( Display* , XExtCodes* , _Xconst char* , long );
typedef Status t_XRegisterInternalConnection(
    Display* dpy,
    int fd,
    _XInternalConnectionProc callback,
    XPointer call_data);
typedef void t_XUnregisterInternalConnection(Display* dpy, int fd);
typedef void t_XProcessInternalConnection(
    Display* dpy,
    struct _XConnectionInfo* conn_info);
typedef char* t__XOS2RedirRoot(char* arg);
typedef int t_XTextHeight(XFontStruct* font_struct, _Xconst char* string, int count);
typedef int t_XTextHeight16(
    XFontStruct* font_struct,
    _Xconst XChar2b* string,
    int count);
typedef int t_XOpenFile(_Xconst char* path, int flags);
typedef int t_XOpenFileMode(_Xconst char* path, int flags, mode_t mode);
typedef void* t_XFopenFile(_Xconst char* path, _Xconst char* mode);
typedef int t_XAccessFile(_Xconst char* path);
typedef Status t_XEventToWire(Display* dpy, XEvent* re, xEvent* event);
typedef int t_XF86LoadQueryLocaleFont(
    Display* dpy,
    _Xconst char* name,
    XFontStruct** xfp,
    Font* fidp);
typedef void t_XProcessWindowAttributes(
    register Display* dpy,
    xChangeWindowAttributesReq* req,
    register unsigned long valuemask,
    register XSetWindowAttributes* attributes);
typedef int t_XDefaultError(Display* dpy, XErrorEvent* event);
typedef int t_XDefaultIOError(Display* dpy);
typedef void t_XSetClipRectangles(
    register Display* dpy,
    GC gc,
    int clip_x_origin,
    int clip_y_origin,
    XRectangle* rectangles,
    int n,
    int ordering);
typedef Bool t_XIsEventCookie(Display* dpy, XEvent* ev);
typedef void t_XFreeEventCookies(Display* dpy);
typedef void t_XStoreEventCookie(Display* dpy, XEvent* ev);
typedef Bool t_XFetchEventCookie(Display* dpy, XGenericEventCookie* ev);
typedef Bool t_XCopyEventCookie(
    Display* dpy,
    XGenericEventCookie* in,
    XGenericEventCookie* out);
typedef void txlocaledir(char* buf, int buf_len);

/* Function implementation declarations. */
extern t_XGetRequest *_XGetRequest_impl;
extern t_XFlushGCCache *_XFlushGCCache_impl;
extern t_XData32 *_XData32_impl;
extern t_XRead32 *_XRead32_impl;
extern t_XDeqAsyncHandler *_XDeqAsyncHandler_impl;
extern tData *Data_impl;
extern t_XError *_XError_impl;
extern t_XIOError *_XIOError_impl;
extern t_XEatData *_XEatData_impl;
extern t_XEatDataWords *_XEatDataWords_impl;
extern t_XAllocScratch *_XAllocScratch_impl;
extern t_XAllocTemp *_XAllocTemp_impl;
extern t_XFreeTemp *_XFreeTemp_impl;
extern t_XVIDtoVisual *_XVIDtoVisual_impl;
extern t_XSetLastRequestRead *_XSetLastRequestRead_impl;
extern t_XGetHostname *_XGetHostname_impl;
extern t_XScreenOfWindow *_XScreenOfWindow_impl;
extern t_XAsyncErrorHandler *_XAsyncErrorHandler_impl;
extern t_XGetAsyncReply *_XGetAsyncReply_impl;
extern t_XGetAsyncData *_XGetAsyncData_impl;
extern t_XFlush *_XFlush_impl;
extern t_XEventsQueued *_XEventsQueued_impl;
extern t_XReadEvents *_XReadEvents_impl;
extern t_XRead *_XRead_impl;
extern t_XReadPad *_XReadPad_impl;
extern t_XSend *_XSend_impl;
extern t_XReply *_XReply_impl;
extern t_XEnq *_XEnq_impl;
extern t_XDeq *_XDeq_impl;
extern t_XUnknownWireEvent *_XUnknownWireEvent_impl;
extern t_XUnknownWireEventCookie *_XUnknownWireEventCookie_impl;
extern t_XUnknownCopyEventCookie *_XUnknownCopyEventCookie_impl;
extern t_XUnknownNativeEvent *_XUnknownNativeEvent_impl;
extern t_XWireToEvent *_XWireToEvent_impl;
extern t_XDefaultWireError *_XDefaultWireError_impl;
extern t_XPollfdCacheInit *_XPollfdCacheInit_impl;
extern t_XPollfdCacheAdd *_XPollfdCacheAdd_impl;
extern t_XPollfdCacheDel *_XPollfdCacheDel_impl;
extern t_XAllocID *_XAllocID_impl;
extern t_XAllocIDs *_XAllocIDs_impl;
extern t_XFreeExtData *_XFreeExtData_impl;
extern tXESetCreateGC *XESetCreateGC_impl;
extern tXESetCopyGC *XESetCopyGC_impl;
extern tXESetFlushGC *XESetFlushGC_impl;
extern tXESetFreeGC *XESetFreeGC_impl;
extern tXESetCreateFont *XESetCreateFont_impl;
extern tXESetFreeFont *XESetFreeFont_impl;
extern tXESetCloseDisplay *XESetCloseDisplay_impl;
extern tXESetError *XESetError_impl;
extern tXESetErrorString *XESetErrorString_impl;
extern tXESetPrintErrorValues *XESetPrintErrorValues_impl;
extern tXESetWireToEvent *XESetWireToEvent_impl;
extern tXESetWireToEventCookie *XESetWireToEventCookie_impl;
extern tXESetCopyEventCookie *XESetCopyEventCookie_impl;
extern tXESetEventToWire *XESetEventToWire_impl;
extern tXESetWireToError *XESetWireToError_impl;
extern tXESetBeforeFlush *XESetBeforeFlush_impl;
extern t_XRegisterInternalConnection *_XRegisterInternalConnection_impl;
extern t_XUnregisterInternalConnection *_XUnregisterInternalConnection_impl;
extern t_XProcessInternalConnection *_XProcessInternalConnection_impl;
extern t__XOS2RedirRoot *__XOS2RedirRoot_impl;
extern t_XTextHeight *_XTextHeight_impl;
extern t_XTextHeight16 *_XTextHeight16_impl;
extern t_XOpenFile *_XOpenFile_impl;
extern t_XOpenFileMode *_XOpenFileMode_impl;
extern t_XFopenFile *_XFopenFile_impl;
extern t_XAccessFile *_XAccessFile_impl;
extern t_XEventToWire *_XEventToWire_impl;
extern t_XF86LoadQueryLocaleFont *_XF86LoadQueryLocaleFont_impl;
extern t_XProcessWindowAttributes *_XProcessWindowAttributes_impl;
extern t_XDefaultError *_XDefaultError_impl;
extern t_XDefaultIOError *_XDefaultIOError_impl;
extern t_XSetClipRectangles *_XSetClipRectangles_impl;
extern t_XIsEventCookie *_XIsEventCookie_impl;
extern t_XFreeEventCookies *_XFreeEventCookies_impl;
extern t_XStoreEventCookie *_XStoreEventCookie_impl;
extern t_XFetchEventCookie *_XFetchEventCookie_impl;
extern t_XCopyEventCookie *_XCopyEventCookie_impl;
extern txlocaledir *xlocaledir_impl;

/* Private methods, only used by wrangler. */
int __x11ew_init_xlibint(void);
void __x11ew_exit_xlibint(void);

#ifdef __cplusplus
}
#endif

#endif  /* __X11EW_XLIBINT_H__ */
