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

#ifndef __X11EW_XLIB_H__
#define __X11EW_XLIB_H__

/* Function types. */
typedef int t_Xmblen(char* str, int len);
typedef XFontStruct* tXLoadQueryFont(Display* display, _Xconst char* name);
typedef XFontStruct* tXQueryFont(Display* display, XID font_ID);
typedef XTimeCoord* tXGetMotionEvents(
    Display* display,
    Window w,
    Time start,
    Time stop,
    int* nevents_return);
typedef XModifierKeymap* tXDeleteModifiermapEntry(
    XModifierKeymap* modmap,
#if NeedWidePrototypes
    unsigned int keycode_entry,
#else
    KeyCode keycode_entry,
#endif
    int modifier);
typedef XModifierKeymap* tXGetModifierMapping(Display* display);
typedef XModifierKeymap* tXInsertModifiermapEntry(
    XModifierKeymap* modmap,
#if NeedWidePrototypes
    unsigned int keycode_entry,
#else
    KeyCode keycode_entry,
#endif
    int modifier);
typedef XModifierKeymap* tXNewModifiermap(int max_keys_per_mod);
typedef XImage* tXCreateImage(
    Display* display,
    Visual* visual,
    unsigned int depth,
    int format,
    int offset,
    char* data,
    unsigned int width,
    unsigned int height,
    int bitmap_pad,
    int bytes_per_line);
typedef Status tXInitImage(XImage* image);
typedef XImage* tXGetImage(
    Display* display,
    Drawable d,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    unsigned long plane_mask,
    int format);
typedef XImage* tXGetSubImage(
    Display* display,
    Drawable d,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    unsigned long plane_mask,
    int format,
    XImage* dest_image,
    int dest_x,
    int dest_y);
typedef Display* tXOpenDisplay(_Xconst char* display_name);
typedef void tXrmInitialize(void );
typedef char* tXFetchBytes(Display* display, int* nbytes_return);
typedef char* tXFetchBuffer(Display* display, int* nbytes_return, int buffer);
typedef char* tXGetAtomName(Display* display, Atom atom);
typedef Status tXGetAtomNames(Display* dpy, Atom* atoms, int count, char** names_return);
typedef char* tXGetDefault(
    Display* display,
    _Xconst char* program,
    _Xconst char* option);
typedef char* tXDisplayName(_Xconst char* string);
typedef char* tXKeysymToString(KeySym keysym);
typedef int (* tXSynchronize(
    Display* display,
    Bool onoff)) ( Display* /* display */ );
typedef int (* tXSetAfterFunction(
    Display* display,
    int (*procedure) ( Display* /* display */ ))) ( Display* /* display */ );
typedef Atom tXInternAtom(
    Display* display,
    _Xconst char* atom_name,
    Bool only_if_exists);
typedef Status tXInternAtoms(
    Display* dpy,
    char** names,
    int count,
    Bool onlyIfExists,
    Atom* atoms_return);
typedef Colormap tXCopyColormapAndFree(Display* display, Colormap colormap);
typedef Colormap tXCreateColormap(Display* display, Window w, Visual* visual, int alloc);
typedef Cursor tXCreatePixmapCursor(
    Display* display,
    Pixmap source,
    Pixmap mask,
    XColor* foreground_color,
    XColor* background_color,
    unsigned int x,
    unsigned int y);
typedef Cursor tXCreateGlyphCursor(
    Display* display,
    Font source_font,
    Font mask_font,
    unsigned int source_char,
    unsigned int mask_char,
    XColor _Xconst* foreground_color,
    XColor _Xconst* background_color);
typedef Cursor tXCreateFontCursor(Display* display, unsigned int shape);
typedef Font tXLoadFont(Display* display, _Xconst char* name);
typedef GC tXCreateGC(
    Display* display,
    Drawable d,
    unsigned long valuemask,
    XGCValues* values);
typedef GContext tXGContextFromGC(GC gc);
typedef void tXFlushGC(Display* display, GC gc);
typedef Pixmap tXCreatePixmap(
    Display* display,
    Drawable d,
    unsigned int width,
    unsigned int height,
    unsigned int depth);
typedef Pixmap tXCreateBitmapFromData(
    Display* display,
    Drawable d,
    _Xconst char* data,
    unsigned int width,
    unsigned int height);
typedef Pixmap tXCreatePixmapFromBitmapData(
    Display* display,
    Drawable d,
    char* data,
    unsigned int width,
    unsigned int height,
    unsigned long fg,
    unsigned long bg,
    unsigned int depth);
typedef Window tXCreateSimpleWindow(
    Display* display,
    Window parent,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    unsigned int border_width,
    unsigned long border,
    unsigned long background);
typedef Window tXGetSelectionOwner(Display* display, Atom selection);
typedef Window tXCreateWindow(
    Display* display,
    Window parent,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    unsigned int border_width,
    int depth,
    unsigned int class_,
    Visual* visual,
    unsigned long valuemask,
    XSetWindowAttributes* attributes);
typedef Colormap* tXListInstalledColormaps(
    Display* display,
    Window w,
    int* num_return);
typedef char** tXListFonts(
    Display* display,
    _Xconst char* pattern,
    int maxnames,
    int* actual_count_return);
typedef char** tXListFontsWithInfo(
    Display* display,
    _Xconst char* pattern,
    int maxnames,
    int* count_return,
    XFontStruct** info_return);
typedef char** tXGetFontPath(Display* display, int* npaths_return);
typedef char** tXListExtensions(Display* display, int* nextensions_return);
typedef Atom* tXListProperties(Display* display, Window w, int* num_prop_return);
typedef XHostAddress* tXListHosts(
    Display* display,
    int* nhosts_return,
    Bool* state_return);
typedef KeySym tXKeycodeToKeysym(
    Display* display,
#if NeedWidePrototypes
    unsigned int keycode,
#else
    KeyCode keycode,
#endif
    int index);
typedef KeySym tXLookupKeysym(XKeyEvent* key_event, int index);
typedef KeySym* tXGetKeyboardMapping(
    Display* display,
#if NeedWidePrototypes
    unsigned int first_keycode,
#else
    KeyCode first_keycode,
#endif
    int keycode_count,
    int* keysyms_per_keycode_return);
typedef KeySym tXStringToKeysym(_Xconst char* string);
typedef long tXMaxRequestSize(Display* display);
typedef long tXExtendedMaxRequestSize(Display* display);
typedef char* tXResourceManagerString(Display* display);
typedef char* tXScreenResourceString(Screen* screen);
typedef unsigned long tXDisplayMotionBufferSize(Display* display);
typedef VisualID tXVisualIDFromVisual(Visual* visual);
typedef Status tXInitThreads(void );
typedef void tXLockDisplay(Display* display);
typedef void tXUnlockDisplay(Display* display);
typedef XExtCodes* tXInitExtension(Display* display, _Xconst char* name);
typedef XExtCodes* tXAddExtension(Display* display);
typedef XExtData* tXFindOnExtensionList(XExtData** structure, int number);
typedef XExtData** tXEHeadOfExtensionList(XEDataObject object);
typedef Window tXRootWindow(Display* display, int screen_number);
typedef Window tXDefaultRootWindow(Display* display);
typedef Window tXRootWindowOfScreen(Screen* screen);
typedef Visual* tXDefaultVisual(Display* display, int screen_number);
typedef Visual* tXDefaultVisualOfScreen(Screen* screen);
typedef GC tXDefaultGC(Display* display, int screen_number);
typedef GC tXDefaultGCOfScreen(Screen* screen);
typedef unsigned long tXBlackPixel(Display* display, int screen_number);
typedef unsigned long tXWhitePixel(Display* display, int screen_number);
typedef unsigned long tXAllPlanes(void );
typedef unsigned long tXBlackPixelOfScreen(Screen* screen);
typedef unsigned long tXWhitePixelOfScreen(Screen* screen);
typedef unsigned long tXNextRequest(Display* display);
typedef unsigned long tXLastKnownRequestProcessed(Display* display);
typedef char* tXServerVendor(Display* display);
typedef char* tXDisplayString(Display* display);
typedef Colormap tXDefaultColormap(Display* display, int screen_number);
typedef Colormap tXDefaultColormapOfScreen(Screen* screen);
typedef Display* tXDisplayOfScreen(Screen* screen);
typedef Screen* tXScreenOfDisplay(Display* display, int screen_number);
typedef Screen* tXDefaultScreenOfDisplay(Display* display);
typedef long tXEventMaskOfScreen(Screen* screen);
typedef int tXScreenNumberOfScreen(Screen* screen);
typedef XErrorHandler tXSetErrorHandler(XErrorHandler handler);
typedef XIOErrorHandler tXSetIOErrorHandler(XIOErrorHandler handler);
typedef XPixmapFormatValues* tXListPixmapFormats(
    Display* display,
    int* count_return);
typedef int* tXListDepths(Display* display, int screen_number, int* count_return);
typedef Status tXReconfigureWMWindow(
    Display* display,
    Window w,
    int screen_number,
    unsigned int mask,
    XWindowChanges* changes);
typedef Status tXGetWMProtocols(
    Display* display,
    Window w,
    Atom** protocols_return,
    int* count_return);
typedef Status tXSetWMProtocols(Display* display, Window w, Atom* protocols, int count);
typedef Status tXIconifyWindow(Display* display, Window w, int screen_number);
typedef Status tXWithdrawWindow(Display* display, Window w, int screen_number);
typedef Status tXGetCommand(
    Display* display,
    Window w,
    char*** argv_return,
    int* argc_return);
typedef Status tXGetWMColormapWindows(
    Display* display,
    Window w,
    Window** windows_return,
    int* count_return);
typedef Status tXSetWMColormapWindows(
    Display* display,
    Window w,
    Window* colormap_windows,
    int count);
typedef void tXFreeStringList(char** list);
typedef int tXSetTransientForHint(Display* display, Window w, Window prop_window);
typedef int tXActivateScreenSaver(Display* display);
typedef int tXAddHost(Display* display, XHostAddress* host);
typedef int tXAddHosts(Display* display, XHostAddress* hosts, int num_hosts);
typedef int tXAddToExtensionList(struct _XExtData** structure, XExtData* ext_data);
typedef int tXAddToSaveSet(Display* display, Window w);
typedef Status tXAllocColor(
    Display* display,
    Colormap colormap,
    XColor* screen_in_out);
typedef Status tXAllocColorCells(
    Display* display,
    Colormap colormap,
    Bool contig,
    unsigned long* plane_masks_return,
    unsigned int nplanes,
    unsigned long* pixels_return,
    unsigned int npixels);
typedef Status tXAllocColorPlanes(
    Display* display,
    Colormap colormap,
    Bool contig,
    unsigned long* pixels_return,
    int ncolors,
    int nreds,
    int ngreens,
    int nblues,
    unsigned long* rmask_return,
    unsigned long* gmask_return,
    unsigned long* bmask_return);
typedef Status tXAllocNamedColor(
    Display* display,
    Colormap colormap,
    _Xconst char* color_name,
    XColor* screen_def_return,
    XColor* exact_def_return);
typedef int tXAllowEvents(Display* display, int event_mode, Time time);
typedef int tXAutoRepeatOff(Display* display);
typedef int tXAutoRepeatOn(Display* display);
typedef int tXBell(Display* display, int percent);
typedef int tXBitmapBitOrder(Display* display);
typedef int tXBitmapPad(Display* display);
typedef int tXBitmapUnit(Display* display);
typedef int tXCellsOfScreen(Screen* screen);
typedef int tXChangeActivePointerGrab(
    Display* display,
    unsigned int event_mask,
    Cursor cursor,
    Time time);
typedef int tXChangeGC(
    Display* display,
    GC gc,
    unsigned long valuemask,
    XGCValues* values);
typedef int tXChangeKeyboardControl(
    Display* display,
    unsigned long value_mask,
    XKeyboardControl* values);
typedef int tXChangeKeyboardMapping(
    Display* display,
    int first_keycode,
    int keysyms_per_keycode,
    KeySym* keysyms,
    int num_codes);
typedef int tXChangePointerControl(
    Display* display,
    Bool do_accel,
    Bool do_threshold,
    int accel_numerator,
    int accel_denominator,
    int threshold);
typedef int tXChangeProperty(
    Display* display,
    Window w,
    Atom property,
    Atom type,
    int format,
    int mode,
    _Xconst unsigned char* data,
    int nelements);
typedef int tXChangeSaveSet(Display* display, Window w, int change_mode);
typedef int tXChangeWindowAttributes(
    Display* display,
    Window w,
    unsigned long valuemask,
    XSetWindowAttributes* attributes);
typedef Bool tXCheckIfEvent(
    Display* display,
    XEvent* event_return,
    Bool (*predicate) ( Display* /* display */ , XEvent* /* event */ , XPointer /* arg */ ),
    XPointer arg);
typedef Bool tXCheckMaskEvent(
    Display* display,
    long event_mask,
    XEvent* event_return);
typedef Bool tXCheckTypedEvent(
    Display* display,
    int event_type,
    XEvent* event_return);
typedef Bool tXCheckTypedWindowEvent(
    Display* display,
    Window w,
    int event_type,
    XEvent* event_return);
typedef Bool tXCheckWindowEvent(
    Display* display,
    Window w,
    long event_mask,
    XEvent* event_return);
typedef int tXCirculateSubwindows(Display* display, Window w, int direction);
typedef int tXCirculateSubwindowsDown(Display* display, Window w);
typedef int tXCirculateSubwindowsUp(Display* display, Window w);
typedef int tXClearArea(
    Display* display,
    Window w,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    Bool exposures);
typedef int tXClearWindow(Display* display, Window w);
typedef int tXCloseDisplay(Display* display);
typedef int tXConfigureWindow(
    Display* display,
    Window w,
    unsigned int value_mask,
    XWindowChanges* values);
typedef int tXConnectionNumber(Display* display);
typedef int tXConvertSelection(
    Display* display,
    Atom selection,
    Atom target,
    Atom property,
    Window requestor,
    Time time);
typedef int tXCopyArea(
    Display* display,
    Drawable src,
    Drawable dest,
    GC gc,
    int src_x,
    int src_y,
    unsigned int width,
    unsigned int height,
    int dest_x,
    int dest_y);
typedef int tXCopyGC(Display* display, GC src, unsigned long valuemask, GC dest);
typedef int tXCopyPlane(
    Display* display,
    Drawable src,
    Drawable dest,
    GC gc,
    int src_x,
    int src_y,
    unsigned int width,
    unsigned int height,
    int dest_x,
    int dest_y,
    unsigned long plane);
typedef int tXDefaultDepth(Display* display, int screen_number);
typedef int tXDefaultDepthOfScreen(Screen* screen);
typedef int tXDefaultScreen(Display* display);
typedef int tXDefineCursor(Display* display, Window w, Cursor cursor);
typedef int tXDeleteProperty(Display* display, Window w, Atom property);
typedef int tXDestroyWindow(Display* display, Window w);
typedef int tXDestroySubwindows(Display* display, Window w);
typedef int tXDoesBackingStore(Screen* screen);
typedef Bool tXDoesSaveUnders(Screen* screen);
typedef int tXDisableAccessControl(Display* display);
typedef int tXDisplayCells(Display* display, int screen_number);
typedef int tXDisplayHeight(Display* display, int screen_number);
typedef int tXDisplayHeightMM(Display* display, int screen_number);
typedef int tXDisplayKeycodes(
    Display* display,
    int* min_keycodes_return,
    int* max_keycodes_return);
typedef int tXDisplayPlanes(Display* display, int screen_number);
typedef int tXDisplayWidth(Display* display, int screen_number);
typedef int tXDisplayWidthMM(Display* display, int screen_number);
typedef int tXDrawArc(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    int angle1,
    int angle2);
typedef int tXDrawArcs(Display* display, Drawable d, GC gc, XArc* arcs, int narcs);
typedef int tXDrawImageString(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    _Xconst char* string,
    int length);
typedef int tXDrawImageString16(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    _Xconst XChar2b* string,
    int length);
typedef int tXDrawLine(Display* display, Drawable d, GC gc, int x1, int y1, int x2, int y2);
typedef int tXDrawLines(
    Display* display,
    Drawable d,
    GC gc,
    XPoint* points,
    int npoints,
    int mode);
typedef int tXDrawPoint(Display* display, Drawable d, GC gc, int x, int y);
typedef int tXDrawPoints(
    Display* display,
    Drawable d,
    GC gc,
    XPoint* points,
    int npoints,
    int mode);
typedef int tXDrawRectangle(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    unsigned int width,
    unsigned int height);
typedef int tXDrawRectangles(
    Display* display,
    Drawable d,
    GC gc,
    XRectangle* rectangles,
    int nrectangles);
typedef int tXDrawSegments(
    Display* display,
    Drawable d,
    GC gc,
    XSegment* segments,
    int nsegments);
typedef int tXDrawString(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    _Xconst char* string,
    int length);
typedef int tXDrawString16(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    _Xconst XChar2b* string,
    int length);
typedef int tXDrawText(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    XTextItem* items,
    int nitems);
typedef int tXDrawText16(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    XTextItem16* items,
    int nitems);
typedef int tXEnableAccessControl(Display* display);
typedef int tXEventsQueued(Display* display, int mode);
typedef Status tXFetchName(Display* display, Window w, char** window_name_return);
typedef int tXFillArc(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    int angle1,
    int angle2);
typedef int tXFillArcs(Display* display, Drawable d, GC gc, XArc* arcs, int narcs);
typedef int tXFillPolygon(
    Display* display,
    Drawable d,
    GC gc,
    XPoint* points,
    int npoints,
    int shape,
    int mode);
typedef int tXFillRectangle(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    unsigned int width,
    unsigned int height);
typedef int tXFillRectangles(
    Display* display,
    Drawable d,
    GC gc,
    XRectangle* rectangles,
    int nrectangles);
typedef int tXFlush(Display* display);
typedef int tXForceScreenSaver(Display* display, int mode);
typedef int tXFree(void* data);
typedef int tXFreeColormap(Display* display, Colormap colormap);
typedef int tXFreeColors(
    Display* display,
    Colormap colormap,
    unsigned long* pixels,
    int npixels,
    unsigned long planes);
typedef int tXFreeCursor(Display* display, Cursor cursor);
typedef int tXFreeExtensionList(char** list);
typedef int tXFreeFont(Display* display, XFontStruct* font_struct);
typedef int tXFreeFontInfo(char** names, XFontStruct* free_info, int actual_count);
typedef int tXFreeFontNames(char** list);
typedef int tXFreeFontPath(char** list);
typedef int tXFreeGC(Display* display, GC gc);
typedef int tXFreeModifiermap(XModifierKeymap* modmap);
typedef int tXFreePixmap(Display* display, Pixmap pixmap);
typedef int tXGeometry(
    Display* display,
    int screen,
    _Xconst char* position,
    _Xconst char* default_position,
    unsigned int bwidth,
    unsigned int fwidth,
    unsigned int fheight,
    int xadder,
    int yadder,
    int* x_return,
    int* y_return,
    int* width_return,
    int* height_return);
typedef int tXGetErrorDatabaseText(
    Display* display,
    _Xconst char* name,
    _Xconst char* message,
    _Xconst char* default_string,
    char* buffer_return,
    int length);
typedef int tXGetErrorText(Display* display, int code, char* buffer_return, int length);
typedef Bool tXGetFontProperty(
    XFontStruct* font_struct,
    Atom atom,
    unsigned long* value_return);
typedef Status tXGetGCValues(
    Display* display,
    GC gc,
    unsigned long valuemask,
    XGCValues* values_return);
typedef Status tXGetGeometry(
    Display* display,
    Drawable d,
    Window* root_return,
    int* x_return,
    int* y_return,
    unsigned int* width_return,
    unsigned int* height_return,
    unsigned int* border_width_return,
    unsigned int* depth_return);
typedef Status tXGetIconName(Display* display, Window w, char** icon_name_return);
typedef int tXGetInputFocus(
    Display* display,
    Window* focus_return,
    int* revert_to_return);
typedef int tXGetKeyboardControl(Display* display, XKeyboardState* values_return);
typedef int tXGetPointerControl(
    Display* display,
    int* accel_numerator_return,
    int* accel_denominator_return,
    int* threshold_return);
typedef int tXGetPointerMapping(
    Display* display,
    unsigned char* map_return,
    int nmap);
typedef int tXGetScreenSaver(
    Display* display,
    int* timeout_return,
    int* interval_return,
    int* prefer_blanking_return,
    int* allow_exposures_return);
typedef Status tXGetTransientForHint(
    Display* display,
    Window w,
    Window* prop_window_return);
typedef int tXGetWindowProperty(
    Display* display,
    Window w,
    Atom property,
    long long_offset,
    long long_length,
    Bool delete_,
    Atom req_type,
    Atom* actual_type_return,
    int* actual_format_return,
    unsigned long* nitems_return,
    unsigned long* bytes_after_return,
    unsigned char** prop_return);
typedef Status tXGetWindowAttributes(
    Display* display,
    Window w,
    XWindowAttributes* window_attributes_return);
typedef int tXGrabButton(
    Display* display,
    unsigned int button,
    unsigned int modifiers,
    Window grab_window,
    Bool owner_events,
    unsigned int event_mask,
    int pointer_mode,
    int keyboard_mode,
    Window confine_to,
    Cursor cursor);
typedef int tXGrabKey(
    Display* display,
    int keycode,
    unsigned int modifiers,
    Window grab_window,
    Bool owner_events,
    int pointer_mode,
    int keyboard_mode);
typedef int tXGrabKeyboard(
    Display* display,
    Window grab_window,
    Bool owner_events,
    int pointer_mode,
    int keyboard_mode,
    Time time);
typedef int tXGrabPointer(
    Display* display,
    Window grab_window,
    Bool owner_events,
    unsigned int event_mask,
    int pointer_mode,
    int keyboard_mode,
    Window confine_to,
    Cursor cursor,
    Time time);
typedef int tXGrabServer(Display* display);
typedef int tXHeightMMOfScreen(Screen* screen);
typedef int tXHeightOfScreen(Screen* screen);
typedef int tXIfEvent(
    Display* display,
    XEvent* event_return,
    Bool (*predicate) ( Display* /* display */ , XEvent* /* event */ , XPointer /* arg */ ),
    XPointer arg);
typedef int tXImageByteOrder(Display* display);
typedef int tXInstallColormap(Display* display, Colormap colormap);
typedef KeyCode tXKeysymToKeycode(Display* display, KeySym keysym);
typedef int tXKillClient(Display* display, XID resource);
typedef Status tXLookupColor(
    Display* display,
    Colormap colormap,
    _Xconst char* color_name,
    XColor* exact_def_return,
    XColor* screen_def_return);
typedef int tXLowerWindow(Display* display, Window w);
typedef int tXMapRaised(Display* display, Window w);
typedef int tXMapSubwindows(Display* display, Window w);
typedef int tXMapWindow(Display* display, Window w);
typedef int tXMaskEvent(Display* display, long event_mask, XEvent* event_return);
typedef int tXMaxCmapsOfScreen(Screen* screen);
typedef int tXMinCmapsOfScreen(Screen* screen);
typedef int tXMoveResizeWindow(
    Display* display,
    Window w,
    int x,
    int y,
    unsigned int width,
    unsigned int height);
typedef int tXMoveWindow(Display* display, Window w, int x, int y);
typedef int tXNextEvent(Display* display, XEvent* event_return);
typedef int tXNoOp(Display* display);
typedef Status tXParseColor(
    Display* display,
    Colormap colormap,
    _Xconst char* spec,
    XColor* exact_def_return);
typedef int tXParseGeometry(
    _Xconst char* parsestring,
    int* x_return,
    int* y_return,
    unsigned int* width_return,
    unsigned int* height_return);
typedef int tXPeekEvent(Display* display, XEvent* event_return);
typedef int tXPeekIfEvent(
    Display* display,
    XEvent* event_return,
    Bool (*predicate) ( Display* /* display */ , XEvent* /* event */ , XPointer /* arg */ ),
    XPointer arg);
typedef int tXPending(Display* display);
typedef int tXPlanesOfScreen(Screen* screen);
typedef int tXProtocolRevision(Display* display);
typedef int tXProtocolVersion(Display* display);
typedef int tXPutBackEvent(Display* display, XEvent* event);
typedef int tXPutImage(
    Display* display,
    Drawable d,
    GC gc,
    XImage* image,
    int src_x,
    int src_y,
    int dest_x,
    int dest_y,
    unsigned int width,
    unsigned int height);
typedef int tXQLength(Display* display);
typedef Status tXQueryBestCursor(
    Display* display,
    Drawable d,
    unsigned int width,
    unsigned int height,
    unsigned int* width_return,
    unsigned int* height_return);
typedef Status tXQueryBestSize(
    Display* display,
    int class_,
    Drawable which_screen,
    unsigned int width,
    unsigned int height,
    unsigned int* width_return,
    unsigned int* height_return);
typedef Status tXQueryBestStipple(
    Display* display,
    Drawable which_screen,
    unsigned int width,
    unsigned int height,
    unsigned int* width_return,
    unsigned int* height_return);
typedef Status tXQueryBestTile(
    Display* display,
    Drawable which_screen,
    unsigned int width,
    unsigned int height,
    unsigned int* width_return,
    unsigned int* height_return);
typedef int tXQueryColor(Display* display, Colormap colormap, XColor* def_in_out);
typedef int tXQueryColors(
    Display* display,
    Colormap colormap,
    XColor* defs_in_out,
    int ncolors);
typedef Bool tXQueryExtension(
    Display* display,
    _Xconst char* name,
    int* major_opcode_return,
    int* first_event_return,
    int* first_error_return);
typedef int tXQueryKeymap(Display* display, char keys_return[32]);
typedef Bool tXQueryPointer(
    Display* display,
    Window w,
    Window* root_return,
    Window* child_return,
    int* root_x_return,
    int* root_y_return,
    int* win_x_return,
    int* win_y_return,
    unsigned int* mask_return);
typedef int tXQueryTextExtents(
    Display* display,
    XID font_ID,
    _Xconst char* string,
    int nchars,
    int* direction_return,
    int* font_ascent_return,
    int* font_descent_return,
    XCharStruct* overall_return);
typedef int tXQueryTextExtents16(
    Display* display,
    XID font_ID,
    _Xconst XChar2b* string,
    int nchars,
    int* direction_return,
    int* font_ascent_return,
    int* font_descent_return,
    XCharStruct* overall_return);
typedef Status tXQueryTree(
    Display* display,
    Window w,
    Window* root_return,
    Window* parent_return,
    Window** children_return,
    unsigned int* nchildren_return);
typedef int tXRaiseWindow(Display* display, Window w);
typedef int tXReadBitmapFile(
    Display* display,
    Drawable d,
    _Xconst char* filename,
    unsigned int* width_return,
    unsigned int* height_return,
    Pixmap* bitmap_return,
    int* x_hot_return,
    int* y_hot_return);
typedef int tXReadBitmapFileData(
    _Xconst char* filename,
    unsigned int* width_return,
    unsigned int* height_return,
    unsigned char** data_return,
    int* x_hot_return,
    int* y_hot_return);
typedef int tXRebindKeysym(
    Display* display,
    KeySym keysym,
    KeySym* list,
    int mod_count,
    _Xconst unsigned char* string,
    int bytes_string);
typedef int tXRecolorCursor(
    Display* display,
    Cursor cursor,
    XColor* foreground_color,
    XColor* background_color);
typedef int tXRefreshKeyboardMapping(XMappingEvent* event_map);
typedef int tXRemoveFromSaveSet(Display* display, Window w);
typedef int tXRemoveHost(Display* display, XHostAddress* host);
typedef int tXRemoveHosts(Display* display, XHostAddress* hosts, int num_hosts);
typedef int tXReparentWindow(Display* display, Window w, Window parent, int x, int y);
typedef int tXResetScreenSaver(Display* display);
typedef int tXResizeWindow(
    Display* display,
    Window w,
    unsigned int width,
    unsigned int height);
typedef int tXRestackWindows(Display* display, Window* windows, int nwindows);
typedef int tXRotateBuffers(Display* display, int rotate);
typedef int tXRotateWindowProperties(
    Display* display,
    Window w,
    Atom* properties,
    int num_prop,
    int npositions);
typedef int tXScreenCount(Display* display);
typedef int tXSelectInput(Display* display, Window w, long event_mask);
typedef Status tXSendEvent(
    Display* display,
    Window w,
    Bool propagate,
    long event_mask,
    XEvent* event_send);
typedef int tXSetAccessControl(Display* display, int mode);
typedef int tXSetArcMode(Display* display, GC gc, int arc_mode);
typedef int tXSetBackground(Display* display, GC gc, unsigned long background);
typedef int tXSetClipMask(Display* display, GC gc, Pixmap pixmap);
typedef int tXSetClipOrigin(
    Display* display,
    GC gc,
    int clip_x_origin,
    int clip_y_origin);
typedef int tXSetClipRectangles(
    Display* display,
    GC gc,
    int clip_x_origin,
    int clip_y_origin,
    XRectangle* rectangles,
    int n,
    int ordering);
typedef int tXSetCloseDownMode(Display* display, int close_mode);
typedef int tXSetCommand(Display* display, Window w, char** argv, int argc);
typedef int tXSetDashes(
    Display* display,
    GC gc,
    int dash_offset,
    _Xconst char* dash_list,
    int n);
typedef int tXSetFillRule(Display* display, GC gc, int fill_rule);
typedef int tXSetFillStyle(Display* display, GC gc, int fill_style);
typedef int tXSetFont(Display* display, GC gc, Font font);
typedef int tXSetFontPath(Display* display, char** directories, int ndirs);
typedef int tXSetForeground(Display* display, GC gc, unsigned long foreground);
typedef int tXSetFunction(Display* display, GC gc, int function);
typedef int tXSetGraphicsExposures(Display* display, GC gc, Bool graphics_exposures);
typedef int tXSetIconName(Display* display, Window w, _Xconst char* icon_name);
typedef int tXSetInputFocus(Display* display, Window focus, int revert_to, Time time);
typedef int tXSetLineAttributes(
    Display* display,
    GC gc,
    unsigned int line_width,
    int line_style,
    int cap_style,
    int join_style);
typedef int tXSetModifierMapping(Display* display, XModifierKeymap* modmap);
typedef int tXSetPlaneMask(Display* display, GC gc, unsigned long plane_mask);
typedef int tXSetPointerMapping(
    Display* display,
    _Xconst unsigned char* map,
    int nmap);
typedef int tXSetScreenSaver(
    Display* display,
    int timeout,
    int interval,
    int prefer_blanking,
    int allow_exposures);
typedef int tXSetSelectionOwner(
    Display* display,
    Atom selection,
    Window owner,
    Time time);
typedef int tXSetState(
    Display* display,
    GC gc,
    unsigned long foreground,
    unsigned long background,
    int function,
    unsigned long plane_mask);
typedef int tXSetStipple(Display* display, GC gc, Pixmap stipple);
typedef int tXSetSubwindowMode(Display* display, GC gc, int subwindow_mode);
typedef int tXSetTSOrigin(Display* display, GC gc, int ts_x_origin, int ts_y_origin);
typedef int tXSetTile(Display* display, GC gc, Pixmap tile);
typedef int tXSetWindowBackground(
    Display* display,
    Window w,
    unsigned long background_pixel);
typedef int tXSetWindowBackgroundPixmap(
    Display* display,
    Window w,
    Pixmap background_pixmap);
typedef int tXSetWindowBorder(Display* display, Window w, unsigned long border_pixel);
typedef int tXSetWindowBorderPixmap(Display* display, Window w, Pixmap border_pixmap);
typedef int tXSetWindowBorderWidth(Display* display, Window w, unsigned int width);
typedef int tXSetWindowColormap(Display* display, Window w, Colormap colormap);
typedef int tXStoreBuffer(Display* display, _Xconst char* bytes, int nbytes, int buffer);
typedef int tXStoreBytes(Display* display, _Xconst char* bytes, int nbytes);
typedef int tXStoreColor(Display* display, Colormap colormap, XColor* color);
typedef int tXStoreColors(
    Display* display,
    Colormap colormap,
    XColor* color,
    int ncolors);
typedef int tXStoreName(Display* display, Window w, _Xconst char* window_name);
typedef int tXStoreNamedColor(
    Display* display,
    Colormap colormap,
    _Xconst char* color,
    unsigned long pixel,
    int flags);
typedef int tXSync(Display* display, Bool discard);
typedef int tXTextExtents(
    XFontStruct* font_struct,
    _Xconst char* string,
    int nchars,
    int* direction_return,
    int* font_ascent_return,
    int* font_descent_return,
    XCharStruct* overall_return);
typedef int tXTextExtents16(
    XFontStruct* font_struct,
    _Xconst XChar2b* string,
    int nchars,
    int* direction_return,
    int* font_ascent_return,
    int* font_descent_return,
    XCharStruct* overall_return);
typedef int tXTextWidth(XFontStruct* font_struct, _Xconst char* string, int count);
typedef int tXTextWidth16(
    XFontStruct* font_struct,
    _Xconst XChar2b* string,
    int count);
typedef Bool tXTranslateCoordinates(
    Display* display,
    Window src_w,
    Window dest_w,
    int src_x,
    int src_y,
    int* dest_x_return,
    int* dest_y_return,
    Window* child_return);
typedef int tXUndefineCursor(Display* display, Window w);
typedef int tXUngrabButton(
    Display* display,
    unsigned int button,
    unsigned int modifiers,
    Window grab_window);
typedef int tXUngrabKey(
    Display* display,
    int keycode,
    unsigned int modifiers,
    Window grab_window);
typedef int tXUngrabKeyboard(Display* display, Time time);
typedef int tXUngrabPointer(Display* display, Time time);
typedef int tXUngrabServer(Display* display);
typedef int tXUninstallColormap(Display* display, Colormap colormap);
typedef int tXUnloadFont(Display* display, Font font);
typedef int tXUnmapSubwindows(Display* display, Window w);
typedef int tXUnmapWindow(Display* display, Window w);
typedef int tXVendorRelease(Display* display);
typedef int tXWarpPointer(
    Display* display,
    Window src_w,
    Window dest_w,
    int src_x,
    int src_y,
    unsigned int src_width,
    unsigned int src_height,
    int dest_x,
    int dest_y);
typedef int tXWidthMMOfScreen(Screen* screen);
typedef int tXWidthOfScreen(Screen* screen);
typedef int tXWindowEvent(
    Display* display,
    Window w,
    long event_mask,
    XEvent* event_return);
typedef int tXWriteBitmapFile(
    Display* display,
    _Xconst char* filename,
    Pixmap bitmap,
    unsigned int width,
    unsigned int height,
    int x_hot,
    int y_hot);
typedef Bool tXSupportsLocale(void );
typedef char* tXSetLocaleModifiers(const char* modifier_list);
typedef XOM tXOpenOM(
    Display* display,
    struct _XrmHashBucketRec* rdb,
    _Xconst char* res_name,
    _Xconst char* res_class);
typedef Status tXCloseOM(XOM om);
typedef char* tXSetOMValues(XOM om, ... );
typedef char* tXGetOMValues(XOM om, ... );
typedef Display* tXDisplayOfOM(XOM om);
typedef char* tXLocaleOfOM(XOM om);
typedef XOC tXCreateOC(XOM om, ... );
typedef void tXDestroyOC(XOC oc);
typedef XOM tXOMOfOC(XOC oc);
typedef char* tXSetOCValues(XOC oc, ... );
typedef char* tXGetOCValues(XOC oc, ... );
typedef XFontSet tXCreateFontSet(
    Display* display,
    _Xconst char* base_font_name_list,
    char*** missing_charset_list,
    int* missing_charset_count,
    char** def_string);
typedef void tXFreeFontSet(Display* display, XFontSet font_set);
typedef int tXFontsOfFontSet(
    XFontSet font_set,
    XFontStruct*** font_struct_list,
    char*** font_name_list);
typedef char* tXBaseFontNameListOfFontSet(XFontSet font_set);
typedef char* tXLocaleOfFontSet(XFontSet font_set);
typedef Bool tXContextDependentDrawing(XFontSet font_set);
typedef Bool tXDirectionalDependentDrawing(XFontSet font_set);
typedef Bool tXContextualDrawing(XFontSet font_set);
typedef XFontSetExtents* tXExtentsOfFontSet(XFontSet font_set);
typedef int tXmbTextEscapement(XFontSet font_set, _Xconst char* text, int bytes_text);
typedef int tXwcTextEscapement(
    XFontSet font_set,
    _Xconst wchar_t* text,
    int num_wchars);
typedef int tXutf8TextEscapement(
    XFontSet font_set,
    _Xconst char* text,
    int bytes_text);
typedef int tXmbTextExtents(
    XFontSet font_set,
    _Xconst char* text,
    int bytes_text,
    XRectangle* overall_ink_return,
    XRectangle* overall_logical_return);
typedef int tXwcTextExtents(
    XFontSet font_set,
    _Xconst wchar_t* text,
    int num_wchars,
    XRectangle* overall_ink_return,
    XRectangle* overall_logical_return);
typedef int tXutf8TextExtents(
    XFontSet font_set,
    _Xconst char* text,
    int bytes_text,
    XRectangle* overall_ink_return,
    XRectangle* overall_logical_return);
typedef Status tXmbTextPerCharExtents(
    XFontSet font_set,
    _Xconst char* text,
    int bytes_text,
    XRectangle* ink_extents_buffer,
    XRectangle* logical_extents_buffer,
    int buffer_size,
    int* num_chars,
    XRectangle* overall_ink_return,
    XRectangle* overall_logical_return);
typedef Status tXwcTextPerCharExtents(
    XFontSet font_set,
    _Xconst wchar_t* text,
    int num_wchars,
    XRectangle* ink_extents_buffer,
    XRectangle* logical_extents_buffer,
    int buffer_size,
    int* num_chars,
    XRectangle* overall_ink_return,
    XRectangle* overall_logical_return);
typedef Status tXutf8TextPerCharExtents(
    XFontSet font_set,
    _Xconst char* text,
    int bytes_text,
    XRectangle* ink_extents_buffer,
    XRectangle* logical_extents_buffer,
    int buffer_size,
    int* num_chars,
    XRectangle* overall_ink_return,
    XRectangle* overall_logical_return);
typedef void tXmbDrawText(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    XmbTextItem* text_items,
    int nitems);
typedef void tXwcDrawText(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    XwcTextItem* text_items,
    int nitems);
typedef void tXutf8DrawText(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    XmbTextItem* text_items,
    int nitems);
typedef void tXmbDrawString(
    Display* display,
    Drawable d,
    XFontSet font_set,
    GC gc,
    int x,
    int y,
    _Xconst char* text,
    int bytes_text);
typedef void tXwcDrawString(
    Display* display,
    Drawable d,
    XFontSet font_set,
    GC gc,
    int x,
    int y,
    _Xconst wchar_t* text,
    int num_wchars);
typedef void tXutf8DrawString(
    Display* display,
    Drawable d,
    XFontSet font_set,
    GC gc,
    int x,
    int y,
    _Xconst char* text,
    int bytes_text);
typedef void tXmbDrawImageString(
    Display* display,
    Drawable d,
    XFontSet font_set,
    GC gc,
    int x,
    int y,
    _Xconst char* text,
    int bytes_text);
typedef void tXwcDrawImageString(
    Display* display,
    Drawable d,
    XFontSet font_set,
    GC gc,
    int x,
    int y,
    _Xconst wchar_t* text,
    int num_wchars);
typedef void tXutf8DrawImageString(
    Display* display,
    Drawable d,
    XFontSet font_set,
    GC gc,
    int x,
    int y,
    _Xconst char* text,
    int bytes_text);
typedef XIM tXOpenIM(
    Display* dpy,
    struct _XrmHashBucketRec* rdb,
    char* res_name,
    char* res_class);
typedef Status tXCloseIM(XIM im);
typedef char* tXGetIMValues(XIM im, ... );
typedef char* tXSetIMValues(XIM im, ... );
typedef Display* tXDisplayOfIM(XIM im);
typedef char* tXLocaleOfIM(XIM im);
typedef XIC tXCreateIC(XIM im, ... );
typedef void tXDestroyIC(XIC ic);
typedef void tXSetICFocus(XIC ic);
typedef void tXUnsetICFocus(XIC ic);
typedef wchar_t* tXwcResetIC(XIC ic);
typedef char* tXmbResetIC(XIC ic);
typedef char* tXutf8ResetIC(XIC ic);
typedef char* tXSetICValues(XIC ic, ... );
typedef char* tXGetICValues(XIC ic, ... );
typedef XIM tXIMOfIC(XIC ic);
typedef Bool tXFilterEvent(XEvent* event, Window window);
typedef int tXmbLookupString(
    XIC ic,
    XKeyPressedEvent* event,
    char* buffer_return,
    int bytes_buffer,
    KeySym* keysym_return,
    Status* status_return);
typedef int tXwcLookupString(
    XIC ic,
    XKeyPressedEvent* event,
    wchar_t* buffer_return,
    int wchars_buffer,
    KeySym* keysym_return,
    Status* status_return);
typedef int tXutf8LookupString(
    XIC ic,
    XKeyPressedEvent* event,
    char* buffer_return,
    int bytes_buffer,
    KeySym* keysym_return,
    Status* status_return);
typedef XVaNestedList tXVaCreateNestedList(int unused, ... );
typedef Bool tXRegisterIMInstantiateCallback(
    Display* dpy,
    struct _XrmHashBucketRec* rdb,
    char* res_name,
    char* res_class,
    XIDProc callback,
    XPointer client_data);
typedef Bool tXUnregisterIMInstantiateCallback(
    Display* dpy,
    struct _XrmHashBucketRec* rdb,
    char* res_name,
    char* res_class,
    XIDProc callback,
    XPointer client_data);
typedef Status tXInternalConnectionNumbers(
    Display* dpy,
    int** fd_return,
    int* count_return);
typedef void tXProcessInternalConnection(Display* dpy, int fd);
typedef Status tXAddConnectionWatch(
    Display* dpy,
    XConnectionWatchProc callback,
    XPointer client_data);
typedef void tXRemoveConnectionWatch(
    Display* dpy,
    XConnectionWatchProc callback,
    XPointer client_data);
typedef void tXSetAuthorization(char* name, int namelen, char* data, int datalen);
typedef int t_Xmbtowc(wchar_t* wstr, char* str, int len);
typedef int t_Xwctomb(char* str, wchar_t wc);
typedef Bool tXGetEventData(Display* dpy, XGenericEventCookie* cookie);
typedef void tXFreeEventData(Display* dpy, XGenericEventCookie* cookie);

/* Function implementation declarations. */
t_Xmblen *_Xmblen_impl;
tXLoadQueryFont *XLoadQueryFont_impl;
tXQueryFont *XQueryFont_impl;
tXGetMotionEvents *XGetMotionEvents_impl;
tXDeleteModifiermapEntry *XDeleteModifiermapEntry_impl;
tXGetModifierMapping *XGetModifierMapping_impl;
tXInsertModifiermapEntry *XInsertModifiermapEntry_impl;
tXNewModifiermap *XNewModifiermap_impl;
tXCreateImage *XCreateImage_impl;
tXInitImage *XInitImage_impl;
tXGetImage *XGetImage_impl;
tXGetSubImage *XGetSubImage_impl;
tXOpenDisplay *XOpenDisplay_impl;
tXrmInitialize *XrmInitialize_impl;
tXFetchBytes *XFetchBytes_impl;
tXFetchBuffer *XFetchBuffer_impl;
tXGetAtomName *XGetAtomName_impl;
tXGetAtomNames *XGetAtomNames_impl;
tXGetDefault *XGetDefault_impl;
tXDisplayName *XDisplayName_impl;
tXKeysymToString *XKeysymToString_impl;
tXSynchronize *XSynchronize_impl;
tXSetAfterFunction *XSetAfterFunction_impl;
tXInternAtom *XInternAtom_impl;
tXInternAtoms *XInternAtoms_impl;
tXCopyColormapAndFree *XCopyColormapAndFree_impl;
tXCreateColormap *XCreateColormap_impl;
tXCreatePixmapCursor *XCreatePixmapCursor_impl;
tXCreateGlyphCursor *XCreateGlyphCursor_impl;
tXCreateFontCursor *XCreateFontCursor_impl;
tXLoadFont *XLoadFont_impl;
tXCreateGC *XCreateGC_impl;
tXGContextFromGC *XGContextFromGC_impl;
tXFlushGC *XFlushGC_impl;
tXCreatePixmap *XCreatePixmap_impl;
tXCreateBitmapFromData *XCreateBitmapFromData_impl;
tXCreatePixmapFromBitmapData *XCreatePixmapFromBitmapData_impl;
tXCreateSimpleWindow *XCreateSimpleWindow_impl;
tXGetSelectionOwner *XGetSelectionOwner_impl;
tXCreateWindow *XCreateWindow_impl;
tXListInstalledColormaps *XListInstalledColormaps_impl;
tXListFonts *XListFonts_impl;
tXListFontsWithInfo *XListFontsWithInfo_impl;
tXGetFontPath *XGetFontPath_impl;
tXListExtensions *XListExtensions_impl;
tXListProperties *XListProperties_impl;
tXListHosts *XListHosts_impl;
tXKeycodeToKeysym *XKeycodeToKeysym_impl;
tXLookupKeysym *XLookupKeysym_impl;
tXGetKeyboardMapping *XGetKeyboardMapping_impl;
tXStringToKeysym *XStringToKeysym_impl;
tXMaxRequestSize *XMaxRequestSize_impl;
tXExtendedMaxRequestSize *XExtendedMaxRequestSize_impl;
tXResourceManagerString *XResourceManagerString_impl;
tXScreenResourceString *XScreenResourceString_impl;
tXDisplayMotionBufferSize *XDisplayMotionBufferSize_impl;
tXVisualIDFromVisual *XVisualIDFromVisual_impl;
tXInitThreads *XInitThreads_impl;
tXLockDisplay *XLockDisplay_impl;
tXUnlockDisplay *XUnlockDisplay_impl;
tXInitExtension *XInitExtension_impl;
tXAddExtension *XAddExtension_impl;
tXFindOnExtensionList *XFindOnExtensionList_impl;
tXEHeadOfExtensionList *XEHeadOfExtensionList_impl;
tXRootWindow *XRootWindow_impl;
tXDefaultRootWindow *XDefaultRootWindow_impl;
tXRootWindowOfScreen *XRootWindowOfScreen_impl;
tXDefaultVisual *XDefaultVisual_impl;
tXDefaultVisualOfScreen *XDefaultVisualOfScreen_impl;
tXDefaultGC *XDefaultGC_impl;
tXDefaultGCOfScreen *XDefaultGCOfScreen_impl;
tXBlackPixel *XBlackPixel_impl;
tXWhitePixel *XWhitePixel_impl;
tXAllPlanes *XAllPlanes_impl;
tXBlackPixelOfScreen *XBlackPixelOfScreen_impl;
tXWhitePixelOfScreen *XWhitePixelOfScreen_impl;
tXNextRequest *XNextRequest_impl;
tXLastKnownRequestProcessed *XLastKnownRequestProcessed_impl;
tXServerVendor *XServerVendor_impl;
tXDisplayString *XDisplayString_impl;
tXDefaultColormap *XDefaultColormap_impl;
tXDefaultColormapOfScreen *XDefaultColormapOfScreen_impl;
tXDisplayOfScreen *XDisplayOfScreen_impl;
tXScreenOfDisplay *XScreenOfDisplay_impl;
tXDefaultScreenOfDisplay *XDefaultScreenOfDisplay_impl;
tXEventMaskOfScreen *XEventMaskOfScreen_impl;
tXScreenNumberOfScreen *XScreenNumberOfScreen_impl;
tXSetErrorHandler *XSetErrorHandler_impl;
tXSetIOErrorHandler *XSetIOErrorHandler_impl;
tXListPixmapFormats *XListPixmapFormats_impl;
tXListDepths *XListDepths_impl;
tXReconfigureWMWindow *XReconfigureWMWindow_impl;
tXGetWMProtocols *XGetWMProtocols_impl;
tXSetWMProtocols *XSetWMProtocols_impl;
tXIconifyWindow *XIconifyWindow_impl;
tXWithdrawWindow *XWithdrawWindow_impl;
tXGetCommand *XGetCommand_impl;
tXGetWMColormapWindows *XGetWMColormapWindows_impl;
tXSetWMColormapWindows *XSetWMColormapWindows_impl;
tXFreeStringList *XFreeStringList_impl;
tXSetTransientForHint *XSetTransientForHint_impl;
tXActivateScreenSaver *XActivateScreenSaver_impl;
tXAddHost *XAddHost_impl;
tXAddHosts *XAddHosts_impl;
tXAddToExtensionList *XAddToExtensionList_impl;
tXAddToSaveSet *XAddToSaveSet_impl;
tXAllocColor *XAllocColor_impl;
tXAllocColorCells *XAllocColorCells_impl;
tXAllocColorPlanes *XAllocColorPlanes_impl;
tXAllocNamedColor *XAllocNamedColor_impl;
tXAllowEvents *XAllowEvents_impl;
tXAutoRepeatOff *XAutoRepeatOff_impl;
tXAutoRepeatOn *XAutoRepeatOn_impl;
tXBell *XBell_impl;
tXBitmapBitOrder *XBitmapBitOrder_impl;
tXBitmapPad *XBitmapPad_impl;
tXBitmapUnit *XBitmapUnit_impl;
tXCellsOfScreen *XCellsOfScreen_impl;
tXChangeActivePointerGrab *XChangeActivePointerGrab_impl;
tXChangeGC *XChangeGC_impl;
tXChangeKeyboardControl *XChangeKeyboardControl_impl;
tXChangeKeyboardMapping *XChangeKeyboardMapping_impl;
tXChangePointerControl *XChangePointerControl_impl;
tXChangeProperty *XChangeProperty_impl;
tXChangeSaveSet *XChangeSaveSet_impl;
tXChangeWindowAttributes *XChangeWindowAttributes_impl;
tXCheckIfEvent *XCheckIfEvent_impl;
tXCheckMaskEvent *XCheckMaskEvent_impl;
tXCheckTypedEvent *XCheckTypedEvent_impl;
tXCheckTypedWindowEvent *XCheckTypedWindowEvent_impl;
tXCheckWindowEvent *XCheckWindowEvent_impl;
tXCirculateSubwindows *XCirculateSubwindows_impl;
tXCirculateSubwindowsDown *XCirculateSubwindowsDown_impl;
tXCirculateSubwindowsUp *XCirculateSubwindowsUp_impl;
tXClearArea *XClearArea_impl;
tXClearWindow *XClearWindow_impl;
tXCloseDisplay *XCloseDisplay_impl;
tXConfigureWindow *XConfigureWindow_impl;
tXConnectionNumber *XConnectionNumber_impl;
tXConvertSelection *XConvertSelection_impl;
tXCopyArea *XCopyArea_impl;
tXCopyGC *XCopyGC_impl;
tXCopyPlane *XCopyPlane_impl;
tXDefaultDepth *XDefaultDepth_impl;
tXDefaultDepthOfScreen *XDefaultDepthOfScreen_impl;
tXDefaultScreen *XDefaultScreen_impl;
tXDefineCursor *XDefineCursor_impl;
tXDeleteProperty *XDeleteProperty_impl;
tXDestroyWindow *XDestroyWindow_impl;
tXDestroySubwindows *XDestroySubwindows_impl;
tXDoesBackingStore *XDoesBackingStore_impl;
tXDoesSaveUnders *XDoesSaveUnders_impl;
tXDisableAccessControl *XDisableAccessControl_impl;
tXDisplayCells *XDisplayCells_impl;
tXDisplayHeight *XDisplayHeight_impl;
tXDisplayHeightMM *XDisplayHeightMM_impl;
tXDisplayKeycodes *XDisplayKeycodes_impl;
tXDisplayPlanes *XDisplayPlanes_impl;
tXDisplayWidth *XDisplayWidth_impl;
tXDisplayWidthMM *XDisplayWidthMM_impl;
tXDrawArc *XDrawArc_impl;
tXDrawArcs *XDrawArcs_impl;
tXDrawImageString *XDrawImageString_impl;
tXDrawImageString16 *XDrawImageString16_impl;
tXDrawLine *XDrawLine_impl;
tXDrawLines *XDrawLines_impl;
tXDrawPoint *XDrawPoint_impl;
tXDrawPoints *XDrawPoints_impl;
tXDrawRectangle *XDrawRectangle_impl;
tXDrawRectangles *XDrawRectangles_impl;
tXDrawSegments *XDrawSegments_impl;
tXDrawString *XDrawString_impl;
tXDrawString16 *XDrawString16_impl;
tXDrawText *XDrawText_impl;
tXDrawText16 *XDrawText16_impl;
tXEnableAccessControl *XEnableAccessControl_impl;
tXEventsQueued *XEventsQueued_impl;
tXFetchName *XFetchName_impl;
tXFillArc *XFillArc_impl;
tXFillArcs *XFillArcs_impl;
tXFillPolygon *XFillPolygon_impl;
tXFillRectangle *XFillRectangle_impl;
tXFillRectangles *XFillRectangles_impl;
tXFlush *XFlush_impl;
tXForceScreenSaver *XForceScreenSaver_impl;
tXFree *XFree_impl;
tXFreeColormap *XFreeColormap_impl;
tXFreeColors *XFreeColors_impl;
tXFreeCursor *XFreeCursor_impl;
tXFreeExtensionList *XFreeExtensionList_impl;
tXFreeFont *XFreeFont_impl;
tXFreeFontInfo *XFreeFontInfo_impl;
tXFreeFontNames *XFreeFontNames_impl;
tXFreeFontPath *XFreeFontPath_impl;
tXFreeGC *XFreeGC_impl;
tXFreeModifiermap *XFreeModifiermap_impl;
tXFreePixmap *XFreePixmap_impl;
tXGeometry *XGeometry_impl;
tXGetErrorDatabaseText *XGetErrorDatabaseText_impl;
tXGetErrorText *XGetErrorText_impl;
tXGetFontProperty *XGetFontProperty_impl;
tXGetGCValues *XGetGCValues_impl;
tXGetGeometry *XGetGeometry_impl;
tXGetIconName *XGetIconName_impl;
tXGetInputFocus *XGetInputFocus_impl;
tXGetKeyboardControl *XGetKeyboardControl_impl;
tXGetPointerControl *XGetPointerControl_impl;
tXGetPointerMapping *XGetPointerMapping_impl;
tXGetScreenSaver *XGetScreenSaver_impl;
tXGetTransientForHint *XGetTransientForHint_impl;
tXGetWindowProperty *XGetWindowProperty_impl;
tXGetWindowAttributes *XGetWindowAttributes_impl;
tXGrabButton *XGrabButton_impl;
tXGrabKey *XGrabKey_impl;
tXGrabKeyboard *XGrabKeyboard_impl;
tXGrabPointer *XGrabPointer_impl;
tXGrabServer *XGrabServer_impl;
tXHeightMMOfScreen *XHeightMMOfScreen_impl;
tXHeightOfScreen *XHeightOfScreen_impl;
tXIfEvent *XIfEvent_impl;
tXImageByteOrder *XImageByteOrder_impl;
tXInstallColormap *XInstallColormap_impl;
tXKeysymToKeycode *XKeysymToKeycode_impl;
tXKillClient *XKillClient_impl;
tXLookupColor *XLookupColor_impl;
tXLowerWindow *XLowerWindow_impl;
tXMapRaised *XMapRaised_impl;
tXMapSubwindows *XMapSubwindows_impl;
tXMapWindow *XMapWindow_impl;
tXMaskEvent *XMaskEvent_impl;
tXMaxCmapsOfScreen *XMaxCmapsOfScreen_impl;
tXMinCmapsOfScreen *XMinCmapsOfScreen_impl;
tXMoveResizeWindow *XMoveResizeWindow_impl;
tXMoveWindow *XMoveWindow_impl;
tXNextEvent *XNextEvent_impl;
tXNoOp *XNoOp_impl;
tXParseColor *XParseColor_impl;
tXParseGeometry *XParseGeometry_impl;
tXPeekEvent *XPeekEvent_impl;
tXPeekIfEvent *XPeekIfEvent_impl;
tXPending *XPending_impl;
tXPlanesOfScreen *XPlanesOfScreen_impl;
tXProtocolRevision *XProtocolRevision_impl;
tXProtocolVersion *XProtocolVersion_impl;
tXPutBackEvent *XPutBackEvent_impl;
tXPutImage *XPutImage_impl;
tXQLength *XQLength_impl;
tXQueryBestCursor *XQueryBestCursor_impl;
tXQueryBestSize *XQueryBestSize_impl;
tXQueryBestStipple *XQueryBestStipple_impl;
tXQueryBestTile *XQueryBestTile_impl;
tXQueryColor *XQueryColor_impl;
tXQueryColors *XQueryColors_impl;
tXQueryExtension *XQueryExtension_impl;
tXQueryKeymap *XQueryKeymap_impl;
tXQueryPointer *XQueryPointer_impl;
tXQueryTextExtents *XQueryTextExtents_impl;
tXQueryTextExtents16 *XQueryTextExtents16_impl;
tXQueryTree *XQueryTree_impl;
tXRaiseWindow *XRaiseWindow_impl;
tXReadBitmapFile *XReadBitmapFile_impl;
tXReadBitmapFileData *XReadBitmapFileData_impl;
tXRebindKeysym *XRebindKeysym_impl;
tXRecolorCursor *XRecolorCursor_impl;
tXRefreshKeyboardMapping *XRefreshKeyboardMapping_impl;
tXRemoveFromSaveSet *XRemoveFromSaveSet_impl;
tXRemoveHost *XRemoveHost_impl;
tXRemoveHosts *XRemoveHosts_impl;
tXReparentWindow *XReparentWindow_impl;
tXResetScreenSaver *XResetScreenSaver_impl;
tXResizeWindow *XResizeWindow_impl;
tXRestackWindows *XRestackWindows_impl;
tXRotateBuffers *XRotateBuffers_impl;
tXRotateWindowProperties *XRotateWindowProperties_impl;
tXScreenCount *XScreenCount_impl;
tXSelectInput *XSelectInput_impl;
tXSendEvent *XSendEvent_impl;
tXSetAccessControl *XSetAccessControl_impl;
tXSetArcMode *XSetArcMode_impl;
tXSetBackground *XSetBackground_impl;
tXSetClipMask *XSetClipMask_impl;
tXSetClipOrigin *XSetClipOrigin_impl;
tXSetClipRectangles *XSetClipRectangles_impl;
tXSetCloseDownMode *XSetCloseDownMode_impl;
tXSetCommand *XSetCommand_impl;
tXSetDashes *XSetDashes_impl;
tXSetFillRule *XSetFillRule_impl;
tXSetFillStyle *XSetFillStyle_impl;
tXSetFont *XSetFont_impl;
tXSetFontPath *XSetFontPath_impl;
tXSetForeground *XSetForeground_impl;
tXSetFunction *XSetFunction_impl;
tXSetGraphicsExposures *XSetGraphicsExposures_impl;
tXSetIconName *XSetIconName_impl;
tXSetInputFocus *XSetInputFocus_impl;
tXSetLineAttributes *XSetLineAttributes_impl;
tXSetModifierMapping *XSetModifierMapping_impl;
tXSetPlaneMask *XSetPlaneMask_impl;
tXSetPointerMapping *XSetPointerMapping_impl;
tXSetScreenSaver *XSetScreenSaver_impl;
tXSetSelectionOwner *XSetSelectionOwner_impl;
tXSetState *XSetState_impl;
tXSetStipple *XSetStipple_impl;
tXSetSubwindowMode *XSetSubwindowMode_impl;
tXSetTSOrigin *XSetTSOrigin_impl;
tXSetTile *XSetTile_impl;
tXSetWindowBackground *XSetWindowBackground_impl;
tXSetWindowBackgroundPixmap *XSetWindowBackgroundPixmap_impl;
tXSetWindowBorder *XSetWindowBorder_impl;
tXSetWindowBorderPixmap *XSetWindowBorderPixmap_impl;
tXSetWindowBorderWidth *XSetWindowBorderWidth_impl;
tXSetWindowColormap *XSetWindowColormap_impl;
tXStoreBuffer *XStoreBuffer_impl;
tXStoreBytes *XStoreBytes_impl;
tXStoreColor *XStoreColor_impl;
tXStoreColors *XStoreColors_impl;
tXStoreName *XStoreName_impl;
tXStoreNamedColor *XStoreNamedColor_impl;
tXSync *XSync_impl;
tXTextExtents *XTextExtents_impl;
tXTextExtents16 *XTextExtents16_impl;
tXTextWidth *XTextWidth_impl;
tXTextWidth16 *XTextWidth16_impl;
tXTranslateCoordinates *XTranslateCoordinates_impl;
tXUndefineCursor *XUndefineCursor_impl;
tXUngrabButton *XUngrabButton_impl;
tXUngrabKey *XUngrabKey_impl;
tXUngrabKeyboard *XUngrabKeyboard_impl;
tXUngrabPointer *XUngrabPointer_impl;
tXUngrabServer *XUngrabServer_impl;
tXUninstallColormap *XUninstallColormap_impl;
tXUnloadFont *XUnloadFont_impl;
tXUnmapSubwindows *XUnmapSubwindows_impl;
tXUnmapWindow *XUnmapWindow_impl;
tXVendorRelease *XVendorRelease_impl;
tXWarpPointer *XWarpPointer_impl;
tXWidthMMOfScreen *XWidthMMOfScreen_impl;
tXWidthOfScreen *XWidthOfScreen_impl;
tXWindowEvent *XWindowEvent_impl;
tXWriteBitmapFile *XWriteBitmapFile_impl;
tXSupportsLocale *XSupportsLocale_impl;
tXSetLocaleModifiers *XSetLocaleModifiers_impl;
tXOpenOM *XOpenOM_impl;
tXCloseOM *XCloseOM_impl;
tXSetOMValues *XSetOMValues_impl;
tXGetOMValues *XGetOMValues_impl;
tXDisplayOfOM *XDisplayOfOM_impl;
tXLocaleOfOM *XLocaleOfOM_impl;
tXCreateOC *XCreateOC_impl;
tXDestroyOC *XDestroyOC_impl;
tXOMOfOC *XOMOfOC_impl;
tXSetOCValues *XSetOCValues_impl;
tXGetOCValues *XGetOCValues_impl;
tXCreateFontSet *XCreateFontSet_impl;
tXFreeFontSet *XFreeFontSet_impl;
tXFontsOfFontSet *XFontsOfFontSet_impl;
tXBaseFontNameListOfFontSet *XBaseFontNameListOfFontSet_impl;
tXLocaleOfFontSet *XLocaleOfFontSet_impl;
tXContextDependentDrawing *XContextDependentDrawing_impl;
tXDirectionalDependentDrawing *XDirectionalDependentDrawing_impl;
tXContextualDrawing *XContextualDrawing_impl;
tXExtentsOfFontSet *XExtentsOfFontSet_impl;
tXmbTextEscapement *XmbTextEscapement_impl;
tXwcTextEscapement *XwcTextEscapement_impl;
tXutf8TextEscapement *Xutf8TextEscapement_impl;
tXmbTextExtents *XmbTextExtents_impl;
tXwcTextExtents *XwcTextExtents_impl;
tXutf8TextExtents *Xutf8TextExtents_impl;
tXmbTextPerCharExtents *XmbTextPerCharExtents_impl;
tXwcTextPerCharExtents *XwcTextPerCharExtents_impl;
tXutf8TextPerCharExtents *Xutf8TextPerCharExtents_impl;
tXmbDrawText *XmbDrawText_impl;
tXwcDrawText *XwcDrawText_impl;
tXutf8DrawText *Xutf8DrawText_impl;
tXmbDrawString *XmbDrawString_impl;
tXwcDrawString *XwcDrawString_impl;
tXutf8DrawString *Xutf8DrawString_impl;
tXmbDrawImageString *XmbDrawImageString_impl;
tXwcDrawImageString *XwcDrawImageString_impl;
tXutf8DrawImageString *Xutf8DrawImageString_impl;
tXOpenIM *XOpenIM_impl;
tXCloseIM *XCloseIM_impl;
tXGetIMValues *XGetIMValues_impl;
tXSetIMValues *XSetIMValues_impl;
tXDisplayOfIM *XDisplayOfIM_impl;
tXLocaleOfIM *XLocaleOfIM_impl;
tXCreateIC *XCreateIC_impl;
tXDestroyIC *XDestroyIC_impl;
tXSetICFocus *XSetICFocus_impl;
tXUnsetICFocus *XUnsetICFocus_impl;
tXwcResetIC *XwcResetIC_impl;
tXmbResetIC *XmbResetIC_impl;
tXutf8ResetIC *Xutf8ResetIC_impl;
tXSetICValues *XSetICValues_impl;
tXGetICValues *XGetICValues_impl;
tXIMOfIC *XIMOfIC_impl;
tXFilterEvent *XFilterEvent_impl;
tXmbLookupString *XmbLookupString_impl;
tXwcLookupString *XwcLookupString_impl;
tXutf8LookupString *Xutf8LookupString_impl;
tXVaCreateNestedList *XVaCreateNestedList_impl;
tXRegisterIMInstantiateCallback *XRegisterIMInstantiateCallback_impl;
tXUnregisterIMInstantiateCallback *XUnregisterIMInstantiateCallback_impl;
tXInternalConnectionNumbers *XInternalConnectionNumbers_impl;
tXProcessInternalConnection *XProcessInternalConnection_impl;
tXAddConnectionWatch *XAddConnectionWatch_impl;
tXRemoveConnectionWatch *XRemoveConnectionWatch_impl;
tXSetAuthorization *XSetAuthorization_impl;
t_Xmbtowc *_Xmbtowc_impl;
t_Xwctomb *_Xwctomb_impl;
tXGetEventData *XGetEventData_impl;
tXFreeEventData *XFreeEventData_impl;

/* Private methods, only used by wrangler. */
int __x11ew_init_xlib(void);
void __x11ew_exit_xlib(void);

#endif  /* __X11EW_XLIB_H__ */
