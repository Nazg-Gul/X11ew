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
tXkbIgnoreExtension *XkbIgnoreExtension_impl;
tXkbOpenDisplay *XkbOpenDisplay_impl;
tXkbQueryExtension *XkbQueryExtension_impl;
tXkbUseExtension *XkbUseExtension_impl;
tXkbLibraryVersion *XkbLibraryVersion_impl;
tXkbSetXlibControls *XkbSetXlibControls_impl;
tXkbGetXlibControls *XkbGetXlibControls_impl;
tXkbXlibControlsImplemented *XkbXlibControlsImplemented_impl;
tXkbSetAtomFuncs *XkbSetAtomFuncs_impl;
tXkbKeycodeToKeysym *XkbKeycodeToKeysym_impl;
tXkbKeysymToModifiers *XkbKeysymToModifiers_impl;
tXkbLookupKeySym *XkbLookupKeySym_impl;
tXkbLookupKeyBinding *XkbLookupKeyBinding_impl;
tXkbTranslateKeyCode *XkbTranslateKeyCode_impl;
tXkbTranslateKeySym *XkbTranslateKeySym_impl;
tXkbSetAutoRepeatRate *XkbSetAutoRepeatRate_impl;
tXkbGetAutoRepeatRate *XkbGetAutoRepeatRate_impl;
tXkbChangeEnabledControls *XkbChangeEnabledControls_impl;
tXkbDeviceBell *XkbDeviceBell_impl;
tXkbForceDeviceBell *XkbForceDeviceBell_impl;
tXkbDeviceBellEvent *XkbDeviceBellEvent_impl;
tXkbBell *XkbBell_impl;
tXkbForceBell *XkbForceBell_impl;
tXkbBellEvent *XkbBellEvent_impl;
tXkbSelectEvents *XkbSelectEvents_impl;
tXkbSelectEventDetails *XkbSelectEventDetails_impl;
tXkbNoteMapChanges *XkbNoteMapChanges_impl;
tXkbNoteNameChanges *XkbNoteNameChanges_impl;
tXkbGetIndicatorState *XkbGetIndicatorState_impl;
tXkbGetDeviceIndicatorState *XkbGetDeviceIndicatorState_impl;
tXkbGetIndicatorMap *XkbGetIndicatorMap_impl;
tXkbSetIndicatorMap *XkbSetIndicatorMap_impl;
tXkbGetNamedIndicator *XkbGetNamedIndicator_impl;
tXkbGetNamedDeviceIndicator *XkbGetNamedDeviceIndicator_impl;
tXkbSetNamedIndicator *XkbSetNamedIndicator_impl;
tXkbSetNamedDeviceIndicator *XkbSetNamedDeviceIndicator_impl;
tXkbLockModifiers *XkbLockModifiers_impl;
tXkbLatchModifiers *XkbLatchModifiers_impl;
tXkbLockGroup *XkbLockGroup_impl;
tXkbLatchGroup *XkbLatchGroup_impl;
tXkbSetServerInternalMods *XkbSetServerInternalMods_impl;
tXkbSetIgnoreLockMods *XkbSetIgnoreLockMods_impl;
tXkbVirtualModsToReal *XkbVirtualModsToReal_impl;
tXkbComputeEffectiveMap *XkbComputeEffectiveMap_impl;
tXkbInitCanonicalKeyTypes *XkbInitCanonicalKeyTypes_impl;
tXkbAllocKeyboard *XkbAllocKeyboard_impl;
tXkbFreeKeyboard *XkbFreeKeyboard_impl;
tXkbAllocClientMap *XkbAllocClientMap_impl;
tXkbAllocServerMap *XkbAllocServerMap_impl;
tXkbFreeClientMap *XkbFreeClientMap_impl;
tXkbFreeServerMap *XkbFreeServerMap_impl;
tXkbAddKeyType *XkbAddKeyType_impl;
tXkbAllocIndicatorMaps *XkbAllocIndicatorMaps_impl;
tXkbFreeIndicatorMaps *XkbFreeIndicatorMaps_impl;
tXkbGetMap *XkbGetMap_impl;
tXkbGetUpdatedMap *XkbGetUpdatedMap_impl;
tXkbGetMapChanges *XkbGetMapChanges_impl;
tXkbRefreshKeyboardMapping *XkbRefreshKeyboardMapping_impl;
tXkbGetKeyTypes *XkbGetKeyTypes_impl;
tXkbGetKeySyms *XkbGetKeySyms_impl;
tXkbGetKeyActions *XkbGetKeyActions_impl;
tXkbGetKeyBehaviors *XkbGetKeyBehaviors_impl;
tXkbGetVirtualMods *XkbGetVirtualMods_impl;
tXkbGetKeyExplicitComponents *XkbGetKeyExplicitComponents_impl;
tXkbGetKeyModifierMap *XkbGetKeyModifierMap_impl;
tXkbGetKeyVirtualModMap *XkbGetKeyVirtualModMap_impl;
tXkbAllocControls *XkbAllocControls_impl;
tXkbFreeControls *XkbFreeControls_impl;
tXkbGetControls *XkbGetControls_impl;
tXkbSetControls *XkbSetControls_impl;
tXkbNoteControlsChanges *XkbNoteControlsChanges_impl;
tXkbAllocCompatMap *XkbAllocCompatMap_impl;
tXkbFreeCompatMap *XkbFreeCompatMap_impl;
tXkbGetCompatMap *XkbGetCompatMap_impl;
tXkbSetCompatMap *XkbSetCompatMap_impl;
tXkbAddSymInterpret *XkbAddSymInterpret_impl;
tXkbAllocNames *XkbAllocNames_impl;
tXkbGetNames *XkbGetNames_impl;
tXkbSetNames *XkbSetNames_impl;
tXkbChangeNames *XkbChangeNames_impl;
tXkbFreeNames *XkbFreeNames_impl;
tXkbGetState *XkbGetState_impl;
tXkbSetMap *XkbSetMap_impl;
tXkbChangeMap *XkbChangeMap_impl;
tXkbSetDetectableAutoRepeat *XkbSetDetectableAutoRepeat_impl;
tXkbGetDetectableAutoRepeat *XkbGetDetectableAutoRepeat_impl;
tXkbSetAutoResetControls *XkbSetAutoResetControls_impl;
tXkbGetAutoResetControls *XkbGetAutoResetControls_impl;
tXkbSetPerClientControls *XkbSetPerClientControls_impl;
tXkbGetPerClientControls *XkbGetPerClientControls_impl;
tXkbCopyKeyType *XkbCopyKeyType_impl;
tXkbCopyKeyTypes *XkbCopyKeyTypes_impl;
tXkbResizeKeyType *XkbResizeKeyType_impl;
tXkbResizeKeySyms *XkbResizeKeySyms_impl;
tXkbResizeKeyActions *XkbResizeKeyActions_impl;
tXkbChangeTypesOfKey *XkbChangeTypesOfKey_impl;
tXkbChangeKeycodeRange *XkbChangeKeycodeRange_impl;
tXkbListComponents *XkbListComponents_impl;
tXkbFreeComponentList *XkbFreeComponentList_impl;
tXkbGetKeyboard *XkbGetKeyboard_impl;
tXkbGetKeyboardByName *XkbGetKeyboardByName_impl;
tXkbKeyTypesForCoreSymbols *XkbKeyTypesForCoreSymbols_impl;
tXkbApplyCompatMapToKey *XkbApplyCompatMapToKey_impl;
tXkbUpdateMapFromCore *XkbUpdateMapFromCore_impl;
tXkbAddDeviceLedInfo *XkbAddDeviceLedInfo_impl;
tXkbResizeDeviceButtonActions *XkbResizeDeviceButtonActions_impl;
tXkbAllocDeviceInfo *XkbAllocDeviceInfo_impl;
tXkbFreeDeviceInfo *XkbFreeDeviceInfo_impl;
tXkbNoteDeviceChanges *XkbNoteDeviceChanges_impl;
tXkbGetDeviceInfo *XkbGetDeviceInfo_impl;
tXkbGetDeviceInfoChanges *XkbGetDeviceInfoChanges_impl;
tXkbGetDeviceButtonActions *XkbGetDeviceButtonActions_impl;
tXkbGetDeviceLedInfo *XkbGetDeviceLedInfo_impl;
tXkbSetDeviceInfo *XkbSetDeviceInfo_impl;
tXkbChangeDeviceInfo *XkbChangeDeviceInfo_impl;
tXkbSetDeviceLedInfo *XkbSetDeviceLedInfo_impl;
tXkbSetDeviceButtonActions *XkbSetDeviceButtonActions_impl;
tXkbToControl *XkbToControl_impl;
tXkbSetDebuggingFlags *XkbSetDebuggingFlags_impl;
tXkbApplyVirtualModChanges *XkbApplyVirtualModChanges_impl;
tXkbUpdateActionVirtualMods *XkbUpdateActionVirtualMods_impl;
tXkbUpdateKeyTypeVirtualMods *XkbUpdateKeyTypeVirtualMods_impl;

/* Function wrappers. */
Bool XkbIgnoreExtension(Bool ignore) {
  return XkbIgnoreExtension_impl(ignore);
}

Display* XkbOpenDisplay(char* name, int* ev_rtrn, int* err_rtrn, int* major_rtrn, int* minor_rtrn, int* reason) {
  return XkbOpenDisplay_impl(name, ev_rtrn, err_rtrn, major_rtrn, minor_rtrn, reason);
}

Bool XkbQueryExtension(
    Display* dpy,
    int* opcodeReturn,
    int* eventBaseReturn,
    int* errorBaseReturn,
    int* majorRtrn,
    int* minorRtrn) {
  return XkbQueryExtension_impl(dpy, opcodeReturn, eventBaseReturn, errorBaseReturn, majorRtrn, minorRtrn);
}

Bool XkbUseExtension(Display* dpy, int* major_rtrn, int* minor_rtrn) {
  return XkbUseExtension_impl(dpy, major_rtrn, minor_rtrn);
}

Bool XkbLibraryVersion(int* libMajorRtrn, int* libMinorRtrn) {
  return XkbLibraryVersion_impl(libMajorRtrn, libMinorRtrn);
}

unsigned int XkbSetXlibControls(Display* dpy, unsigned int affect, unsigned int values) {
  return XkbSetXlibControls_impl(dpy, affect, values);
}

unsigned int XkbGetXlibControls(Display* dpy) {
  return XkbGetXlibControls_impl(dpy);
}

unsigned int XkbXlibControlsImplemented(void ) {
  return XkbXlibControlsImplemented_impl();
}

void XkbSetAtomFuncs(XkbInternAtomFunc getAtom, XkbGetAtomNameFunc getName) {
  return XkbSetAtomFuncs_impl(getAtom, getName);
}

KeySym XkbKeycodeToKeysym(
    Display* dpy,
#if NeedWidePrototypes
    unsigned int kc,
#else
    KeyCode kc,
#endif
    int group,
    int level) {
  return XkbKeycodeToKeysym_impl(dpy, kc, group, level);
}

unsigned int XkbKeysymToModifiers(Display* dpy, KeySym ks) {
  return XkbKeysymToModifiers_impl(dpy, ks);
}

Bool XkbLookupKeySym(
    Display* dpy,
#if NeedWidePrototypes
    unsigned int keycode,
#else
    KeyCode keycode,
#endif
    unsigned int modifiers,
    unsigned int* modifiers_return,
    KeySym* keysym_return) {
  return XkbLookupKeySym_impl(dpy, keycode, modifiers, modifiers_return, keysym_return);
}

int XkbLookupKeyBinding(Display* dpy, KeySym sym_rtrn, unsigned int mods, char* buffer, int nbytes, int* extra_rtrn) {
  return XkbLookupKeyBinding_impl(dpy, sym_rtrn, mods, buffer, nbytes, extra_rtrn);
}

Bool XkbTranslateKeyCode(
    XkbDescPtr xkb,
#if NeedWidePrototypes
    unsigned int keycode,
#else
    KeyCode keycode,
#endif
    unsigned int modifiers,
    unsigned int* modifiers_return,
    KeySym* keysym_return) {
  return XkbTranslateKeyCode_impl(xkb, keycode, modifiers, modifiers_return, keysym_return);
}

int XkbTranslateKeySym(
    Display* dpy,
    register KeySym* sym_return,
    unsigned int modifiers,
    char* buffer,
    int nbytes,
    int* extra_rtrn) {
  return XkbTranslateKeySym_impl(dpy, sym_return, modifiers, buffer, nbytes, extra_rtrn);
}

Bool XkbSetAutoRepeatRate(Display* dpy, unsigned int deviceSpec, unsigned int delay, unsigned int interval) {
  return XkbSetAutoRepeatRate_impl(dpy, deviceSpec, delay, interval);
}

Bool XkbGetAutoRepeatRate(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int* delayRtrn,
    unsigned int* intervalRtrn) {
  return XkbGetAutoRepeatRate_impl(dpy, deviceSpec, delayRtrn, intervalRtrn);
}

Bool XkbChangeEnabledControls(Display* dpy, unsigned int deviceSpec, unsigned int affect, unsigned int values) {
  return XkbChangeEnabledControls_impl(dpy, deviceSpec, affect, values);
}

Bool XkbDeviceBell(Display* dpy, Window win, int deviceSpec, int bellClass, int bellID, int percent, Atom name) {
  return XkbDeviceBell_impl(dpy, win, deviceSpec, bellClass, bellID, percent, name);
}

Bool XkbForceDeviceBell(Display* dpy, int deviceSpec, int bellClass, int bellID, int percent) {
  return XkbForceDeviceBell_impl(dpy, deviceSpec, bellClass, bellID, percent);
}

Bool XkbDeviceBellEvent(Display* dpy, Window win, int deviceSpec, int bellClass, int bellID, int percent, Atom name) {
  return XkbDeviceBellEvent_impl(dpy, win, deviceSpec, bellClass, bellID, percent, name);
}

Bool XkbBell(Display* dpy, Window win, int percent, Atom name) {
  return XkbBell_impl(dpy, win, percent, name);
}

Bool XkbForceBell(Display* dpy, int percent) {
  return XkbForceBell_impl(dpy, percent);
}

Bool XkbBellEvent(Display* dpy, Window win, int percent, Atom name) {
  return XkbBellEvent_impl(dpy, win, percent, name);
}

Bool XkbSelectEvents(Display* dpy, unsigned int deviceID, unsigned int affect, unsigned int values) {
  return XkbSelectEvents_impl(dpy, deviceID, affect, values);
}

Bool XkbSelectEventDetails(
    Display* dpy,
    unsigned int deviceID,
    unsigned int eventType,
    unsigned long affect,
    unsigned long details) {
  return XkbSelectEventDetails_impl(dpy, deviceID, eventType, affect, details);
}

void XkbNoteMapChanges(XkbMapChangesPtr old, XkbMapNotifyEvent* new_, unsigned int wanted) {
  return XkbNoteMapChanges_impl(old, new_, wanted);
}

void XkbNoteNameChanges(XkbNameChangesPtr old, XkbNamesNotifyEvent* new_, unsigned int wanted) {
  return XkbNoteNameChanges_impl(old, new_, wanted);
}

Status XkbGetIndicatorState(Display* dpy, unsigned int deviceSpec, unsigned int* pStateRtrn) {
  return XkbGetIndicatorState_impl(dpy, deviceSpec, pStateRtrn);
}

Status XkbGetDeviceIndicatorState(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int ledClass,
    unsigned int ledID,
    unsigned int* pStateRtrn) {
  return XkbGetDeviceIndicatorState_impl(dpy, deviceSpec, ledClass, ledID, pStateRtrn);
}

Status XkbGetIndicatorMap(Display* dpy, unsigned long which, XkbDescPtr desc) {
  return XkbGetIndicatorMap_impl(dpy, which, desc);
}

Bool XkbSetIndicatorMap(Display* dpy, unsigned long which, XkbDescPtr desc) {
  return XkbSetIndicatorMap_impl(dpy, which, desc);
}

Bool XkbGetNamedIndicator(
    Display* dpy,
    Atom name,
    int* pNdxRtrn,
    Bool* pStateRtrn,
    XkbIndicatorMapPtr pMapRtrn,
    Bool* pRealRtrn) {
  return XkbGetNamedIndicator_impl(dpy, name, pNdxRtrn, pStateRtrn, pMapRtrn, pRealRtrn);
}

Bool XkbGetNamedDeviceIndicator(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int ledClass,
    unsigned int ledID,
    Atom name,
    int* pNdxRtrn,
    Bool* pStateRtrn,
    XkbIndicatorMapPtr pMapRtrn,
    Bool* pRealRtrn) {
  return XkbGetNamedDeviceIndicator_impl(dpy, deviceSpec, ledClass, ledID, name, pNdxRtrn, pStateRtrn, pMapRtrn, pRealRtrn);
}

Bool XkbSetNamedIndicator(
    Display* dpy,
    Atom name,
    Bool changeState,
    Bool state,
    Bool createNewMap,
    XkbIndicatorMapPtr pMap) {
  return XkbSetNamedIndicator_impl(dpy, name, changeState, state, createNewMap, pMap);
}

Bool XkbSetNamedDeviceIndicator(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int ledClass,
    unsigned int ledID,
    Atom name,
    Bool changeState,
    Bool state,
    Bool createNewMap,
    XkbIndicatorMapPtr pMap) {
  return XkbSetNamedDeviceIndicator_impl(dpy, deviceSpec, ledClass, ledID, name, changeState, state, createNewMap, pMap);
}

Bool XkbLockModifiers(Display* dpy, unsigned int deviceSpec, unsigned int affect, unsigned int values) {
  return XkbLockModifiers_impl(dpy, deviceSpec, affect, values);
}

Bool XkbLatchModifiers(Display* dpy, unsigned int deviceSpec, unsigned int affect, unsigned int values) {
  return XkbLatchModifiers_impl(dpy, deviceSpec, affect, values);
}

Bool XkbLockGroup(Display* dpy, unsigned int deviceSpec, unsigned int group) {
  return XkbLockGroup_impl(dpy, deviceSpec, group);
}

Bool XkbLatchGroup(Display* dpy, unsigned int deviceSpec, unsigned int group) {
  return XkbLatchGroup_impl(dpy, deviceSpec, group);
}

Bool XkbSetServerInternalMods(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int affectReal,
    unsigned int realValues,
    unsigned int affectVirtual,
    unsigned int virtualValues) {
  return XkbSetServerInternalMods_impl(dpy, deviceSpec, affectReal, realValues, affectVirtual, virtualValues);
}

Bool XkbSetIgnoreLockMods(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int affectReal,
    unsigned int realValues,
    unsigned int affectVirtual,
    unsigned int virtualValues) {
  return XkbSetIgnoreLockMods_impl(dpy, deviceSpec, affectReal, realValues, affectVirtual, virtualValues);
}

Bool XkbVirtualModsToReal(XkbDescPtr xkb, unsigned int virtual_mask, unsigned int* mask_rtrn) {
  return XkbVirtualModsToReal_impl(xkb, virtual_mask, mask_rtrn);
}

Bool XkbComputeEffectiveMap(XkbDescPtr xkb, XkbKeyTypePtr type, unsigned char* map_rtrn) {
  return XkbComputeEffectiveMap_impl(xkb, type, map_rtrn);
}

Status XkbInitCanonicalKeyTypes(XkbDescPtr xkb, unsigned int which, int keypadVMod) {
  return XkbInitCanonicalKeyTypes_impl(xkb, which, keypadVMod);
}

XkbDescPtr XkbAllocKeyboard(void ) {
  return XkbAllocKeyboard_impl();
}

void XkbFreeKeyboard(XkbDescPtr xkb, unsigned int which, Bool freeDesc) {
  return XkbFreeKeyboard_impl(xkb, which, freeDesc);
}

Status XkbAllocClientMap(XkbDescPtr xkb, unsigned int which, unsigned int nTypes) {
  return XkbAllocClientMap_impl(xkb, which, nTypes);
}

Status XkbAllocServerMap(XkbDescPtr xkb, unsigned int which, unsigned int nActions) {
  return XkbAllocServerMap_impl(xkb, which, nActions);
}

void XkbFreeClientMap(XkbDescPtr xkb, unsigned int what, Bool freeMap) {
  return XkbFreeClientMap_impl(xkb, what, freeMap);
}

void XkbFreeServerMap(XkbDescPtr xkb, unsigned int what, Bool freeMap) {
  return XkbFreeServerMap_impl(xkb, what, freeMap);
}

XkbKeyTypePtr XkbAddKeyType(XkbDescPtr xkb, Atom name, int map_count, Bool want_preserve, int num_lvls) {
  return XkbAddKeyType_impl(xkb, name, map_count, want_preserve, num_lvls);
}

Status XkbAllocIndicatorMaps(XkbDescPtr xkb) {
  return XkbAllocIndicatorMaps_impl(xkb);
}

void XkbFreeIndicatorMaps(XkbDescPtr xkb) {
  return XkbFreeIndicatorMaps_impl(xkb);
}

XkbDescPtr XkbGetMap(Display* dpy, unsigned int which, unsigned int deviceSpec) {
  return XkbGetMap_impl(dpy, which, deviceSpec);
}

Status XkbGetUpdatedMap(Display* dpy, unsigned int which, XkbDescPtr desc) {
  return XkbGetUpdatedMap_impl(dpy, which, desc);
}

Status XkbGetMapChanges(Display* dpy, XkbDescPtr xkb, XkbMapChangesPtr changes) {
  return XkbGetMapChanges_impl(dpy, xkb, changes);
}

Status XkbRefreshKeyboardMapping(XkbMapNotifyEvent* event) {
  return XkbRefreshKeyboardMapping_impl(event);
}

Status XkbGetKeyTypes(Display* dpy, unsigned int first, unsigned int num, XkbDescPtr xkb) {
  return XkbGetKeyTypes_impl(dpy, first, num, xkb);
}

Status XkbGetKeySyms(Display* dpy, unsigned int first, unsigned int num, XkbDescPtr xkb) {
  return XkbGetKeySyms_impl(dpy, first, num, xkb);
}

Status XkbGetKeyActions(Display* dpy, unsigned int first, unsigned int num, XkbDescPtr xkb) {
  return XkbGetKeyActions_impl(dpy, first, num, xkb);
}

Status XkbGetKeyBehaviors(Display* dpy, unsigned int firstKey, unsigned int nKeys, XkbDescPtr desc) {
  return XkbGetKeyBehaviors_impl(dpy, firstKey, nKeys, desc);
}

Status XkbGetVirtualMods(Display* dpy, unsigned int which, XkbDescPtr desc) {
  return XkbGetVirtualMods_impl(dpy, which, desc);
}

Status XkbGetKeyExplicitComponents(Display* dpy, unsigned int firstKey, unsigned int nKeys, XkbDescPtr desc) {
  return XkbGetKeyExplicitComponents_impl(dpy, firstKey, nKeys, desc);
}

Status XkbGetKeyModifierMap(Display* dpy, unsigned int firstKey, unsigned int nKeys, XkbDescPtr desc) {
  return XkbGetKeyModifierMap_impl(dpy, firstKey, nKeys, desc);
}

Status XkbGetKeyVirtualModMap(Display* dpy, unsigned int first, unsigned int num, XkbDescPtr xkb) {
  return XkbGetKeyVirtualModMap_impl(dpy, first, num, xkb);
}

Status XkbAllocControls(XkbDescPtr xkb, unsigned int which) {
  return XkbAllocControls_impl(xkb, which);
}

void XkbFreeControls(XkbDescPtr xkb, unsigned int which, Bool freeMap) {
  return XkbFreeControls_impl(xkb, which, freeMap);
}

Status XkbGetControls(Display* dpy, unsigned long which, XkbDescPtr desc) {
  return XkbGetControls_impl(dpy, which, desc);
}

Bool XkbSetControls(Display* dpy, unsigned long which, XkbDescPtr desc) {
  return XkbSetControls_impl(dpy, which, desc);
}

void XkbNoteControlsChanges(XkbControlsChangesPtr old, XkbControlsNotifyEvent* new_, unsigned int wanted) {
  return XkbNoteControlsChanges_impl(old, new_, wanted);
}

Status XkbAllocCompatMap(XkbDescPtr xkb, unsigned int which, unsigned int nInterpret) {
  return XkbAllocCompatMap_impl(xkb, which, nInterpret);
}

void XkbFreeCompatMap(XkbDescPtr xkb, unsigned int which, Bool freeMap) {
  return XkbFreeCompatMap_impl(xkb, which, freeMap);
}

Status XkbGetCompatMap(Display* dpy, unsigned int which, XkbDescPtr xkb) {
  return XkbGetCompatMap_impl(dpy, which, xkb);
}

Bool XkbSetCompatMap(Display* dpy, unsigned int which, XkbDescPtr xkb, Bool updateActions) {
  return XkbSetCompatMap_impl(dpy, which, xkb, updateActions);
}

XkbSymInterpretPtr XkbAddSymInterpret(XkbDescPtr xkb, XkbSymInterpretPtr si, Bool updateMap, XkbChangesPtr changes) {
  return XkbAddSymInterpret_impl(xkb, si, updateMap, changes);
}

Status XkbAllocNames(XkbDescPtr xkb, unsigned int which, int nTotalRG, int nTotalAliases) {
  return XkbAllocNames_impl(xkb, which, nTotalRG, nTotalAliases);
}

Status XkbGetNames(Display* dpy, unsigned int which, XkbDescPtr desc) {
  return XkbGetNames_impl(dpy, which, desc);
}

Bool XkbSetNames(
    Display* dpy,
    unsigned int which,
    unsigned int firstType,
    unsigned int nTypes,
    XkbDescPtr desc) {
  return XkbSetNames_impl(dpy, which, firstType, nTypes, desc);
}

Bool XkbChangeNames(Display* dpy, XkbDescPtr xkb, XkbNameChangesPtr changes) {
  return XkbChangeNames_impl(dpy, xkb, changes);
}

void XkbFreeNames(XkbDescPtr xkb, unsigned int which, Bool freeMap) {
  return XkbFreeNames_impl(xkb, which, freeMap);
}

Status XkbGetState(Display* dpy, unsigned int deviceSpec, XkbStatePtr rtrnState) {
  return XkbGetState_impl(dpy, deviceSpec, rtrnState);
}

Bool XkbSetMap(Display* dpy, unsigned int which, XkbDescPtr desc) {
  return XkbSetMap_impl(dpy, which, desc);
}

Bool XkbChangeMap(Display* dpy, XkbDescPtr desc, XkbMapChangesPtr changes) {
  return XkbChangeMap_impl(dpy, desc, changes);
}

Bool XkbSetDetectableAutoRepeat(Display* dpy, Bool detectable, Bool* supported) {
  return XkbSetDetectableAutoRepeat_impl(dpy, detectable, supported);
}

Bool XkbGetDetectableAutoRepeat(Display* dpy, Bool* supported) {
  return XkbGetDetectableAutoRepeat_impl(dpy, supported);
}

Bool XkbSetAutoResetControls(Display* dpy, unsigned int changes, unsigned int* auto_ctrls, unsigned int* auto_values) {
  return XkbSetAutoResetControls_impl(dpy, changes, auto_ctrls, auto_values);
}

Bool XkbGetAutoResetControls(Display* dpy, unsigned int* auto_ctrls, unsigned int* auto_ctrl_values) {
  return XkbGetAutoResetControls_impl(dpy, auto_ctrls, auto_ctrl_values);
}

Bool XkbSetPerClientControls(Display* dpy, unsigned int change, unsigned int* values) {
  return XkbSetPerClientControls_impl(dpy, change, values);
}

Bool XkbGetPerClientControls(Display* dpy, unsigned int* ctrls) {
  return XkbGetPerClientControls_impl(dpy, ctrls);
}

Status XkbCopyKeyType(XkbKeyTypePtr from, XkbKeyTypePtr into) {
  return XkbCopyKeyType_impl(from, into);
}

Status XkbCopyKeyTypes(XkbKeyTypePtr from, XkbKeyTypePtr into, int num_types) {
  return XkbCopyKeyTypes_impl(from, into, num_types);
}

Status XkbResizeKeyType(XkbDescPtr xkb, int type_ndx, int map_count, Bool want_preserve, int new_num_lvls) {
  return XkbResizeKeyType_impl(xkb, type_ndx, map_count, want_preserve, new_num_lvls);
}

KeySym* XkbResizeKeySyms(XkbDescPtr desc, int forKey, int symsNeeded) {
  return XkbResizeKeySyms_impl(desc, forKey, symsNeeded);
}

XkbAction* XkbResizeKeyActions(XkbDescPtr desc, int forKey, int actsNeeded) {
  return XkbResizeKeyActions_impl(desc, forKey, actsNeeded);
}

Status XkbChangeTypesOfKey(
    XkbDescPtr xkb,
    int key,
    int num_groups,
    unsigned int groups,
    int* newTypes,
    XkbMapChangesPtr pChanges) {
  return XkbChangeTypesOfKey_impl(xkb, key, num_groups, groups, newTypes, pChanges);
}

Status XkbChangeKeycodeRange(XkbDescPtr xkb, int minKC, int maxKC, XkbChangesPtr changes) {
  return XkbChangeKeycodeRange_impl(xkb, minKC, maxKC, changes);
}

XkbComponentListPtr XkbListComponents(Display* dpy, unsigned int deviceSpec, XkbComponentNamesPtr ptrns, int* max_inout) {
  return XkbListComponents_impl(dpy, deviceSpec, ptrns, max_inout);
}

void XkbFreeComponentList(XkbComponentListPtr list) {
  return XkbFreeComponentList_impl(list);
}

XkbDescPtr XkbGetKeyboard(Display* dpy, unsigned int which, unsigned int deviceSpec) {
  return XkbGetKeyboard_impl(dpy, which, deviceSpec);
}

XkbDescPtr XkbGetKeyboardByName(
    Display* dpy,
    unsigned int deviceSpec,
    XkbComponentNamesPtr names,
    unsigned int want,
    unsigned int need,
    Bool load) {
  return XkbGetKeyboardByName_impl(dpy, deviceSpec, names, want, need, load);
}

int XkbKeyTypesForCoreSymbols(
    XkbDescPtr xkb,
    int map_width,
    KeySym* core_syms,
    unsigned int protected_,
    int* types_inout,
    KeySym* xkb_syms_rtrn) {
  return XkbKeyTypesForCoreSymbols_impl(xkb, map_width, core_syms, protected_, types_inout, xkb_syms_rtrn);
}

Bool XkbApplyCompatMapToKey(
    XkbDescPtr xkb,
#if NeedWidePrototypes
    unsigned int key,
#else
    KeyCode key,
#endif
    XkbChangesPtr changes) {
  return XkbApplyCompatMapToKey_impl(xkb, key, changes);
}

Bool XkbUpdateMapFromCore(
    XkbDescPtr xkb,
#if NeedWidePrototypes
    unsigned int first_key,
#else
    KeyCode first_key,
#endif
    int num_keys,
    int map_width,
    KeySym* core_keysyms,
    XkbChangesPtr changes) {
  return XkbUpdateMapFromCore_impl(xkb, first_key, num_keys, map_width, core_keysyms, changes);
}

XkbDeviceLedInfoPtr XkbAddDeviceLedInfo(XkbDeviceInfoPtr devi, unsigned int ledClass, unsigned int ledId) {
  return XkbAddDeviceLedInfo_impl(devi, ledClass, ledId);
}

Status XkbResizeDeviceButtonActions(XkbDeviceInfoPtr devi, unsigned int newTotal) {
  return XkbResizeDeviceButtonActions_impl(devi, newTotal);
}

XkbDeviceInfoPtr XkbAllocDeviceInfo(unsigned int deviceSpec, unsigned int nButtons, unsigned int szLeds) {
  return XkbAllocDeviceInfo_impl(deviceSpec, nButtons, szLeds);
}

void XkbFreeDeviceInfo(XkbDeviceInfoPtr devi, unsigned int which, Bool freeDevI) {
  return XkbFreeDeviceInfo_impl(devi, which, freeDevI);
}

void XkbNoteDeviceChanges(XkbDeviceChangesPtr old, XkbExtensionDeviceNotifyEvent* new_, unsigned int wanted) {
  return XkbNoteDeviceChanges_impl(old, new_, wanted);
}

XkbDeviceInfoPtr XkbGetDeviceInfo(
    Display* dpy,
    unsigned int which,
    unsigned int deviceSpec,
    unsigned int ledClass,
    unsigned int ledID) {
  return XkbGetDeviceInfo_impl(dpy, which, deviceSpec, ledClass, ledID);
}

Status XkbGetDeviceInfoChanges(Display* dpy, XkbDeviceInfoPtr devi, XkbDeviceChangesPtr changes) {
  return XkbGetDeviceInfoChanges_impl(dpy, devi, changes);
}

Status XkbGetDeviceButtonActions(Display* dpy, XkbDeviceInfoPtr devi, Bool all, unsigned int first, unsigned int nBtns) {
  return XkbGetDeviceButtonActions_impl(dpy, devi, all, first, nBtns);
}

Status XkbGetDeviceLedInfo(
    Display* dpy,
    XkbDeviceInfoPtr devi,
    unsigned int ledClass,
    unsigned int ledId,
    unsigned int which) {
  return XkbGetDeviceLedInfo_impl(dpy, devi, ledClass, ledId, which);
}

Bool XkbSetDeviceInfo(Display* dpy, unsigned int which, XkbDeviceInfoPtr devi) {
  return XkbSetDeviceInfo_impl(dpy, which, devi);
}

Bool XkbChangeDeviceInfo(Display* dpy, XkbDeviceInfoPtr desc, XkbDeviceChangesPtr changes) {
  return XkbChangeDeviceInfo_impl(dpy, desc, changes);
}

Bool XkbSetDeviceLedInfo(
    Display* dpy,
    XkbDeviceInfoPtr devi,
    unsigned int ledClass,
    unsigned int ledID,
    unsigned int which) {
  return XkbSetDeviceLedInfo_impl(dpy, devi, ledClass, ledID, which);
}

Bool XkbSetDeviceButtonActions(Display* dpy, XkbDeviceInfoPtr devi, unsigned int first, unsigned int nBtns) {
  return XkbSetDeviceButtonActions_impl(dpy, devi, first, nBtns);
}

char XkbToControl(char c) {
  return XkbToControl_impl(c);
}

Bool XkbSetDebuggingFlags(
    Display* dpy,
    unsigned int mask,
    unsigned int flags,
    char* msg,
    unsigned int ctrls_mask,
    unsigned int ctrls,
    unsigned int* rtrn_flags,
    unsigned int* rtrn_ctrls) {
  return XkbSetDebuggingFlags_impl(dpy, mask, flags, msg, ctrls_mask, ctrls, rtrn_flags, rtrn_ctrls);
}

Bool XkbApplyVirtualModChanges(XkbDescPtr xkb, unsigned int changed, XkbChangesPtr changes) {
  return XkbApplyVirtualModChanges_impl(xkb, changed, changes);
}

Bool XkbUpdateActionVirtualMods(XkbDescPtr xkb, XkbAction* act, unsigned int changed) {
  return XkbUpdateActionVirtualMods_impl(xkb, act, changed);
}

void XkbUpdateKeyTypeVirtualMods(XkbDescPtr xkb, XkbKeyTypePtr type, unsigned int changed, XkbChangesPtr changes) {
  return XkbUpdateKeyTypeVirtualMods_impl(xkb, type, changed, changes);
}


int __x11ew_init_xkblib(void) {
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
  _LIBRARY_FIND(library, XkbIgnoreExtension);
  _LIBRARY_FIND(library, XkbOpenDisplay);
  _LIBRARY_FIND(library, XkbQueryExtension);
  _LIBRARY_FIND(library, XkbUseExtension);
  _LIBRARY_FIND(library, XkbLibraryVersion);
  _LIBRARY_FIND(library, XkbSetXlibControls);
  _LIBRARY_FIND(library, XkbGetXlibControls);
  _LIBRARY_FIND(library, XkbXlibControlsImplemented);
  _LIBRARY_FIND(library, XkbSetAtomFuncs);
  _LIBRARY_FIND(library, XkbKeycodeToKeysym);
  _LIBRARY_FIND(library, XkbKeysymToModifiers);
  _LIBRARY_FIND(library, XkbLookupKeySym);
  _LIBRARY_FIND(library, XkbLookupKeyBinding);
  _LIBRARY_FIND(library, XkbTranslateKeyCode);
  _LIBRARY_FIND(library, XkbTranslateKeySym);
  _LIBRARY_FIND(library, XkbSetAutoRepeatRate);
  _LIBRARY_FIND(library, XkbGetAutoRepeatRate);
  _LIBRARY_FIND(library, XkbChangeEnabledControls);
  _LIBRARY_FIND(library, XkbDeviceBell);
  _LIBRARY_FIND(library, XkbForceDeviceBell);
  _LIBRARY_FIND(library, XkbDeviceBellEvent);
  _LIBRARY_FIND(library, XkbBell);
  _LIBRARY_FIND(library, XkbForceBell);
  _LIBRARY_FIND(library, XkbBellEvent);
  _LIBRARY_FIND(library, XkbSelectEvents);
  _LIBRARY_FIND(library, XkbSelectEventDetails);
  _LIBRARY_FIND(library, XkbNoteMapChanges);
  _LIBRARY_FIND(library, XkbNoteNameChanges);
  _LIBRARY_FIND(library, XkbGetIndicatorState);
  _LIBRARY_FIND(library, XkbGetDeviceIndicatorState);
  _LIBRARY_FIND(library, XkbGetIndicatorMap);
  _LIBRARY_FIND(library, XkbSetIndicatorMap);
  _LIBRARY_FIND(library, XkbGetNamedIndicator);
  _LIBRARY_FIND(library, XkbGetNamedDeviceIndicator);
  _LIBRARY_FIND(library, XkbSetNamedIndicator);
  _LIBRARY_FIND(library, XkbSetNamedDeviceIndicator);
  _LIBRARY_FIND(library, XkbLockModifiers);
  _LIBRARY_FIND(library, XkbLatchModifiers);
  _LIBRARY_FIND(library, XkbLockGroup);
  _LIBRARY_FIND(library, XkbLatchGroup);
  _LIBRARY_FIND(library, XkbSetServerInternalMods);
  _LIBRARY_FIND(library, XkbSetIgnoreLockMods);
  _LIBRARY_FIND(library, XkbVirtualModsToReal);
  _LIBRARY_FIND(library, XkbComputeEffectiveMap);
  _LIBRARY_FIND(library, XkbInitCanonicalKeyTypes);
  _LIBRARY_FIND(library, XkbAllocKeyboard);
  _LIBRARY_FIND(library, XkbFreeKeyboard);
  _LIBRARY_FIND(library, XkbAllocClientMap);
  _LIBRARY_FIND(library, XkbAllocServerMap);
  _LIBRARY_FIND(library, XkbFreeClientMap);
  _LIBRARY_FIND(library, XkbFreeServerMap);
  _LIBRARY_FIND(library, XkbAddKeyType);
  _LIBRARY_FIND(library, XkbAllocIndicatorMaps);
  _LIBRARY_FIND(library, XkbFreeIndicatorMaps);
  _LIBRARY_FIND(library, XkbGetMap);
  _LIBRARY_FIND(library, XkbGetUpdatedMap);
  _LIBRARY_FIND(library, XkbGetMapChanges);
  _LIBRARY_FIND(library, XkbRefreshKeyboardMapping);
  _LIBRARY_FIND(library, XkbGetKeyTypes);
  _LIBRARY_FIND(library, XkbGetKeySyms);
  _LIBRARY_FIND(library, XkbGetKeyActions);
  _LIBRARY_FIND(library, XkbGetKeyBehaviors);
  _LIBRARY_FIND(library, XkbGetVirtualMods);
  _LIBRARY_FIND(library, XkbGetKeyExplicitComponents);
  _LIBRARY_FIND(library, XkbGetKeyModifierMap);
  _LIBRARY_FIND(library, XkbGetKeyVirtualModMap);
  _LIBRARY_FIND(library, XkbAllocControls);
  _LIBRARY_FIND(library, XkbFreeControls);
  _LIBRARY_FIND(library, XkbGetControls);
  _LIBRARY_FIND(library, XkbSetControls);
  _LIBRARY_FIND(library, XkbNoteControlsChanges);
  _LIBRARY_FIND(library, XkbAllocCompatMap);
  _LIBRARY_FIND(library, XkbFreeCompatMap);
  _LIBRARY_FIND(library, XkbGetCompatMap);
  _LIBRARY_FIND(library, XkbSetCompatMap);
  _LIBRARY_FIND(library, XkbAddSymInterpret);
  _LIBRARY_FIND(library, XkbAllocNames);
  _LIBRARY_FIND(library, XkbGetNames);
  _LIBRARY_FIND(library, XkbSetNames);
  _LIBRARY_FIND(library, XkbChangeNames);
  _LIBRARY_FIND(library, XkbFreeNames);
  _LIBRARY_FIND(library, XkbGetState);
  _LIBRARY_FIND(library, XkbSetMap);
  _LIBRARY_FIND(library, XkbChangeMap);
  _LIBRARY_FIND(library, XkbSetDetectableAutoRepeat);
  _LIBRARY_FIND(library, XkbGetDetectableAutoRepeat);
  _LIBRARY_FIND(library, XkbSetAutoResetControls);
  _LIBRARY_FIND(library, XkbGetAutoResetControls);
  _LIBRARY_FIND(library, XkbSetPerClientControls);
  _LIBRARY_FIND(library, XkbGetPerClientControls);
  _LIBRARY_FIND(library, XkbCopyKeyType);
  _LIBRARY_FIND(library, XkbCopyKeyTypes);
  _LIBRARY_FIND(library, XkbResizeKeyType);
  _LIBRARY_FIND(library, XkbResizeKeySyms);
  _LIBRARY_FIND(library, XkbResizeKeyActions);
  _LIBRARY_FIND(library, XkbChangeTypesOfKey);
  _LIBRARY_FIND(library, XkbChangeKeycodeRange);
  _LIBRARY_FIND(library, XkbListComponents);
  _LIBRARY_FIND(library, XkbFreeComponentList);
  _LIBRARY_FIND(library, XkbGetKeyboard);
  _LIBRARY_FIND(library, XkbGetKeyboardByName);
  _LIBRARY_FIND(library, XkbKeyTypesForCoreSymbols);
  _LIBRARY_FIND(library, XkbApplyCompatMapToKey);
  _LIBRARY_FIND(library, XkbUpdateMapFromCore);
  _LIBRARY_FIND(library, XkbAddDeviceLedInfo);
  _LIBRARY_FIND(library, XkbResizeDeviceButtonActions);
  _LIBRARY_FIND(library, XkbAllocDeviceInfo);
  _LIBRARY_FIND(library, XkbFreeDeviceInfo);
  _LIBRARY_FIND(library, XkbNoteDeviceChanges);
  _LIBRARY_FIND(library, XkbGetDeviceInfo);
  _LIBRARY_FIND(library, XkbGetDeviceInfoChanges);
  _LIBRARY_FIND(library, XkbGetDeviceButtonActions);
  _LIBRARY_FIND(library, XkbGetDeviceLedInfo);
  _LIBRARY_FIND(library, XkbSetDeviceInfo);
  _LIBRARY_FIND(library, XkbChangeDeviceInfo);
  _LIBRARY_FIND(library, XkbSetDeviceLedInfo);
  _LIBRARY_FIND(library, XkbSetDeviceButtonActions);
  _LIBRARY_FIND(library, XkbToControl);
  _LIBRARY_FIND(library, XkbSetDebuggingFlags);
  _LIBRARY_FIND(library, XkbApplyVirtualModChanges);
  _LIBRARY_FIND(library, XkbUpdateActionVirtualMods);
  _LIBRARY_FIND(library, XkbUpdateKeyTypeVirtualMods);
  return X11EW_SUCCESS;
}

void __x11ew_exit_xkblib(void) {
  if (library != NULL) {
    dynamic_library_close(library);
    library = NULL;
  }
}

