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

/* Function wrappers. */
int _Xmblen(char* str, int len) {
  return _Xmblen_impl(str, len);
}

XFontStruct* XLoadQueryFont(Display* display, _Xconst char* name) {
  return XLoadQueryFont_impl(display, name);
}

XFontStruct* XQueryFont(Display* display, XID font_ID) {
  return XQueryFont_impl(display, font_ID);
}

XTimeCoord* XGetMotionEvents(Display* display, Window w, Time start, Time stop, int* nevents_return) {
  return XGetMotionEvents_impl(display, w, start, stop, nevents_return);
}

XModifierKeymap* XDeleteModifiermapEntry(
    XModifierKeymap* modmap,
#if NeedWidePrototypes
    unsigned int keycode_entry,
#else
    KeyCode keycode_entry,
#endif
    int modifier) {
  return XDeleteModifiermapEntry_impl(modmap, keycode_entry, modifier);
}

XModifierKeymap* XGetModifierMapping(Display* display) {
  return XGetModifierMapping_impl(display);
}

XModifierKeymap* XInsertModifiermapEntry(
    XModifierKeymap* modmap,
#if NeedWidePrototypes
    unsigned int keycode_entry,
#else
    KeyCode keycode_entry,
#endif
    int modifier) {
  return XInsertModifiermapEntry_impl(modmap, keycode_entry, modifier);
}

XModifierKeymap* XNewModifiermap(int max_keys_per_mod) {
  return XNewModifiermap_impl(max_keys_per_mod);
}

XImage* XCreateImage(
    Display* display,
    Visual* visual,
    unsigned int depth,
    int format,
    int offset,
    char* data,
    unsigned int width,
    unsigned int height,
    int bitmap_pad,
    int bytes_per_line) {
  return XCreateImage_impl(display, visual, depth, format, offset, data, width, height, bitmap_pad, bytes_per_line);
}

Status XInitImage(XImage* image) {
  return XInitImage_impl(image);
}

XImage* XGetImage(
    Display* display,
    Drawable d,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    unsigned long plane_mask,
    int format) {
  return XGetImage_impl(display, d, x, y, width, height, plane_mask, format);
}

XImage* XGetSubImage(
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
    int dest_y) {
  return XGetSubImage_impl(display, d, x, y, width, height, plane_mask, format, dest_image, dest_x, dest_y);
}

Display* XOpenDisplay(_Xconst char* display_name) {
  return XOpenDisplay_impl(display_name);
}

void XrmInitialize(void ) {
  return XrmInitialize_impl();
}

char* XFetchBytes(Display* display, int* nbytes_return) {
  return XFetchBytes_impl(display, nbytes_return);
}

char* XFetchBuffer(Display* display, int* nbytes_return, int buffer) {
  return XFetchBuffer_impl(display, nbytes_return, buffer);
}

char* XGetAtomName(Display* display, Atom atom) {
  return XGetAtomName_impl(display, atom);
}

Status XGetAtomNames(Display* dpy, Atom* atoms, int count, char** names_return) {
  return XGetAtomNames_impl(dpy, atoms, count, names_return);
}

char* XGetDefault(Display* display, _Xconst char* program, _Xconst char* option) {
  return XGetDefault_impl(display, program, option);
}

char* XDisplayName(_Xconst char* string) {
  return XDisplayName_impl(string);
}

char* XKeysymToString(KeySym keysym) {
  return XKeysymToString_impl(keysym);
}

int (* XSynchronize(
    Display* display,
    Bool onoff)) ( Display* /* display */ ) {
  return XSynchronize_impl(display, onoff);
}

int (* XSetAfterFunction(
    Display* display,
    int (*procedure) ( Display* /* display */ ))) ( Display* /* display */ ) {
  return XSetAfterFunction_impl(display, procedure);
}

Atom XInternAtom(Display* display, _Xconst char* atom_name, Bool only_if_exists) {
  return XInternAtom_impl(display, atom_name, only_if_exists);
}

Status XInternAtoms(Display* dpy, char** names, int count, Bool onlyIfExists, Atom* atoms_return) {
  return XInternAtoms_impl(dpy, names, count, onlyIfExists, atoms_return);
}

Colormap XCopyColormapAndFree(Display* display, Colormap colormap) {
  return XCopyColormapAndFree_impl(display, colormap);
}

Colormap XCreateColormap(Display* display, Window w, Visual* visual, int alloc) {
  return XCreateColormap_impl(display, w, visual, alloc);
}

Cursor XCreatePixmapCursor(
    Display* display,
    Pixmap source,
    Pixmap mask,
    XColor* foreground_color,
    XColor* background_color,
    unsigned int x,
    unsigned int y) {
  return XCreatePixmapCursor_impl(display, source, mask, foreground_color, background_color, x, y);
}

Cursor XCreateGlyphCursor(
    Display* display,
    Font source_font,
    Font mask_font,
    unsigned int source_char,
    unsigned int mask_char,
    XColor _Xconst* foreground_color,
    XColor _Xconst* background_color) {
  return XCreateGlyphCursor_impl(display, source_font, mask_font, source_char, mask_char, foreground_color, background_color);
}

Cursor XCreateFontCursor(Display* display, unsigned int shape) {
  return XCreateFontCursor_impl(display, shape);
}

Font XLoadFont(Display* display, _Xconst char* name) {
  return XLoadFont_impl(display, name);
}

GC XCreateGC(Display* display, Drawable d, unsigned long valuemask, XGCValues* values) {
  return XCreateGC_impl(display, d, valuemask, values);
}

GContext XGContextFromGC(GC gc) {
  return XGContextFromGC_impl(gc);
}

void XFlushGC(Display* display, GC gc) {
  return XFlushGC_impl(display, gc);
}

Pixmap XCreatePixmap(Display* display, Drawable d, unsigned int width, unsigned int height, unsigned int depth) {
  return XCreatePixmap_impl(display, d, width, height, depth);
}

Pixmap XCreateBitmapFromData(Display* display, Drawable d, _Xconst char* data, unsigned int width, unsigned int height) {
  return XCreateBitmapFromData_impl(display, d, data, width, height);
}

Pixmap XCreatePixmapFromBitmapData(
    Display* display,
    Drawable d,
    char* data,
    unsigned int width,
    unsigned int height,
    unsigned long fg,
    unsigned long bg,
    unsigned int depth) {
  return XCreatePixmapFromBitmapData_impl(display, d, data, width, height, fg, bg, depth);
}

Window XCreateSimpleWindow(
    Display* display,
    Window parent,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    unsigned int border_width,
    unsigned long border,
    unsigned long background) {
  return XCreateSimpleWindow_impl(display, parent, x, y, width, height, border_width, border, background);
}

Window XGetSelectionOwner(Display* display, Atom selection) {
  return XGetSelectionOwner_impl(display, selection);
}

Window XCreateWindow(
    Display* display,
    Window parent,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    unsigned int border_width,
    int depth,
    unsigned int class,
    Visual* visual,
    unsigned long valuemask,
    XSetWindowAttributes* attributes) {
  return XCreateWindow_impl(display, parent, x, y, width, height, border_width, depth, class, visual, valuemask, attributes);
}

Colormap* XListInstalledColormaps(Display* display, Window w, int* num_return) {
  return XListInstalledColormaps_impl(display, w, num_return);
}

char** XListFonts(Display* display, _Xconst char* pattern, int maxnames, int* actual_count_return) {
  return XListFonts_impl(display, pattern, maxnames, actual_count_return);
}

char** XListFontsWithInfo(
    Display* display,
    _Xconst char* pattern,
    int maxnames,
    int* count_return,
    XFontStruct** info_return) {
  return XListFontsWithInfo_impl(display, pattern, maxnames, count_return, info_return);
}

char** XGetFontPath(Display* display, int* npaths_return) {
  return XGetFontPath_impl(display, npaths_return);
}

char** XListExtensions(Display* display, int* nextensions_return) {
  return XListExtensions_impl(display, nextensions_return);
}

Atom* XListProperties(Display* display, Window w, int* num_prop_return) {
  return XListProperties_impl(display, w, num_prop_return);
}

XHostAddress* XListHosts(Display* display, int* nhosts_return, Bool* state_return) {
  return XListHosts_impl(display, nhosts_return, state_return);
}

KeySym XKeycodeToKeysym(
    Display* display,
#if NeedWidePrototypes
    unsigned int keycode,
#else
    KeyCode keycode,
#endif
    int index) {
  return XKeycodeToKeysym_impl(display, keycode, index);
}

KeySym XLookupKeysym(XKeyEvent* key_event, int index) {
  return XLookupKeysym_impl(key_event, index);
}

KeySym* XGetKeyboardMapping(
    Display* display,
#if NeedWidePrototypes
    unsigned int first_keycode,
#else
    KeyCode first_keycode,
#endif
    int keycode_count,
    int* keysyms_per_keycode_return) {
  return XGetKeyboardMapping_impl(display, first_keycode, keycode_count, keysyms_per_keycode_return);
}

KeySym XStringToKeysym(_Xconst char* string) {
  return XStringToKeysym_impl(string);
}

long XMaxRequestSize(Display* display) {
  return XMaxRequestSize_impl(display);
}

long XExtendedMaxRequestSize(Display* display) {
  return XExtendedMaxRequestSize_impl(display);
}

char* XResourceManagerString(Display* display) {
  return XResourceManagerString_impl(display);
}

char* XScreenResourceString(Screen* screen) {
  return XScreenResourceString_impl(screen);
}

unsigned long XDisplayMotionBufferSize(Display* display) {
  return XDisplayMotionBufferSize_impl(display);
}

VisualID XVisualIDFromVisual(Visual* visual) {
  return XVisualIDFromVisual_impl(visual);
}

Status XInitThreads(void ) {
  return XInitThreads_impl();
}

void XLockDisplay(Display* display) {
  return XLockDisplay_impl(display);
}

void XUnlockDisplay(Display* display) {
  return XUnlockDisplay_impl(display);
}

XExtCodes* XInitExtension(Display* display, _Xconst char* name) {
  return XInitExtension_impl(display, name);
}

XExtCodes* XAddExtension(Display* display) {
  return XAddExtension_impl(display);
}

XExtData* XFindOnExtensionList(XExtData** structure, int number) {
  return XFindOnExtensionList_impl(structure, number);
}

XExtData** XEHeadOfExtensionList(XEDataObject object) {
  return XEHeadOfExtensionList_impl(object);
}

Window XRootWindow(Display* display, int screen_number) {
  return XRootWindow_impl(display, screen_number);
}

Window XDefaultRootWindow(Display* display) {
  return XDefaultRootWindow_impl(display);
}

Window XRootWindowOfScreen(Screen* screen) {
  return XRootWindowOfScreen_impl(screen);
}

Visual* XDefaultVisual(Display* display, int screen_number) {
  return XDefaultVisual_impl(display, screen_number);
}

Visual* XDefaultVisualOfScreen(Screen* screen) {
  return XDefaultVisualOfScreen_impl(screen);
}

GC XDefaultGC(Display* display, int screen_number) {
  return XDefaultGC_impl(display, screen_number);
}

GC XDefaultGCOfScreen(Screen* screen) {
  return XDefaultGCOfScreen_impl(screen);
}

unsigned long XBlackPixel(Display* display, int screen_number) {
  return XBlackPixel_impl(display, screen_number);
}

unsigned long XWhitePixel(Display* display, int screen_number) {
  return XWhitePixel_impl(display, screen_number);
}

unsigned long XAllPlanes(void ) {
  return XAllPlanes_impl();
}

unsigned long XBlackPixelOfScreen(Screen* screen) {
  return XBlackPixelOfScreen_impl(screen);
}

unsigned long XWhitePixelOfScreen(Screen* screen) {
  return XWhitePixelOfScreen_impl(screen);
}

unsigned long XNextRequest(Display* display) {
  return XNextRequest_impl(display);
}

unsigned long XLastKnownRequestProcessed(Display* display) {
  return XLastKnownRequestProcessed_impl(display);
}

char* XServerVendor(Display* display) {
  return XServerVendor_impl(display);
}

char* XDisplayString(Display* display) {
  return XDisplayString_impl(display);
}

Colormap XDefaultColormap(Display* display, int screen_number) {
  return XDefaultColormap_impl(display, screen_number);
}

Colormap XDefaultColormapOfScreen(Screen* screen) {
  return XDefaultColormapOfScreen_impl(screen);
}

Display* XDisplayOfScreen(Screen* screen) {
  return XDisplayOfScreen_impl(screen);
}

Screen* XScreenOfDisplay(Display* display, int screen_number) {
  return XScreenOfDisplay_impl(display, screen_number);
}

Screen* XDefaultScreenOfDisplay(Display* display) {
  return XDefaultScreenOfDisplay_impl(display);
}

long XEventMaskOfScreen(Screen* screen) {
  return XEventMaskOfScreen_impl(screen);
}

int XScreenNumberOfScreen(Screen* screen) {
  return XScreenNumberOfScreen_impl(screen);
}

XErrorHandler XSetErrorHandler(XErrorHandler handler) {
  return XSetErrorHandler_impl(handler);
}

XIOErrorHandler XSetIOErrorHandler(XIOErrorHandler handler) {
  return XSetIOErrorHandler_impl(handler);
}

XPixmapFormatValues* XListPixmapFormats(Display* display, int* count_return) {
  return XListPixmapFormats_impl(display, count_return);
}

int* XListDepths(Display* display, int screen_number, int* count_return) {
  return XListDepths_impl(display, screen_number, count_return);
}

Status XReconfigureWMWindow(Display* display, Window w, int screen_number, unsigned int mask, XWindowChanges* changes) {
  return XReconfigureWMWindow_impl(display, w, screen_number, mask, changes);
}

Status XGetWMProtocols(Display* display, Window w, Atom** protocols_return, int* count_return) {
  return XGetWMProtocols_impl(display, w, protocols_return, count_return);
}

Status XSetWMProtocols(Display* display, Window w, Atom* protocols, int count) {
  return XSetWMProtocols_impl(display, w, protocols, count);
}

Status XIconifyWindow(Display* display, Window w, int screen_number) {
  return XIconifyWindow_impl(display, w, screen_number);
}

Status XWithdrawWindow(Display* display, Window w, int screen_number) {
  return XWithdrawWindow_impl(display, w, screen_number);
}

Status XGetCommand(Display* display, Window w, char*** argv_return, int* argc_return) {
  return XGetCommand_impl(display, w, argv_return, argc_return);
}

Status XGetWMColormapWindows(Display* display, Window w, Window** windows_return, int* count_return) {
  return XGetWMColormapWindows_impl(display, w, windows_return, count_return);
}

Status XSetWMColormapWindows(Display* display, Window w, Window* colormap_windows, int count) {
  return XSetWMColormapWindows_impl(display, w, colormap_windows, count);
}

void XFreeStringList(char** list) {
  return XFreeStringList_impl(list);
}

int XSetTransientForHint(Display* display, Window w, Window prop_window) {
  return XSetTransientForHint_impl(display, w, prop_window);
}

int XActivateScreenSaver(Display* display) {
  return XActivateScreenSaver_impl(display);
}

int XAddHost(Display* display, XHostAddress* host) {
  return XAddHost_impl(display, host);
}

int XAddHosts(Display* display, XHostAddress* hosts, int num_hosts) {
  return XAddHosts_impl(display, hosts, num_hosts);
}

int XAddToExtensionList(struct _XExtData** structure, XExtData* ext_data) {
  return XAddToExtensionList_impl(structure, ext_data);
}

int XAddToSaveSet(Display* display, Window w) {
  return XAddToSaveSet_impl(display, w);
}

Status XAllocColor(Display* display, Colormap colormap, XColor* screen_in_out) {
  return XAllocColor_impl(display, colormap, screen_in_out);
}

Status XAllocColorCells(
    Display* display,
    Colormap colormap,
    Bool contig,
    unsigned long* plane_masks_return,
    unsigned int nplanes,
    unsigned long* pixels_return,
    unsigned int npixels) {
  return XAllocColorCells_impl(display, colormap, contig, plane_masks_return, nplanes, pixels_return, npixels);
}

Status XAllocColorPlanes(
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
    unsigned long* bmask_return) {
  return XAllocColorPlanes_impl(display, colormap, contig, pixels_return, ncolors, nreds, ngreens, nblues, rmask_return, gmask_return, bmask_return);
}

Status XAllocNamedColor(
    Display* display,
    Colormap colormap,
    _Xconst char* color_name,
    XColor* screen_def_return,
    XColor* exact_def_return) {
  return XAllocNamedColor_impl(display, colormap, color_name, screen_def_return, exact_def_return);
}

int XAllowEvents(Display* display, int event_mode, Time time) {
  return XAllowEvents_impl(display, event_mode, time);
}

int XAutoRepeatOff(Display* display) {
  return XAutoRepeatOff_impl(display);
}

int XAutoRepeatOn(Display* display) {
  return XAutoRepeatOn_impl(display);
}

int XBell(Display* display, int percent) {
  return XBell_impl(display, percent);
}

int XBitmapBitOrder(Display* display) {
  return XBitmapBitOrder_impl(display);
}

int XBitmapPad(Display* display) {
  return XBitmapPad_impl(display);
}

int XBitmapUnit(Display* display) {
  return XBitmapUnit_impl(display);
}

int XCellsOfScreen(Screen* screen) {
  return XCellsOfScreen_impl(screen);
}

int XChangeActivePointerGrab(Display* display, unsigned int event_mask, Cursor cursor, Time time) {
  return XChangeActivePointerGrab_impl(display, event_mask, cursor, time);
}

int XChangeGC(Display* display, GC gc, unsigned long valuemask, XGCValues* values) {
  return XChangeGC_impl(display, gc, valuemask, values);
}

int XChangeKeyboardControl(Display* display, unsigned long value_mask, XKeyboardControl* values) {
  return XChangeKeyboardControl_impl(display, value_mask, values);
}

int XChangeKeyboardMapping(
    Display* display,
    int first_keycode,
    int keysyms_per_keycode,
    KeySym* keysyms,
    int num_codes) {
  return XChangeKeyboardMapping_impl(display, first_keycode, keysyms_per_keycode, keysyms, num_codes);
}

int XChangePointerControl(
    Display* display,
    Bool do_accel,
    Bool do_threshold,
    int accel_numerator,
    int accel_denominator,
    int threshold) {
  return XChangePointerControl_impl(display, do_accel, do_threshold, accel_numerator, accel_denominator, threshold);
}

int XChangeProperty(
    Display* display,
    Window w,
    Atom property,
    Atom type,
    int format,
    int mode,
    _Xconst unsigned char* data,
    int nelements) {
  return XChangeProperty_impl(display, w, property, type, format, mode, data, nelements);
}

int XChangeSaveSet(Display* display, Window w, int change_mode) {
  return XChangeSaveSet_impl(display, w, change_mode);
}

int XChangeWindowAttributes(Display* display, Window w, unsigned long valuemask, XSetWindowAttributes* attributes) {
  return XChangeWindowAttributes_impl(display, w, valuemask, attributes);
}

Bool XCheckIfEvent(
    Display* display,
    XEvent* event_return,
    Bool (*predicate) ( Display* /* display */ , XEvent* /* event */ , XPointer /* arg */ ),
    XPointer arg) {
  return XCheckIfEvent_impl(display, event_return, predicate, arg);
}

Bool XCheckMaskEvent(Display* display, long event_mask, XEvent* event_return) {
  return XCheckMaskEvent_impl(display, event_mask, event_return);
}

Bool XCheckTypedEvent(Display* display, int event_type, XEvent* event_return) {
  return XCheckTypedEvent_impl(display, event_type, event_return);
}

Bool XCheckTypedWindowEvent(Display* display, Window w, int event_type, XEvent* event_return) {
  return XCheckTypedWindowEvent_impl(display, w, event_type, event_return);
}

Bool XCheckWindowEvent(Display* display, Window w, long event_mask, XEvent* event_return) {
  return XCheckWindowEvent_impl(display, w, event_mask, event_return);
}

int XCirculateSubwindows(Display* display, Window w, int direction) {
  return XCirculateSubwindows_impl(display, w, direction);
}

int XCirculateSubwindowsDown(Display* display, Window w) {
  return XCirculateSubwindowsDown_impl(display, w);
}

int XCirculateSubwindowsUp(Display* display, Window w) {
  return XCirculateSubwindowsUp_impl(display, w);
}

int XClearArea(
    Display* display,
    Window w,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    Bool exposures) {
  return XClearArea_impl(display, w, x, y, width, height, exposures);
}

int XClearWindow(Display* display, Window w) {
  return XClearWindow_impl(display, w);
}

int XCloseDisplay(Display* display) {
  return XCloseDisplay_impl(display);
}

int XConfigureWindow(Display* display, Window w, unsigned int value_mask, XWindowChanges* values) {
  return XConfigureWindow_impl(display, w, value_mask, values);
}

int XConnectionNumber(Display* display) {
  return XConnectionNumber_impl(display);
}

int XConvertSelection(Display* display, Atom selection, Atom target, Atom property, Window requestor, Time time) {
  return XConvertSelection_impl(display, selection, target, property, requestor, time);
}

int XCopyArea(
    Display* display,
    Drawable src,
    Drawable dest,
    GC gc,
    int src_x,
    int src_y,
    unsigned int width,
    unsigned int height,
    int dest_x,
    int dest_y) {
  return XCopyArea_impl(display, src, dest, gc, src_x, src_y, width, height, dest_x, dest_y);
}

int XCopyGC(Display* display, GC src, unsigned long valuemask, GC dest) {
  return XCopyGC_impl(display, src, valuemask, dest);
}

int XCopyPlane(
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
    unsigned long plane) {
  return XCopyPlane_impl(display, src, dest, gc, src_x, src_y, width, height, dest_x, dest_y, plane);
}

int XDefaultDepth(Display* display, int screen_number) {
  return XDefaultDepth_impl(display, screen_number);
}

int XDefaultDepthOfScreen(Screen* screen) {
  return XDefaultDepthOfScreen_impl(screen);
}

int XDefaultScreen(Display* display) {
  return XDefaultScreen_impl(display);
}

int XDefineCursor(Display* display, Window w, Cursor cursor) {
  return XDefineCursor_impl(display, w, cursor);
}

int XDeleteProperty(Display* display, Window w, Atom property) {
  return XDeleteProperty_impl(display, w, property);
}

int XDestroyWindow(Display* display, Window w) {
  return XDestroyWindow_impl(display, w);
}

int XDestroySubwindows(Display* display, Window w) {
  return XDestroySubwindows_impl(display, w);
}

int XDoesBackingStore(Screen* screen) {
  return XDoesBackingStore_impl(screen);
}

Bool XDoesSaveUnders(Screen* screen) {
  return XDoesSaveUnders_impl(screen);
}

int XDisableAccessControl(Display* display) {
  return XDisableAccessControl_impl(display);
}

int XDisplayCells(Display* display, int screen_number) {
  return XDisplayCells_impl(display, screen_number);
}

int XDisplayHeight(Display* display, int screen_number) {
  return XDisplayHeight_impl(display, screen_number);
}

int XDisplayHeightMM(Display* display, int screen_number) {
  return XDisplayHeightMM_impl(display, screen_number);
}

int XDisplayKeycodes(Display* display, int* min_keycodes_return, int* max_keycodes_return) {
  return XDisplayKeycodes_impl(display, min_keycodes_return, max_keycodes_return);
}

int XDisplayPlanes(Display* display, int screen_number) {
  return XDisplayPlanes_impl(display, screen_number);
}

int XDisplayWidth(Display* display, int screen_number) {
  return XDisplayWidth_impl(display, screen_number);
}

int XDisplayWidthMM(Display* display, int screen_number) {
  return XDisplayWidthMM_impl(display, screen_number);
}

int XDrawArc(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    int angle1,
    int angle2) {
  return XDrawArc_impl(display, d, gc, x, y, width, height, angle1, angle2);
}

int XDrawArcs(Display* display, Drawable d, GC gc, XArc* arcs, int narcs) {
  return XDrawArcs_impl(display, d, gc, arcs, narcs);
}

int XDrawImageString(Display* display, Drawable d, GC gc, int x, int y, _Xconst char* string, int length) {
  return XDrawImageString_impl(display, d, gc, x, y, string, length);
}

int XDrawImageString16(Display* display, Drawable d, GC gc, int x, int y, _Xconst XChar2b* string, int length) {
  return XDrawImageString16_impl(display, d, gc, x, y, string, length);
}

int XDrawLine(Display* display, Drawable d, GC gc, int x1, int y1, int x2, int y2) {
  return XDrawLine_impl(display, d, gc, x1, y1, x2, y2);
}

int XDrawLines(Display* display, Drawable d, GC gc, XPoint* points, int npoints, int mode) {
  return XDrawLines_impl(display, d, gc, points, npoints, mode);
}

int XDrawPoint(Display* display, Drawable d, GC gc, int x, int y) {
  return XDrawPoint_impl(display, d, gc, x, y);
}

int XDrawPoints(Display* display, Drawable d, GC gc, XPoint* points, int npoints, int mode) {
  return XDrawPoints_impl(display, d, gc, points, npoints, mode);
}

int XDrawRectangle(Display* display, Drawable d, GC gc, int x, int y, unsigned int width, unsigned int height) {
  return XDrawRectangle_impl(display, d, gc, x, y, width, height);
}

int XDrawRectangles(Display* display, Drawable d, GC gc, XRectangle* rectangles, int nrectangles) {
  return XDrawRectangles_impl(display, d, gc, rectangles, nrectangles);
}

int XDrawSegments(Display* display, Drawable d, GC gc, XSegment* segments, int nsegments) {
  return XDrawSegments_impl(display, d, gc, segments, nsegments);
}

int XDrawString(Display* display, Drawable d, GC gc, int x, int y, _Xconst char* string, int length) {
  return XDrawString_impl(display, d, gc, x, y, string, length);
}

int XDrawString16(Display* display, Drawable d, GC gc, int x, int y, _Xconst XChar2b* string, int length) {
  return XDrawString16_impl(display, d, gc, x, y, string, length);
}

int XDrawText(Display* display, Drawable d, GC gc, int x, int y, XTextItem* items, int nitems) {
  return XDrawText_impl(display, d, gc, x, y, items, nitems);
}

int XDrawText16(Display* display, Drawable d, GC gc, int x, int y, XTextItem16* items, int nitems) {
  return XDrawText16_impl(display, d, gc, x, y, items, nitems);
}

int XEnableAccessControl(Display* display) {
  return XEnableAccessControl_impl(display);
}

int XEventsQueued(Display* display, int mode) {
  return XEventsQueued_impl(display, mode);
}

Status XFetchName(Display* display, Window w, char** window_name_return) {
  return XFetchName_impl(display, w, window_name_return);
}

int XFillArc(
    Display* display,
    Drawable d,
    GC gc,
    int x,
    int y,
    unsigned int width,
    unsigned int height,
    int angle1,
    int angle2) {
  return XFillArc_impl(display, d, gc, x, y, width, height, angle1, angle2);
}

int XFillArcs(Display* display, Drawable d, GC gc, XArc* arcs, int narcs) {
  return XFillArcs_impl(display, d, gc, arcs, narcs);
}

int XFillPolygon(Display* display, Drawable d, GC gc, XPoint* points, int npoints, int shape, int mode) {
  return XFillPolygon_impl(display, d, gc, points, npoints, shape, mode);
}

int XFillRectangle(Display* display, Drawable d, GC gc, int x, int y, unsigned int width, unsigned int height) {
  return XFillRectangle_impl(display, d, gc, x, y, width, height);
}

int XFillRectangles(Display* display, Drawable d, GC gc, XRectangle* rectangles, int nrectangles) {
  return XFillRectangles_impl(display, d, gc, rectangles, nrectangles);
}

int XFlush(Display* display) {
  return XFlush_impl(display);
}

int XForceScreenSaver(Display* display, int mode) {
  return XForceScreenSaver_impl(display, mode);
}

int XFree(void* data) {
  return XFree_impl(data);
}

int XFreeColormap(Display* display, Colormap colormap) {
  return XFreeColormap_impl(display, colormap);
}

int XFreeColors(
    Display* display,
    Colormap colormap,
    unsigned long* pixels,
    int npixels,
    unsigned long planes) {
  return XFreeColors_impl(display, colormap, pixels, npixels, planes);
}

int XFreeCursor(Display* display, Cursor cursor) {
  return XFreeCursor_impl(display, cursor);
}

int XFreeExtensionList(char** list) {
  return XFreeExtensionList_impl(list);
}

int XFreeFont(Display* display, XFontStruct* font_struct) {
  return XFreeFont_impl(display, font_struct);
}

int XFreeFontInfo(char** names, XFontStruct* free_info, int actual_count) {
  return XFreeFontInfo_impl(names, free_info, actual_count);
}

int XFreeFontNames(char** list) {
  return XFreeFontNames_impl(list);
}

int XFreeFontPath(char** list) {
  return XFreeFontPath_impl(list);
}

int XFreeGC(Display* display, GC gc) {
  return XFreeGC_impl(display, gc);
}

int XFreeModifiermap(XModifierKeymap* modmap) {
  return XFreeModifiermap_impl(modmap);
}

int XFreePixmap(Display* display, Pixmap pixmap) {
  return XFreePixmap_impl(display, pixmap);
}

int XGeometry(
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
    int* height_return) {
  return XGeometry_impl(display, screen, position, default_position, bwidth, fwidth, fheight, xadder, yadder, x_return, y_return, width_return, height_return);
}

int XGetErrorDatabaseText(
    Display* display,
    _Xconst char* name,
    _Xconst char* message,
    _Xconst char* default_string,
    char* buffer_return,
    int length) {
  return XGetErrorDatabaseText_impl(display, name, message, default_string, buffer_return, length);
}

int XGetErrorText(Display* display, int code, char* buffer_return, int length) {
  return XGetErrorText_impl(display, code, buffer_return, length);
}

Bool XGetFontProperty(XFontStruct* font_struct, Atom atom, unsigned long* value_return) {
  return XGetFontProperty_impl(font_struct, atom, value_return);
}

Status XGetGCValues(Display* display, GC gc, unsigned long valuemask, XGCValues* values_return) {
  return XGetGCValues_impl(display, gc, valuemask, values_return);
}

Status XGetGeometry(
    Display* display,
    Drawable d,
    Window* root_return,
    int* x_return,
    int* y_return,
    unsigned int* width_return,
    unsigned int* height_return,
    unsigned int* border_width_return,
    unsigned int* depth_return) {
  return XGetGeometry_impl(display, d, root_return, x_return, y_return, width_return, height_return, border_width_return, depth_return);
}

Status XGetIconName(Display* display, Window w, char** icon_name_return) {
  return XGetIconName_impl(display, w, icon_name_return);
}

int XGetInputFocus(Display* display, Window* focus_return, int* revert_to_return) {
  return XGetInputFocus_impl(display, focus_return, revert_to_return);
}

int XGetKeyboardControl(Display* display, XKeyboardState* values_return) {
  return XGetKeyboardControl_impl(display, values_return);
}

int XGetPointerControl(
    Display* display,
    int* accel_numerator_return,
    int* accel_denominator_return,
    int* threshold_return) {
  return XGetPointerControl_impl(display, accel_numerator_return, accel_denominator_return, threshold_return);
}

int XGetPointerMapping(Display* display, unsigned char* map_return, int nmap) {
  return XGetPointerMapping_impl(display, map_return, nmap);
}

int XGetScreenSaver(
    Display* display,
    int* timeout_return,
    int* interval_return,
    int* prefer_blanking_return,
    int* allow_exposures_return) {
  return XGetScreenSaver_impl(display, timeout_return, interval_return, prefer_blanking_return, allow_exposures_return);
}

Status XGetTransientForHint(Display* display, Window w, Window* prop_window_return) {
  return XGetTransientForHint_impl(display, w, prop_window_return);
}

int XGetWindowProperty(
    Display* display,
    Window w,
    Atom property,
    long long_offset,
    long long_length,
    Bool delete,
    Atom req_type,
    Atom* actual_type_return,
    int* actual_format_return,
    unsigned long* nitems_return,
    unsigned long* bytes_after_return,
    unsigned char** prop_return) {
  return XGetWindowProperty_impl(display, w, property, long_offset, long_length, delete, req_type, actual_type_return, actual_format_return, nitems_return, bytes_after_return, prop_return);
}

Status XGetWindowAttributes(Display* display, Window w, XWindowAttributes* window_attributes_return) {
  return XGetWindowAttributes_impl(display, w, window_attributes_return);
}

int XGrabButton(
    Display* display,
    unsigned int button,
    unsigned int modifiers,
    Window grab_window,
    Bool owner_events,
    unsigned int event_mask,
    int pointer_mode,
    int keyboard_mode,
    Window confine_to,
    Cursor cursor) {
  return XGrabButton_impl(display, button, modifiers, grab_window, owner_events, event_mask, pointer_mode, keyboard_mode, confine_to, cursor);
}

int XGrabKey(
    Display* display,
    int keycode,
    unsigned int modifiers,
    Window grab_window,
    Bool owner_events,
    int pointer_mode,
    int keyboard_mode) {
  return XGrabKey_impl(display, keycode, modifiers, grab_window, owner_events, pointer_mode, keyboard_mode);
}

int XGrabKeyboard(
    Display* display,
    Window grab_window,
    Bool owner_events,
    int pointer_mode,
    int keyboard_mode,
    Time time) {
  return XGrabKeyboard_impl(display, grab_window, owner_events, pointer_mode, keyboard_mode, time);
}

int XGrabPointer(
    Display* display,
    Window grab_window,
    Bool owner_events,
    unsigned int event_mask,
    int pointer_mode,
    int keyboard_mode,
    Window confine_to,
    Cursor cursor,
    Time time) {
  return XGrabPointer_impl(display, grab_window, owner_events, event_mask, pointer_mode, keyboard_mode, confine_to, cursor, time);
}

int XGrabServer(Display* display) {
  return XGrabServer_impl(display);
}

int XHeightMMOfScreen(Screen* screen) {
  return XHeightMMOfScreen_impl(screen);
}

int XHeightOfScreen(Screen* screen) {
  return XHeightOfScreen_impl(screen);
}

int XIfEvent(
    Display* display,
    XEvent* event_return,
    Bool (*predicate) ( Display* /* display */ , XEvent* /* event */ , XPointer /* arg */ ),
    XPointer arg) {
  return XIfEvent_impl(display, event_return, predicate, arg);
}

int XImageByteOrder(Display* display) {
  return XImageByteOrder_impl(display);
}

int XInstallColormap(Display* display, Colormap colormap) {
  return XInstallColormap_impl(display, colormap);
}

KeyCode XKeysymToKeycode(Display* display, KeySym keysym) {
  return XKeysymToKeycode_impl(display, keysym);
}

int XKillClient(Display* display, XID resource) {
  return XKillClient_impl(display, resource);
}

Status XLookupColor(
    Display* display,
    Colormap colormap,
    _Xconst char* color_name,
    XColor* exact_def_return,
    XColor* screen_def_return) {
  return XLookupColor_impl(display, colormap, color_name, exact_def_return, screen_def_return);
}

int XLowerWindow(Display* display, Window w) {
  return XLowerWindow_impl(display, w);
}

int XMapRaised(Display* display, Window w) {
  return XMapRaised_impl(display, w);
}

int XMapSubwindows(Display* display, Window w) {
  return XMapSubwindows_impl(display, w);
}

int XMapWindow(Display* display, Window w) {
  return XMapWindow_impl(display, w);
}

int XMaskEvent(Display* display, long event_mask, XEvent* event_return) {
  return XMaskEvent_impl(display, event_mask, event_return);
}

int XMaxCmapsOfScreen(Screen* screen) {
  return XMaxCmapsOfScreen_impl(screen);
}

int XMinCmapsOfScreen(Screen* screen) {
  return XMinCmapsOfScreen_impl(screen);
}

int XMoveResizeWindow(Display* display, Window w, int x, int y, unsigned int width, unsigned int height) {
  return XMoveResizeWindow_impl(display, w, x, y, width, height);
}

int XMoveWindow(Display* display, Window w, int x, int y) {
  return XMoveWindow_impl(display, w, x, y);
}

int XNextEvent(Display* display, XEvent* event_return) {
  return XNextEvent_impl(display, event_return);
}

int XNoOp(Display* display) {
  return XNoOp_impl(display);
}

Status XParseColor(Display* display, Colormap colormap, _Xconst char* spec, XColor* exact_def_return) {
  return XParseColor_impl(display, colormap, spec, exact_def_return);
}

int XParseGeometry(
    _Xconst char* parsestring,
    int* x_return,
    int* y_return,
    unsigned int* width_return,
    unsigned int* height_return) {
  return XParseGeometry_impl(parsestring, x_return, y_return, width_return, height_return);
}

int XPeekEvent(Display* display, XEvent* event_return) {
  return XPeekEvent_impl(display, event_return);
}

int XPeekIfEvent(
    Display* display,
    XEvent* event_return,
    Bool (*predicate) ( Display* /* display */ , XEvent* /* event */ , XPointer /* arg */ ),
    XPointer arg) {
  return XPeekIfEvent_impl(display, event_return, predicate, arg);
}

int XPending(Display* display) {
  return XPending_impl(display);
}

int XPlanesOfScreen(Screen* screen) {
  return XPlanesOfScreen_impl(screen);
}

int XProtocolRevision(Display* display) {
  return XProtocolRevision_impl(display);
}

int XProtocolVersion(Display* display) {
  return XProtocolVersion_impl(display);
}

int XPutBackEvent(Display* display, XEvent* event) {
  return XPutBackEvent_impl(display, event);
}

int XPutImage(
    Display* display,
    Drawable d,
    GC gc,
    XImage* image,
    int src_x,
    int src_y,
    int dest_x,
    int dest_y,
    unsigned int width,
    unsigned int height) {
  return XPutImage_impl(display, d, gc, image, src_x, src_y, dest_x, dest_y, width, height);
}

int XQLength(Display* display) {
  return XQLength_impl(display);
}

Status XQueryBestCursor(
    Display* display,
    Drawable d,
    unsigned int width,
    unsigned int height,
    unsigned int* width_return,
    unsigned int* height_return) {
  return XQueryBestCursor_impl(display, d, width, height, width_return, height_return);
}

Status XQueryBestSize(
    Display* display,
    int class,
    Drawable which_screen,
    unsigned int width,
    unsigned int height,
    unsigned int* width_return,
    unsigned int* height_return) {
  return XQueryBestSize_impl(display, class, which_screen, width, height, width_return, height_return);
}

Status XQueryBestStipple(
    Display* display,
    Drawable which_screen,
    unsigned int width,
    unsigned int height,
    unsigned int* width_return,
    unsigned int* height_return) {
  return XQueryBestStipple_impl(display, which_screen, width, height, width_return, height_return);
}

Status XQueryBestTile(
    Display* display,
    Drawable which_screen,
    unsigned int width,
    unsigned int height,
    unsigned int* width_return,
    unsigned int* height_return) {
  return XQueryBestTile_impl(display, which_screen, width, height, width_return, height_return);
}

int XQueryColor(Display* display, Colormap colormap, XColor* def_in_out) {
  return XQueryColor_impl(display, colormap, def_in_out);
}

int XQueryColors(Display* display, Colormap colormap, XColor* defs_in_out, int ncolors) {
  return XQueryColors_impl(display, colormap, defs_in_out, ncolors);
}

Bool XQueryExtension(
    Display* display,
    _Xconst char* name,
    int* major_opcode_return,
    int* first_event_return,
    int* first_error_return) {
  return XQueryExtension_impl(display, name, major_opcode_return, first_event_return, first_error_return);
}

int XQueryKeymap(Display* display, char keys_return[32]) {
  return XQueryKeymap_impl(display, keys_return);
}

Bool XQueryPointer(
    Display* display,
    Window w,
    Window* root_return,
    Window* child_return,
    int* root_x_return,
    int* root_y_return,
    int* win_x_return,
    int* win_y_return,
    unsigned int* mask_return) {
  return XQueryPointer_impl(display, w, root_return, child_return, root_x_return, root_y_return, win_x_return, win_y_return, mask_return);
}

int XQueryTextExtents(
    Display* display,
    XID font_ID,
    _Xconst char* string,
    int nchars,
    int* direction_return,
    int* font_ascent_return,
    int* font_descent_return,
    XCharStruct* overall_return) {
  return XQueryTextExtents_impl(display, font_ID, string, nchars, direction_return, font_ascent_return, font_descent_return, overall_return);
}

int XQueryTextExtents16(
    Display* display,
    XID font_ID,
    _Xconst XChar2b* string,
    int nchars,
    int* direction_return,
    int* font_ascent_return,
    int* font_descent_return,
    XCharStruct* overall_return) {
  return XQueryTextExtents16_impl(display, font_ID, string, nchars, direction_return, font_ascent_return, font_descent_return, overall_return);
}

Status XQueryTree(
    Display* display,
    Window w,
    Window* root_return,
    Window* parent_return,
    Window** children_return,
    unsigned int* nchildren_return) {
  return XQueryTree_impl(display, w, root_return, parent_return, children_return, nchildren_return);
}

int XRaiseWindow(Display* display, Window w) {
  return XRaiseWindow_impl(display, w);
}

int XReadBitmapFile(
    Display* display,
    Drawable d,
    _Xconst char* filename,
    unsigned int* width_return,
    unsigned int* height_return,
    Pixmap* bitmap_return,
    int* x_hot_return,
    int* y_hot_return) {
  return XReadBitmapFile_impl(display, d, filename, width_return, height_return, bitmap_return, x_hot_return, y_hot_return);
}

int XReadBitmapFileData(
    _Xconst char* filename,
    unsigned int* width_return,
    unsigned int* height_return,
    unsigned char** data_return,
    int* x_hot_return,
    int* y_hot_return) {
  return XReadBitmapFileData_impl(filename, width_return, height_return, data_return, x_hot_return, y_hot_return);
}

int XRebindKeysym(
    Display* display,
    KeySym keysym,
    KeySym* list,
    int mod_count,
    _Xconst unsigned char* string,
    int bytes_string) {
  return XRebindKeysym_impl(display, keysym, list, mod_count, string, bytes_string);
}

int XRecolorCursor(Display* display, Cursor cursor, XColor* foreground_color, XColor* background_color) {
  return XRecolorCursor_impl(display, cursor, foreground_color, background_color);
}

int XRefreshKeyboardMapping(XMappingEvent* event_map) {
  return XRefreshKeyboardMapping_impl(event_map);
}

int XRemoveFromSaveSet(Display* display, Window w) {
  return XRemoveFromSaveSet_impl(display, w);
}

int XRemoveHost(Display* display, XHostAddress* host) {
  return XRemoveHost_impl(display, host);
}

int XRemoveHosts(Display* display, XHostAddress* hosts, int num_hosts) {
  return XRemoveHosts_impl(display, hosts, num_hosts);
}

int XReparentWindow(Display* display, Window w, Window parent, int x, int y) {
  return XReparentWindow_impl(display, w, parent, x, y);
}

int XResetScreenSaver(Display* display) {
  return XResetScreenSaver_impl(display);
}

int XResizeWindow(Display* display, Window w, unsigned int width, unsigned int height) {
  return XResizeWindow_impl(display, w, width, height);
}

int XRestackWindows(Display* display, Window* windows, int nwindows) {
  return XRestackWindows_impl(display, windows, nwindows);
}

int XRotateBuffers(Display* display, int rotate) {
  return XRotateBuffers_impl(display, rotate);
}

int XRotateWindowProperties(Display* display, Window w, Atom* properties, int num_prop, int npositions) {
  return XRotateWindowProperties_impl(display, w, properties, num_prop, npositions);
}

int XScreenCount(Display* display) {
  return XScreenCount_impl(display);
}

int XSelectInput(Display* display, Window w, long event_mask) {
  return XSelectInput_impl(display, w, event_mask);
}

Status XSendEvent(Display* display, Window w, Bool propagate, long event_mask, XEvent* event_send) {
  return XSendEvent_impl(display, w, propagate, event_mask, event_send);
}

int XSetAccessControl(Display* display, int mode) {
  return XSetAccessControl_impl(display, mode);
}

int XSetArcMode(Display* display, GC gc, int arc_mode) {
  return XSetArcMode_impl(display, gc, arc_mode);
}

int XSetBackground(Display* display, GC gc, unsigned long background) {
  return XSetBackground_impl(display, gc, background);
}

int XSetClipMask(Display* display, GC gc, Pixmap pixmap) {
  return XSetClipMask_impl(display, gc, pixmap);
}

int XSetClipOrigin(Display* display, GC gc, int clip_x_origin, int clip_y_origin) {
  return XSetClipOrigin_impl(display, gc, clip_x_origin, clip_y_origin);
}

int XSetClipRectangles(
    Display* display,
    GC gc,
    int clip_x_origin,
    int clip_y_origin,
    XRectangle* rectangles,
    int n,
    int ordering) {
  return XSetClipRectangles_impl(display, gc, clip_x_origin, clip_y_origin, rectangles, n, ordering);
}

int XSetCloseDownMode(Display* display, int close_mode) {
  return XSetCloseDownMode_impl(display, close_mode);
}

int XSetCommand(Display* display, Window w, char** argv, int argc) {
  return XSetCommand_impl(display, w, argv, argc);
}

int XSetDashes(Display* display, GC gc, int dash_offset, _Xconst char* dash_list, int n) {
  return XSetDashes_impl(display, gc, dash_offset, dash_list, n);
}

int XSetFillRule(Display* display, GC gc, int fill_rule) {
  return XSetFillRule_impl(display, gc, fill_rule);
}

int XSetFillStyle(Display* display, GC gc, int fill_style) {
  return XSetFillStyle_impl(display, gc, fill_style);
}

int XSetFont(Display* display, GC gc, Font font) {
  return XSetFont_impl(display, gc, font);
}

int XSetFontPath(Display* display, char** directories, int ndirs) {
  return XSetFontPath_impl(display, directories, ndirs);
}

int XSetForeground(Display* display, GC gc, unsigned long foreground) {
  return XSetForeground_impl(display, gc, foreground);
}

int XSetFunction(Display* display, GC gc, int function) {
  return XSetFunction_impl(display, gc, function);
}

int XSetGraphicsExposures(Display* display, GC gc, Bool graphics_exposures) {
  return XSetGraphicsExposures_impl(display, gc, graphics_exposures);
}

int XSetIconName(Display* display, Window w, _Xconst char* icon_name) {
  return XSetIconName_impl(display, w, icon_name);
}

int XSetInputFocus(Display* display, Window focus, int revert_to, Time time) {
  return XSetInputFocus_impl(display, focus, revert_to, time);
}

int XSetLineAttributes(
    Display* display,
    GC gc,
    unsigned int line_width,
    int line_style,
    int cap_style,
    int join_style) {
  return XSetLineAttributes_impl(display, gc, line_width, line_style, cap_style, join_style);
}

int XSetModifierMapping(Display* display, XModifierKeymap* modmap) {
  return XSetModifierMapping_impl(display, modmap);
}

int XSetPlaneMask(Display* display, GC gc, unsigned long plane_mask) {
  return XSetPlaneMask_impl(display, gc, plane_mask);
}

int XSetPointerMapping(Display* display, _Xconst unsigned char* map, int nmap) {
  return XSetPointerMapping_impl(display, map, nmap);
}

int XSetScreenSaver(Display* display, int timeout, int interval, int prefer_blanking, int allow_exposures) {
  return XSetScreenSaver_impl(display, timeout, interval, prefer_blanking, allow_exposures);
}

int XSetSelectionOwner(Display* display, Atom selection, Window owner, Time time) {
  return XSetSelectionOwner_impl(display, selection, owner, time);
}

int XSetState(
    Display* display,
    GC gc,
    unsigned long foreground,
    unsigned long background,
    int function,
    unsigned long plane_mask) {
  return XSetState_impl(display, gc, foreground, background, function, plane_mask);
}

int XSetStipple(Display* display, GC gc, Pixmap stipple) {
  return XSetStipple_impl(display, gc, stipple);
}

int XSetSubwindowMode(Display* display, GC gc, int subwindow_mode) {
  return XSetSubwindowMode_impl(display, gc, subwindow_mode);
}

int XSetTSOrigin(Display* display, GC gc, int ts_x_origin, int ts_y_origin) {
  return XSetTSOrigin_impl(display, gc, ts_x_origin, ts_y_origin);
}

int XSetTile(Display* display, GC gc, Pixmap tile) {
  return XSetTile_impl(display, gc, tile);
}

int XSetWindowBackground(Display* display, Window w, unsigned long background_pixel) {
  return XSetWindowBackground_impl(display, w, background_pixel);
}

int XSetWindowBackgroundPixmap(Display* display, Window w, Pixmap background_pixmap) {
  return XSetWindowBackgroundPixmap_impl(display, w, background_pixmap);
}

int XSetWindowBorder(Display* display, Window w, unsigned long border_pixel) {
  return XSetWindowBorder_impl(display, w, border_pixel);
}

int XSetWindowBorderPixmap(Display* display, Window w, Pixmap border_pixmap) {
  return XSetWindowBorderPixmap_impl(display, w, border_pixmap);
}

int XSetWindowBorderWidth(Display* display, Window w, unsigned int width) {
  return XSetWindowBorderWidth_impl(display, w, width);
}

int XSetWindowColormap(Display* display, Window w, Colormap colormap) {
  return XSetWindowColormap_impl(display, w, colormap);
}

int XStoreBuffer(Display* display, _Xconst char* bytes, int nbytes, int buffer) {
  return XStoreBuffer_impl(display, bytes, nbytes, buffer);
}

int XStoreBytes(Display* display, _Xconst char* bytes, int nbytes) {
  return XStoreBytes_impl(display, bytes, nbytes);
}

int XStoreColor(Display* display, Colormap colormap, XColor* color) {
  return XStoreColor_impl(display, colormap, color);
}

int XStoreColors(Display* display, Colormap colormap, XColor* color, int ncolors) {
  return XStoreColors_impl(display, colormap, color, ncolors);
}

int XStoreName(Display* display, Window w, _Xconst char* window_name) {
  return XStoreName_impl(display, w, window_name);
}

int XStoreNamedColor(Display* display, Colormap colormap, _Xconst char* color, unsigned long pixel, int flags) {
  return XStoreNamedColor_impl(display, colormap, color, pixel, flags);
}

int XSync(Display* display, Bool discard) {
  return XSync_impl(display, discard);
}

int XTextExtents(
    XFontStruct* font_struct,
    _Xconst char* string,
    int nchars,
    int* direction_return,
    int* font_ascent_return,
    int* font_descent_return,
    XCharStruct* overall_return) {
  return XTextExtents_impl(font_struct, string, nchars, direction_return, font_ascent_return, font_descent_return, overall_return);
}

int XTextExtents16(
    XFontStruct* font_struct,
    _Xconst XChar2b* string,
    int nchars,
    int* direction_return,
    int* font_ascent_return,
    int* font_descent_return,
    XCharStruct* overall_return) {
  return XTextExtents16_impl(font_struct, string, nchars, direction_return, font_ascent_return, font_descent_return, overall_return);
}

int XTextWidth(XFontStruct* font_struct, _Xconst char* string, int count) {
  return XTextWidth_impl(font_struct, string, count);
}

int XTextWidth16(XFontStruct* font_struct, _Xconst XChar2b* string, int count) {
  return XTextWidth16_impl(font_struct, string, count);
}

Bool XTranslateCoordinates(
    Display* display,
    Window src_w,
    Window dest_w,
    int src_x,
    int src_y,
    int* dest_x_return,
    int* dest_y_return,
    Window* child_return) {
  return XTranslateCoordinates_impl(display, src_w, dest_w, src_x, src_y, dest_x_return, dest_y_return, child_return);
}

int XUndefineCursor(Display* display, Window w) {
  return XUndefineCursor_impl(display, w);
}

int XUngrabButton(Display* display, unsigned int button, unsigned int modifiers, Window grab_window) {
  return XUngrabButton_impl(display, button, modifiers, grab_window);
}

int XUngrabKey(Display* display, int keycode, unsigned int modifiers, Window grab_window) {
  return XUngrabKey_impl(display, keycode, modifiers, grab_window);
}

int XUngrabKeyboard(Display* display, Time time) {
  return XUngrabKeyboard_impl(display, time);
}

int XUngrabPointer(Display* display, Time time) {
  return XUngrabPointer_impl(display, time);
}

int XUngrabServer(Display* display) {
  return XUngrabServer_impl(display);
}

int XUninstallColormap(Display* display, Colormap colormap) {
  return XUninstallColormap_impl(display, colormap);
}

int XUnloadFont(Display* display, Font font) {
  return XUnloadFont_impl(display, font);
}

int XUnmapSubwindows(Display* display, Window w) {
  return XUnmapSubwindows_impl(display, w);
}

int XUnmapWindow(Display* display, Window w) {
  return XUnmapWindow_impl(display, w);
}

int XVendorRelease(Display* display) {
  return XVendorRelease_impl(display);
}

int XWarpPointer(
    Display* display,
    Window src_w,
    Window dest_w,
    int src_x,
    int src_y,
    unsigned int src_width,
    unsigned int src_height,
    int dest_x,
    int dest_y) {
  return XWarpPointer_impl(display, src_w, dest_w, src_x, src_y, src_width, src_height, dest_x, dest_y);
}

int XWidthMMOfScreen(Screen* screen) {
  return XWidthMMOfScreen_impl(screen);
}

int XWidthOfScreen(Screen* screen) {
  return XWidthOfScreen_impl(screen);
}

int XWindowEvent(Display* display, Window w, long event_mask, XEvent* event_return) {
  return XWindowEvent_impl(display, w, event_mask, event_return);
}

int XWriteBitmapFile(
    Display* display,
    _Xconst char* filename,
    Pixmap bitmap,
    unsigned int width,
    unsigned int height,
    int x_hot,
    int y_hot) {
  return XWriteBitmapFile_impl(display, filename, bitmap, width, height, x_hot, y_hot);
}

Bool XSupportsLocale(void ) {
  return XSupportsLocale_impl();
}

char* XSetLocaleModifiers(const char* modifier_list) {
  return XSetLocaleModifiers_impl(modifier_list);
}

XOM XOpenOM(
    Display* display,
    struct _XrmHashBucketRec* rdb,
    _Xconst char* res_name,
    _Xconst char* res_class) {
  return XOpenOM_impl(display, rdb, res_name, res_class);
}

Status XCloseOM(XOM om) {
  return XCloseOM_impl(om);
}

Display* XDisplayOfOM(XOM om) {
  return XDisplayOfOM_impl(om);
}

char* XLocaleOfOM(XOM om) {
  return XLocaleOfOM_impl(om);
}

void XDestroyOC(XOC oc) {
  return XDestroyOC_impl(oc);
}

XOM XOMOfOC(XOC oc) {
  return XOMOfOC_impl(oc);
}

XFontSet XCreateFontSet(
    Display* display,
    _Xconst char* base_font_name_list,
    char*** missing_charset_list,
    int* missing_charset_count,
    char** def_string) {
  return XCreateFontSet_impl(display, base_font_name_list, missing_charset_list, missing_charset_count, def_string);
}

void XFreeFontSet(Display* display, XFontSet font_set) {
  return XFreeFontSet_impl(display, font_set);
}

int XFontsOfFontSet(XFontSet font_set, XFontStruct*** font_struct_list, char*** font_name_list) {
  return XFontsOfFontSet_impl(font_set, font_struct_list, font_name_list);
}

char* XBaseFontNameListOfFontSet(XFontSet font_set) {
  return XBaseFontNameListOfFontSet_impl(font_set);
}

char* XLocaleOfFontSet(XFontSet font_set) {
  return XLocaleOfFontSet_impl(font_set);
}

Bool XContextDependentDrawing(XFontSet font_set) {
  return XContextDependentDrawing_impl(font_set);
}

Bool XDirectionalDependentDrawing(XFontSet font_set) {
  return XDirectionalDependentDrawing_impl(font_set);
}

Bool XContextualDrawing(XFontSet font_set) {
  return XContextualDrawing_impl(font_set);
}

XFontSetExtents* XExtentsOfFontSet(XFontSet font_set) {
  return XExtentsOfFontSet_impl(font_set);
}

int XmbTextEscapement(XFontSet font_set, _Xconst char* text, int bytes_text) {
  return XmbTextEscapement_impl(font_set, text, bytes_text);
}

int XwcTextEscapement(XFontSet font_set, _Xconst wchar_t* text, int num_wchars) {
  return XwcTextEscapement_impl(font_set, text, num_wchars);
}

int Xutf8TextEscapement(XFontSet font_set, _Xconst char* text, int bytes_text) {
  return Xutf8TextEscapement_impl(font_set, text, bytes_text);
}

int XmbTextExtents(
    XFontSet font_set,
    _Xconst char* text,
    int bytes_text,
    XRectangle* overall_ink_return,
    XRectangle* overall_logical_return) {
  return XmbTextExtents_impl(font_set, text, bytes_text, overall_ink_return, overall_logical_return);
}

int XwcTextExtents(
    XFontSet font_set,
    _Xconst wchar_t* text,
    int num_wchars,
    XRectangle* overall_ink_return,
    XRectangle* overall_logical_return) {
  return XwcTextExtents_impl(font_set, text, num_wchars, overall_ink_return, overall_logical_return);
}

int Xutf8TextExtents(
    XFontSet font_set,
    _Xconst char* text,
    int bytes_text,
    XRectangle* overall_ink_return,
    XRectangle* overall_logical_return) {
  return Xutf8TextExtents_impl(font_set, text, bytes_text, overall_ink_return, overall_logical_return);
}

Status XmbTextPerCharExtents(
    XFontSet font_set,
    _Xconst char* text,
    int bytes_text,
    XRectangle* ink_extents_buffer,
    XRectangle* logical_extents_buffer,
    int buffer_size,
    int* num_chars,
    XRectangle* overall_ink_return,
    XRectangle* overall_logical_return) {
  return XmbTextPerCharExtents_impl(font_set, text, bytes_text, ink_extents_buffer, logical_extents_buffer, buffer_size, num_chars, overall_ink_return, overall_logical_return);
}

Status XwcTextPerCharExtents(
    XFontSet font_set,
    _Xconst wchar_t* text,
    int num_wchars,
    XRectangle* ink_extents_buffer,
    XRectangle* logical_extents_buffer,
    int buffer_size,
    int* num_chars,
    XRectangle* overall_ink_return,
    XRectangle* overall_logical_return) {
  return XwcTextPerCharExtents_impl(font_set, text, num_wchars, ink_extents_buffer, logical_extents_buffer, buffer_size, num_chars, overall_ink_return, overall_logical_return);
}

Status Xutf8TextPerCharExtents(
    XFontSet font_set,
    _Xconst char* text,
    int bytes_text,
    XRectangle* ink_extents_buffer,
    XRectangle* logical_extents_buffer,
    int buffer_size,
    int* num_chars,
    XRectangle* overall_ink_return,
    XRectangle* overall_logical_return) {
  return Xutf8TextPerCharExtents_impl(font_set, text, bytes_text, ink_extents_buffer, logical_extents_buffer, buffer_size, num_chars, overall_ink_return, overall_logical_return);
}

void XmbDrawText(Display* display, Drawable d, GC gc, int x, int y, XmbTextItem* text_items, int nitems) {
  return XmbDrawText_impl(display, d, gc, x, y, text_items, nitems);
}

void XwcDrawText(Display* display, Drawable d, GC gc, int x, int y, XwcTextItem* text_items, int nitems) {
  return XwcDrawText_impl(display, d, gc, x, y, text_items, nitems);
}

void Xutf8DrawText(Display* display, Drawable d, GC gc, int x, int y, XmbTextItem* text_items, int nitems) {
  return Xutf8DrawText_impl(display, d, gc, x, y, text_items, nitems);
}

void XmbDrawString(
    Display* display,
    Drawable d,
    XFontSet font_set,
    GC gc,
    int x,
    int y,
    _Xconst char* text,
    int bytes_text) {
  return XmbDrawString_impl(display, d, font_set, gc, x, y, text, bytes_text);
}

void XwcDrawString(
    Display* display,
    Drawable d,
    XFontSet font_set,
    GC gc,
    int x,
    int y,
    _Xconst wchar_t* text,
    int num_wchars) {
  return XwcDrawString_impl(display, d, font_set, gc, x, y, text, num_wchars);
}

void Xutf8DrawString(
    Display* display,
    Drawable d,
    XFontSet font_set,
    GC gc,
    int x,
    int y,
    _Xconst char* text,
    int bytes_text) {
  return Xutf8DrawString_impl(display, d, font_set, gc, x, y, text, bytes_text);
}

void XmbDrawImageString(
    Display* display,
    Drawable d,
    XFontSet font_set,
    GC gc,
    int x,
    int y,
    _Xconst char* text,
    int bytes_text) {
  return XmbDrawImageString_impl(display, d, font_set, gc, x, y, text, bytes_text);
}

void XwcDrawImageString(
    Display* display,
    Drawable d,
    XFontSet font_set,
    GC gc,
    int x,
    int y,
    _Xconst wchar_t* text,
    int num_wchars) {
  return XwcDrawImageString_impl(display, d, font_set, gc, x, y, text, num_wchars);
}

void Xutf8DrawImageString(
    Display* display,
    Drawable d,
    XFontSet font_set,
    GC gc,
    int x,
    int y,
    _Xconst char* text,
    int bytes_text) {
  return Xutf8DrawImageString_impl(display, d, font_set, gc, x, y, text, bytes_text);
}

XIM XOpenIM(Display* dpy, struct _XrmHashBucketRec* rdb, char* res_name, char* res_class) {
  return XOpenIM_impl(dpy, rdb, res_name, res_class);
}

Status XCloseIM(XIM im) {
  return XCloseIM_impl(im);
}

Display* XDisplayOfIM(XIM im) {
  return XDisplayOfIM_impl(im);
}

char* XLocaleOfIM(XIM im) {
  return XLocaleOfIM_impl(im);
}

void XDestroyIC(XIC ic) {
  return XDestroyIC_impl(ic);
}

void XSetICFocus(XIC ic) {
  return XSetICFocus_impl(ic);
}

void XUnsetICFocus(XIC ic) {
  return XUnsetICFocus_impl(ic);
}

wchar_t* XwcResetIC(XIC ic) {
  return XwcResetIC_impl(ic);
}

char* XmbResetIC(XIC ic) {
  return XmbResetIC_impl(ic);
}

char* Xutf8ResetIC(XIC ic) {
  return Xutf8ResetIC_impl(ic);
}

XIM XIMOfIC(XIC ic) {
  return XIMOfIC_impl(ic);
}

Bool XFilterEvent(XEvent* event, Window window) {
  return XFilterEvent_impl(event, window);
}

int XmbLookupString(
    XIC ic,
    XKeyPressedEvent* event,
    char* buffer_return,
    int bytes_buffer,
    KeySym* keysym_return,
    Status* status_return) {
  return XmbLookupString_impl(ic, event, buffer_return, bytes_buffer, keysym_return, status_return);
}

int XwcLookupString(
    XIC ic,
    XKeyPressedEvent* event,
    wchar_t* buffer_return,
    int wchars_buffer,
    KeySym* keysym_return,
    Status* status_return) {
  return XwcLookupString_impl(ic, event, buffer_return, wchars_buffer, keysym_return, status_return);
}

int Xutf8LookupString(
    XIC ic,
    XKeyPressedEvent* event,
    char* buffer_return,
    int bytes_buffer,
    KeySym* keysym_return,
    Status* status_return) {
  return Xutf8LookupString_impl(ic, event, buffer_return, bytes_buffer, keysym_return, status_return);
}

Bool XRegisterIMInstantiateCallback(
    Display* dpy,
    struct _XrmHashBucketRec* rdb,
    char* res_name,
    char* res_class,
    XIDProc callback,
    XPointer client_data) {
  return XRegisterIMInstantiateCallback_impl(dpy, rdb, res_name, res_class, callback, client_data);
}

Bool XUnregisterIMInstantiateCallback(
    Display* dpy,
    struct _XrmHashBucketRec* rdb,
    char* res_name,
    char* res_class,
    XIDProc callback,
    XPointer client_data) {
  return XUnregisterIMInstantiateCallback_impl(dpy, rdb, res_name, res_class, callback, client_data);
}

Status XInternalConnectionNumbers(Display* dpy, int** fd_return, int* count_return) {
  return XInternalConnectionNumbers_impl(dpy, fd_return, count_return);
}

void XProcessInternalConnection(Display* dpy, int fd) {
  return XProcessInternalConnection_impl(dpy, fd);
}

Status XAddConnectionWatch(Display* dpy, XConnectionWatchProc callback, XPointer client_data) {
  return XAddConnectionWatch_impl(dpy, callback, client_data);
}

void XRemoveConnectionWatch(Display* dpy, XConnectionWatchProc callback, XPointer client_data) {
  return XRemoveConnectionWatch_impl(dpy, callback, client_data);
}

void XSetAuthorization(char* name, int namelen, char* data, int datalen) {
  return XSetAuthorization_impl(name, namelen, data, datalen);
}

int _Xmbtowc(wchar_t* wstr, char* str, int len) {
  return _Xmbtowc_impl(wstr, str, len);
}

int _Xwctomb(char* str, wchar_t wc) {
  return _Xwctomb_impl(str, wc);
}

Bool XGetEventData(Display* dpy, XGenericEventCookie* cookie) {
  return XGetEventData_impl(dpy, cookie);
}

void XFreeEventData(Display* dpy, XGenericEventCookie* cookie) {
  return XFreeEventData_impl(dpy, cookie);
}


int __x11ew_init_xlib(void) {
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
  _LIBRARY_FIND(library, _Xmblen);
  _LIBRARY_FIND(library, XLoadQueryFont);
  _LIBRARY_FIND(library, XQueryFont);
  _LIBRARY_FIND(library, XGetMotionEvents);
  _LIBRARY_FIND(library, XDeleteModifiermapEntry);
  _LIBRARY_FIND(library, XGetModifierMapping);
  _LIBRARY_FIND(library, XInsertModifiermapEntry);
  _LIBRARY_FIND(library, XNewModifiermap);
  _LIBRARY_FIND(library, XCreateImage);
  _LIBRARY_FIND(library, XInitImage);
  _LIBRARY_FIND(library, XGetImage);
  _LIBRARY_FIND(library, XGetSubImage);
  _LIBRARY_FIND(library, XOpenDisplay);
  _LIBRARY_FIND(library, XrmInitialize);
  _LIBRARY_FIND(library, XFetchBytes);
  _LIBRARY_FIND(library, XFetchBuffer);
  _LIBRARY_FIND(library, XGetAtomName);
  _LIBRARY_FIND(library, XGetAtomNames);
  _LIBRARY_FIND(library, XGetDefault);
  _LIBRARY_FIND(library, XDisplayName);
  _LIBRARY_FIND(library, XKeysymToString);
  _LIBRARY_FIND(library, XSynchronize);
  _LIBRARY_FIND(library, XSetAfterFunction);
  _LIBRARY_FIND(library, XInternAtom);
  _LIBRARY_FIND(library, XInternAtoms);
  _LIBRARY_FIND(library, XCopyColormapAndFree);
  _LIBRARY_FIND(library, XCreateColormap);
  _LIBRARY_FIND(library, XCreatePixmapCursor);
  _LIBRARY_FIND(library, XCreateGlyphCursor);
  _LIBRARY_FIND(library, XCreateFontCursor);
  _LIBRARY_FIND(library, XLoadFont);
  _LIBRARY_FIND(library, XCreateGC);
  _LIBRARY_FIND(library, XGContextFromGC);
  _LIBRARY_FIND(library, XFlushGC);
  _LIBRARY_FIND(library, XCreatePixmap);
  _LIBRARY_FIND(library, XCreateBitmapFromData);
  _LIBRARY_FIND(library, XCreatePixmapFromBitmapData);
  _LIBRARY_FIND(library, XCreateSimpleWindow);
  _LIBRARY_FIND(library, XGetSelectionOwner);
  _LIBRARY_FIND(library, XCreateWindow);
  _LIBRARY_FIND(library, XListInstalledColormaps);
  _LIBRARY_FIND(library, XListFonts);
  _LIBRARY_FIND(library, XListFontsWithInfo);
  _LIBRARY_FIND(library, XGetFontPath);
  _LIBRARY_FIND(library, XListExtensions);
  _LIBRARY_FIND(library, XListProperties);
  _LIBRARY_FIND(library, XListHosts);
  _LIBRARY_FIND(library, XKeycodeToKeysym);
  _LIBRARY_FIND(library, XLookupKeysym);
  _LIBRARY_FIND(library, XGetKeyboardMapping);
  _LIBRARY_FIND(library, XStringToKeysym);
  _LIBRARY_FIND(library, XMaxRequestSize);
  _LIBRARY_FIND(library, XExtendedMaxRequestSize);
  _LIBRARY_FIND(library, XResourceManagerString);
  _LIBRARY_FIND(library, XScreenResourceString);
  _LIBRARY_FIND(library, XDisplayMotionBufferSize);
  _LIBRARY_FIND(library, XVisualIDFromVisual);
  _LIBRARY_FIND(library, XInitThreads);
  _LIBRARY_FIND(library, XLockDisplay);
  _LIBRARY_FIND(library, XUnlockDisplay);
  _LIBRARY_FIND(library, XInitExtension);
  _LIBRARY_FIND(library, XAddExtension);
  _LIBRARY_FIND(library, XFindOnExtensionList);
  _LIBRARY_FIND(library, XEHeadOfExtensionList);
  _LIBRARY_FIND(library, XRootWindow);
  _LIBRARY_FIND(library, XDefaultRootWindow);
  _LIBRARY_FIND(library, XRootWindowOfScreen);
  _LIBRARY_FIND(library, XDefaultVisual);
  _LIBRARY_FIND(library, XDefaultVisualOfScreen);
  _LIBRARY_FIND(library, XDefaultGC);
  _LIBRARY_FIND(library, XDefaultGCOfScreen);
  _LIBRARY_FIND(library, XBlackPixel);
  _LIBRARY_FIND(library, XWhitePixel);
  _LIBRARY_FIND(library, XAllPlanes);
  _LIBRARY_FIND(library, XBlackPixelOfScreen);
  _LIBRARY_FIND(library, XWhitePixelOfScreen);
  _LIBRARY_FIND(library, XNextRequest);
  _LIBRARY_FIND(library, XLastKnownRequestProcessed);
  _LIBRARY_FIND(library, XServerVendor);
  _LIBRARY_FIND(library, XDisplayString);
  _LIBRARY_FIND(library, XDefaultColormap);
  _LIBRARY_FIND(library, XDefaultColormapOfScreen);
  _LIBRARY_FIND(library, XDisplayOfScreen);
  _LIBRARY_FIND(library, XScreenOfDisplay);
  _LIBRARY_FIND(library, XDefaultScreenOfDisplay);
  _LIBRARY_FIND(library, XEventMaskOfScreen);
  _LIBRARY_FIND(library, XScreenNumberOfScreen);
  _LIBRARY_FIND(library, XSetErrorHandler);
  _LIBRARY_FIND(library, XSetIOErrorHandler);
  _LIBRARY_FIND(library, XListPixmapFormats);
  _LIBRARY_FIND(library, XListDepths);
  _LIBRARY_FIND(library, XReconfigureWMWindow);
  _LIBRARY_FIND(library, XGetWMProtocols);
  _LIBRARY_FIND(library, XSetWMProtocols);
  _LIBRARY_FIND(library, XIconifyWindow);
  _LIBRARY_FIND(library, XWithdrawWindow);
  _LIBRARY_FIND(library, XGetCommand);
  _LIBRARY_FIND(library, XGetWMColormapWindows);
  _LIBRARY_FIND(library, XSetWMColormapWindows);
  _LIBRARY_FIND(library, XFreeStringList);
  _LIBRARY_FIND(library, XSetTransientForHint);
  _LIBRARY_FIND(library, XActivateScreenSaver);
  _LIBRARY_FIND(library, XAddHost);
  _LIBRARY_FIND(library, XAddHosts);
  _LIBRARY_FIND(library, XAddToExtensionList);
  _LIBRARY_FIND(library, XAddToSaveSet);
  _LIBRARY_FIND(library, XAllocColor);
  _LIBRARY_FIND(library, XAllocColorCells);
  _LIBRARY_FIND(library, XAllocColorPlanes);
  _LIBRARY_FIND(library, XAllocNamedColor);
  _LIBRARY_FIND(library, XAllowEvents);
  _LIBRARY_FIND(library, XAutoRepeatOff);
  _LIBRARY_FIND(library, XAutoRepeatOn);
  _LIBRARY_FIND(library, XBell);
  _LIBRARY_FIND(library, XBitmapBitOrder);
  _LIBRARY_FIND(library, XBitmapPad);
  _LIBRARY_FIND(library, XBitmapUnit);
  _LIBRARY_FIND(library, XCellsOfScreen);
  _LIBRARY_FIND(library, XChangeActivePointerGrab);
  _LIBRARY_FIND(library, XChangeGC);
  _LIBRARY_FIND(library, XChangeKeyboardControl);
  _LIBRARY_FIND(library, XChangeKeyboardMapping);
  _LIBRARY_FIND(library, XChangePointerControl);
  _LIBRARY_FIND(library, XChangeProperty);
  _LIBRARY_FIND(library, XChangeSaveSet);
  _LIBRARY_FIND(library, XChangeWindowAttributes);
  _LIBRARY_FIND(library, XCheckIfEvent);
  _LIBRARY_FIND(library, XCheckMaskEvent);
  _LIBRARY_FIND(library, XCheckTypedEvent);
  _LIBRARY_FIND(library, XCheckTypedWindowEvent);
  _LIBRARY_FIND(library, XCheckWindowEvent);
  _LIBRARY_FIND(library, XCirculateSubwindows);
  _LIBRARY_FIND(library, XCirculateSubwindowsDown);
  _LIBRARY_FIND(library, XCirculateSubwindowsUp);
  _LIBRARY_FIND(library, XClearArea);
  _LIBRARY_FIND(library, XClearWindow);
  _LIBRARY_FIND(library, XCloseDisplay);
  _LIBRARY_FIND(library, XConfigureWindow);
  _LIBRARY_FIND(library, XConnectionNumber);
  _LIBRARY_FIND(library, XConvertSelection);
  _LIBRARY_FIND(library, XCopyArea);
  _LIBRARY_FIND(library, XCopyGC);
  _LIBRARY_FIND(library, XCopyPlane);
  _LIBRARY_FIND(library, XDefaultDepth);
  _LIBRARY_FIND(library, XDefaultDepthOfScreen);
  _LIBRARY_FIND(library, XDefaultScreen);
  _LIBRARY_FIND(library, XDefineCursor);
  _LIBRARY_FIND(library, XDeleteProperty);
  _LIBRARY_FIND(library, XDestroyWindow);
  _LIBRARY_FIND(library, XDestroySubwindows);
  _LIBRARY_FIND(library, XDoesBackingStore);
  _LIBRARY_FIND(library, XDoesSaveUnders);
  _LIBRARY_FIND(library, XDisableAccessControl);
  _LIBRARY_FIND(library, XDisplayCells);
  _LIBRARY_FIND(library, XDisplayHeight);
  _LIBRARY_FIND(library, XDisplayHeightMM);
  _LIBRARY_FIND(library, XDisplayKeycodes);
  _LIBRARY_FIND(library, XDisplayPlanes);
  _LIBRARY_FIND(library, XDisplayWidth);
  _LIBRARY_FIND(library, XDisplayWidthMM);
  _LIBRARY_FIND(library, XDrawArc);
  _LIBRARY_FIND(library, XDrawArcs);
  _LIBRARY_FIND(library, XDrawImageString);
  _LIBRARY_FIND(library, XDrawImageString16);
  _LIBRARY_FIND(library, XDrawLine);
  _LIBRARY_FIND(library, XDrawLines);
  _LIBRARY_FIND(library, XDrawPoint);
  _LIBRARY_FIND(library, XDrawPoints);
  _LIBRARY_FIND(library, XDrawRectangle);
  _LIBRARY_FIND(library, XDrawRectangles);
  _LIBRARY_FIND(library, XDrawSegments);
  _LIBRARY_FIND(library, XDrawString);
  _LIBRARY_FIND(library, XDrawString16);
  _LIBRARY_FIND(library, XDrawText);
  _LIBRARY_FIND(library, XDrawText16);
  _LIBRARY_FIND(library, XEnableAccessControl);
  _LIBRARY_FIND(library, XEventsQueued);
  _LIBRARY_FIND(library, XFetchName);
  _LIBRARY_FIND(library, XFillArc);
  _LIBRARY_FIND(library, XFillArcs);
  _LIBRARY_FIND(library, XFillPolygon);
  _LIBRARY_FIND(library, XFillRectangle);
  _LIBRARY_FIND(library, XFillRectangles);
  _LIBRARY_FIND(library, XFlush);
  _LIBRARY_FIND(library, XForceScreenSaver);
  _LIBRARY_FIND(library, XFree);
  _LIBRARY_FIND(library, XFreeColormap);
  _LIBRARY_FIND(library, XFreeColors);
  _LIBRARY_FIND(library, XFreeCursor);
  _LIBRARY_FIND(library, XFreeExtensionList);
  _LIBRARY_FIND(library, XFreeFont);
  _LIBRARY_FIND(library, XFreeFontInfo);
  _LIBRARY_FIND(library, XFreeFontNames);
  _LIBRARY_FIND(library, XFreeFontPath);
  _LIBRARY_FIND(library, XFreeGC);
  _LIBRARY_FIND(library, XFreeModifiermap);
  _LIBRARY_FIND(library, XFreePixmap);
  _LIBRARY_FIND(library, XGeometry);
  _LIBRARY_FIND(library, XGetErrorDatabaseText);
  _LIBRARY_FIND(library, XGetErrorText);
  _LIBRARY_FIND(library, XGetFontProperty);
  _LIBRARY_FIND(library, XGetGCValues);
  _LIBRARY_FIND(library, XGetGeometry);
  _LIBRARY_FIND(library, XGetIconName);
  _LIBRARY_FIND(library, XGetInputFocus);
  _LIBRARY_FIND(library, XGetKeyboardControl);
  _LIBRARY_FIND(library, XGetPointerControl);
  _LIBRARY_FIND(library, XGetPointerMapping);
  _LIBRARY_FIND(library, XGetScreenSaver);
  _LIBRARY_FIND(library, XGetTransientForHint);
  _LIBRARY_FIND(library, XGetWindowProperty);
  _LIBRARY_FIND(library, XGetWindowAttributes);
  _LIBRARY_FIND(library, XGrabButton);
  _LIBRARY_FIND(library, XGrabKey);
  _LIBRARY_FIND(library, XGrabKeyboard);
  _LIBRARY_FIND(library, XGrabPointer);
  _LIBRARY_FIND(library, XGrabServer);
  _LIBRARY_FIND(library, XHeightMMOfScreen);
  _LIBRARY_FIND(library, XHeightOfScreen);
  _LIBRARY_FIND(library, XIfEvent);
  _LIBRARY_FIND(library, XImageByteOrder);
  _LIBRARY_FIND(library, XInstallColormap);
  _LIBRARY_FIND(library, XKeysymToKeycode);
  _LIBRARY_FIND(library, XKillClient);
  _LIBRARY_FIND(library, XLookupColor);
  _LIBRARY_FIND(library, XLowerWindow);
  _LIBRARY_FIND(library, XMapRaised);
  _LIBRARY_FIND(library, XMapSubwindows);
  _LIBRARY_FIND(library, XMapWindow);
  _LIBRARY_FIND(library, XMaskEvent);
  _LIBRARY_FIND(library, XMaxCmapsOfScreen);
  _LIBRARY_FIND(library, XMinCmapsOfScreen);
  _LIBRARY_FIND(library, XMoveResizeWindow);
  _LIBRARY_FIND(library, XMoveWindow);
  _LIBRARY_FIND(library, XNextEvent);
  _LIBRARY_FIND(library, XNoOp);
  _LIBRARY_FIND(library, XParseColor);
  _LIBRARY_FIND(library, XParseGeometry);
  _LIBRARY_FIND(library, XPeekEvent);
  _LIBRARY_FIND(library, XPeekIfEvent);
  _LIBRARY_FIND(library, XPending);
  _LIBRARY_FIND(library, XPlanesOfScreen);
  _LIBRARY_FIND(library, XProtocolRevision);
  _LIBRARY_FIND(library, XProtocolVersion);
  _LIBRARY_FIND(library, XPutBackEvent);
  _LIBRARY_FIND(library, XPutImage);
  _LIBRARY_FIND(library, XQLength);
  _LIBRARY_FIND(library, XQueryBestCursor);
  _LIBRARY_FIND(library, XQueryBestSize);
  _LIBRARY_FIND(library, XQueryBestStipple);
  _LIBRARY_FIND(library, XQueryBestTile);
  _LIBRARY_FIND(library, XQueryColor);
  _LIBRARY_FIND(library, XQueryColors);
  _LIBRARY_FIND(library, XQueryExtension);
  _LIBRARY_FIND(library, XQueryKeymap);
  _LIBRARY_FIND(library, XQueryPointer);
  _LIBRARY_FIND(library, XQueryTextExtents);
  _LIBRARY_FIND(library, XQueryTextExtents16);
  _LIBRARY_FIND(library, XQueryTree);
  _LIBRARY_FIND(library, XRaiseWindow);
  _LIBRARY_FIND(library, XReadBitmapFile);
  _LIBRARY_FIND(library, XReadBitmapFileData);
  _LIBRARY_FIND(library, XRebindKeysym);
  _LIBRARY_FIND(library, XRecolorCursor);
  _LIBRARY_FIND(library, XRefreshKeyboardMapping);
  _LIBRARY_FIND(library, XRemoveFromSaveSet);
  _LIBRARY_FIND(library, XRemoveHost);
  _LIBRARY_FIND(library, XRemoveHosts);
  _LIBRARY_FIND(library, XReparentWindow);
  _LIBRARY_FIND(library, XResetScreenSaver);
  _LIBRARY_FIND(library, XResizeWindow);
  _LIBRARY_FIND(library, XRestackWindows);
  _LIBRARY_FIND(library, XRotateBuffers);
  _LIBRARY_FIND(library, XRotateWindowProperties);
  _LIBRARY_FIND(library, XScreenCount);
  _LIBRARY_FIND(library, XSelectInput);
  _LIBRARY_FIND(library, XSendEvent);
  _LIBRARY_FIND(library, XSetAccessControl);
  _LIBRARY_FIND(library, XSetArcMode);
  _LIBRARY_FIND(library, XSetBackground);
  _LIBRARY_FIND(library, XSetClipMask);
  _LIBRARY_FIND(library, XSetClipOrigin);
  _LIBRARY_FIND(library, XSetClipRectangles);
  _LIBRARY_FIND(library, XSetCloseDownMode);
  _LIBRARY_FIND(library, XSetCommand);
  _LIBRARY_FIND(library, XSetDashes);
  _LIBRARY_FIND(library, XSetFillRule);
  _LIBRARY_FIND(library, XSetFillStyle);
  _LIBRARY_FIND(library, XSetFont);
  _LIBRARY_FIND(library, XSetFontPath);
  _LIBRARY_FIND(library, XSetForeground);
  _LIBRARY_FIND(library, XSetFunction);
  _LIBRARY_FIND(library, XSetGraphicsExposures);
  _LIBRARY_FIND(library, XSetIconName);
  _LIBRARY_FIND(library, XSetInputFocus);
  _LIBRARY_FIND(library, XSetLineAttributes);
  _LIBRARY_FIND(library, XSetModifierMapping);
  _LIBRARY_FIND(library, XSetPlaneMask);
  _LIBRARY_FIND(library, XSetPointerMapping);
  _LIBRARY_FIND(library, XSetScreenSaver);
  _LIBRARY_FIND(library, XSetSelectionOwner);
  _LIBRARY_FIND(library, XSetState);
  _LIBRARY_FIND(library, XSetStipple);
  _LIBRARY_FIND(library, XSetSubwindowMode);
  _LIBRARY_FIND(library, XSetTSOrigin);
  _LIBRARY_FIND(library, XSetTile);
  _LIBRARY_FIND(library, XSetWindowBackground);
  _LIBRARY_FIND(library, XSetWindowBackgroundPixmap);
  _LIBRARY_FIND(library, XSetWindowBorder);
  _LIBRARY_FIND(library, XSetWindowBorderPixmap);
  _LIBRARY_FIND(library, XSetWindowBorderWidth);
  _LIBRARY_FIND(library, XSetWindowColormap);
  _LIBRARY_FIND(library, XStoreBuffer);
  _LIBRARY_FIND(library, XStoreBytes);
  _LIBRARY_FIND(library, XStoreColor);
  _LIBRARY_FIND(library, XStoreColors);
  _LIBRARY_FIND(library, XStoreName);
  _LIBRARY_FIND(library, XStoreNamedColor);
  _LIBRARY_FIND(library, XSync);
  _LIBRARY_FIND(library, XTextExtents);
  _LIBRARY_FIND(library, XTextExtents16);
  _LIBRARY_FIND(library, XTextWidth);
  _LIBRARY_FIND(library, XTextWidth16);
  _LIBRARY_FIND(library, XTranslateCoordinates);
  _LIBRARY_FIND(library, XUndefineCursor);
  _LIBRARY_FIND(library, XUngrabButton);
  _LIBRARY_FIND(library, XUngrabKey);
  _LIBRARY_FIND(library, XUngrabKeyboard);
  _LIBRARY_FIND(library, XUngrabPointer);
  _LIBRARY_FIND(library, XUngrabServer);
  _LIBRARY_FIND(library, XUninstallColormap);
  _LIBRARY_FIND(library, XUnloadFont);
  _LIBRARY_FIND(library, XUnmapSubwindows);
  _LIBRARY_FIND(library, XUnmapWindow);
  _LIBRARY_FIND(library, XVendorRelease);
  _LIBRARY_FIND(library, XWarpPointer);
  _LIBRARY_FIND(library, XWidthMMOfScreen);
  _LIBRARY_FIND(library, XWidthOfScreen);
  _LIBRARY_FIND(library, XWindowEvent);
  _LIBRARY_FIND(library, XWriteBitmapFile);
  _LIBRARY_FIND(library, XSupportsLocale);
  _LIBRARY_FIND(library, XSetLocaleModifiers);
  _LIBRARY_FIND(library, XOpenOM);
  _LIBRARY_FIND(library, XCloseOM);
  _LIBRARY_FIND(library, XSetOMValues);
  _LIBRARY_FIND(library, XGetOMValues);
  _LIBRARY_FIND(library, XDisplayOfOM);
  _LIBRARY_FIND(library, XLocaleOfOM);
  _LIBRARY_FIND(library, XCreateOC);
  _LIBRARY_FIND(library, XDestroyOC);
  _LIBRARY_FIND(library, XOMOfOC);
  _LIBRARY_FIND(library, XSetOCValues);
  _LIBRARY_FIND(library, XGetOCValues);
  _LIBRARY_FIND(library, XCreateFontSet);
  _LIBRARY_FIND(library, XFreeFontSet);
  _LIBRARY_FIND(library, XFontsOfFontSet);
  _LIBRARY_FIND(library, XBaseFontNameListOfFontSet);
  _LIBRARY_FIND(library, XLocaleOfFontSet);
  _LIBRARY_FIND(library, XContextDependentDrawing);
  _LIBRARY_FIND(library, XDirectionalDependentDrawing);
  _LIBRARY_FIND(library, XContextualDrawing);
  _LIBRARY_FIND(library, XExtentsOfFontSet);
  _LIBRARY_FIND(library, XmbTextEscapement);
  _LIBRARY_FIND(library, XwcTextEscapement);
  _LIBRARY_FIND(library, Xutf8TextEscapement);
  _LIBRARY_FIND(library, XmbTextExtents);
  _LIBRARY_FIND(library, XwcTextExtents);
  _LIBRARY_FIND(library, Xutf8TextExtents);
  _LIBRARY_FIND(library, XmbTextPerCharExtents);
  _LIBRARY_FIND(library, XwcTextPerCharExtents);
  _LIBRARY_FIND(library, Xutf8TextPerCharExtents);
  _LIBRARY_FIND(library, XmbDrawText);
  _LIBRARY_FIND(library, XwcDrawText);
  _LIBRARY_FIND(library, Xutf8DrawText);
  _LIBRARY_FIND(library, XmbDrawString);
  _LIBRARY_FIND(library, XwcDrawString);
  _LIBRARY_FIND(library, Xutf8DrawString);
  _LIBRARY_FIND(library, XmbDrawImageString);
  _LIBRARY_FIND(library, XwcDrawImageString);
  _LIBRARY_FIND(library, Xutf8DrawImageString);
  _LIBRARY_FIND(library, XOpenIM);
  _LIBRARY_FIND(library, XCloseIM);
  _LIBRARY_FIND(library, XGetIMValues);
  _LIBRARY_FIND(library, XSetIMValues);
  _LIBRARY_FIND(library, XDisplayOfIM);
  _LIBRARY_FIND(library, XLocaleOfIM);
  _LIBRARY_FIND(library, XCreateIC);
  _LIBRARY_FIND(library, XDestroyIC);
  _LIBRARY_FIND(library, XSetICFocus);
  _LIBRARY_FIND(library, XUnsetICFocus);
  _LIBRARY_FIND(library, XwcResetIC);
  _LIBRARY_FIND(library, XmbResetIC);
  _LIBRARY_FIND(library, Xutf8ResetIC);
  _LIBRARY_FIND(library, XSetICValues);
  _LIBRARY_FIND(library, XGetICValues);
  _LIBRARY_FIND(library, XIMOfIC);
  _LIBRARY_FIND(library, XFilterEvent);
  _LIBRARY_FIND(library, XmbLookupString);
  _LIBRARY_FIND(library, XwcLookupString);
  _LIBRARY_FIND(library, Xutf8LookupString);
  _LIBRARY_FIND(library, XVaCreateNestedList);
  _LIBRARY_FIND(library, XRegisterIMInstantiateCallback);
  _LIBRARY_FIND(library, XUnregisterIMInstantiateCallback);
  _LIBRARY_FIND(library, XInternalConnectionNumbers);
  _LIBRARY_FIND(library, XProcessInternalConnection);
  _LIBRARY_FIND(library, XAddConnectionWatch);
  _LIBRARY_FIND(library, XRemoveConnectionWatch);
  _LIBRARY_FIND(library, XSetAuthorization);
  _LIBRARY_FIND(library, _Xmbtowc);
  _LIBRARY_FIND(library, _Xwctomb);
  _LIBRARY_FIND(library, XGetEventData);
  _LIBRARY_FIND(library, XFreeEventData);
  return X11EW_SUCCESS;
}

void __x11ew_exit_xlib(void) {
  if (library != NULL) {
    dynamic_library_close(library);
    library = NULL;
  }
}

