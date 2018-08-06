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

#ifndef __X11EW_XKBLIB_H__
#define __X11EW_XKBLIB_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Function types. */
typedef Bool tXkbIgnoreExtension(Bool ignore);
typedef Display* tXkbOpenDisplay(
    char* name,
    int* ev_rtrn,
    int* err_rtrn,
    int* major_rtrn,
    int* minor_rtrn,
    int* reason);
typedef Bool tXkbQueryExtension(
    Display* dpy,
    int* opcodeReturn,
    int* eventBaseReturn,
    int* errorBaseReturn,
    int* majorRtrn,
    int* minorRtrn);
typedef Bool tXkbUseExtension(Display* dpy, int* major_rtrn, int* minor_rtrn);
typedef Bool tXkbLibraryVersion(int* libMajorRtrn, int* libMinorRtrn);
typedef unsigned int tXkbSetXlibControls(
    Display* dpy,
    unsigned int affect,
    unsigned int values);
typedef unsigned int tXkbGetXlibControls(Display* dpy);
typedef unsigned int tXkbXlibControlsImplemented(void );
typedef void tXkbSetAtomFuncs(
    XkbInternAtomFunc getAtom,
    XkbGetAtomNameFunc getName);
typedef KeySym tXkbKeycodeToKeysym(
    Display* dpy,
#if NeedWidePrototypes
    unsigned int kc,
#else
    KeyCode kc,
#endif
    int group,
    int level);
typedef unsigned int tXkbKeysymToModifiers(Display* dpy, KeySym ks);
typedef Bool tXkbLookupKeySym(
    Display* dpy,
#if NeedWidePrototypes
    unsigned int keycode,
#else
    KeyCode keycode,
#endif
    unsigned int modifiers,
    unsigned int* modifiers_return,
    KeySym* keysym_return);
typedef int tXkbLookupKeyBinding(
    Display* dpy,
    KeySym sym_rtrn,
    unsigned int mods,
    char* buffer,
    int nbytes,
    int* extra_rtrn);
typedef Bool tXkbTranslateKeyCode(
    XkbDescPtr xkb,
#if NeedWidePrototypes
    unsigned int keycode,
#else
    KeyCode keycode,
#endif
    unsigned int modifiers,
    unsigned int* modifiers_return,
    KeySym* keysym_return);
typedef int tXkbTranslateKeySym(
    Display* dpy,
    register KeySym* sym_return,
    unsigned int modifiers,
    char* buffer,
    int nbytes,
    int* extra_rtrn);
typedef Bool tXkbSetAutoRepeatRate(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int delay,
    unsigned int interval);
typedef Bool tXkbGetAutoRepeatRate(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int* delayRtrn,
    unsigned int* intervalRtrn);
typedef Bool tXkbChangeEnabledControls(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int affect,
    unsigned int values);
typedef Bool tXkbDeviceBell(
    Display* dpy,
    Window win,
    int deviceSpec,
    int bellClass,
    int bellID,
    int percent,
    Atom name);
typedef Bool tXkbForceDeviceBell(
    Display* dpy,
    int deviceSpec,
    int bellClass,
    int bellID,
    int percent);
typedef Bool tXkbDeviceBellEvent(
    Display* dpy,
    Window win,
    int deviceSpec,
    int bellClass,
    int bellID,
    int percent,
    Atom name);
typedef Bool tXkbBell(Display* dpy, Window win, int percent, Atom name);
typedef Bool tXkbForceBell(Display* dpy, int percent);
typedef Bool tXkbBellEvent(Display* dpy, Window win, int percent, Atom name);
typedef Bool tXkbSelectEvents(
    Display* dpy,
    unsigned int deviceID,
    unsigned int affect,
    unsigned int values);
typedef Bool tXkbSelectEventDetails(
    Display* dpy,
    unsigned int deviceID,
    unsigned int eventType,
    unsigned long affect,
    unsigned long details);
typedef void tXkbNoteMapChanges(
    XkbMapChangesPtr old,
    XkbMapNotifyEvent* new_,
    unsigned int wanted);
typedef void tXkbNoteNameChanges(
    XkbNameChangesPtr old,
    XkbNamesNotifyEvent* new_,
    unsigned int wanted);
typedef Status tXkbGetIndicatorState(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int* pStateRtrn);
typedef Status tXkbGetDeviceIndicatorState(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int ledClass,
    unsigned int ledID,
    unsigned int* pStateRtrn);
typedef Status tXkbGetIndicatorMap(
    Display* dpy,
    unsigned long which,
    XkbDescPtr desc);
typedef Bool tXkbSetIndicatorMap(Display* dpy, unsigned long which, XkbDescPtr desc);
typedef Bool tXkbGetNamedIndicator(
    Display* dpy,
    Atom name,
    int* pNdxRtrn,
    Bool* pStateRtrn,
    XkbIndicatorMapPtr pMapRtrn,
    Bool* pRealRtrn);
typedef Bool tXkbGetNamedDeviceIndicator(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int ledClass,
    unsigned int ledID,
    Atom name,
    int* pNdxRtrn,
    Bool* pStateRtrn,
    XkbIndicatorMapPtr pMapRtrn,
    Bool* pRealRtrn);
typedef Bool tXkbSetNamedIndicator(
    Display* dpy,
    Atom name,
    Bool changeState,
    Bool state,
    Bool createNewMap,
    XkbIndicatorMapPtr pMap);
typedef Bool tXkbSetNamedDeviceIndicator(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int ledClass,
    unsigned int ledID,
    Atom name,
    Bool changeState,
    Bool state,
    Bool createNewMap,
    XkbIndicatorMapPtr pMap);
typedef Bool tXkbLockModifiers(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int affect,
    unsigned int values);
typedef Bool tXkbLatchModifiers(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int affect,
    unsigned int values);
typedef Bool tXkbLockGroup(Display* dpy, unsigned int deviceSpec, unsigned int group);
typedef Bool tXkbLatchGroup(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int group);
typedef Bool tXkbSetServerInternalMods(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int affectReal,
    unsigned int realValues,
    unsigned int affectVirtual,
    unsigned int virtualValues);
typedef Bool tXkbSetIgnoreLockMods(
    Display* dpy,
    unsigned int deviceSpec,
    unsigned int affectReal,
    unsigned int realValues,
    unsigned int affectVirtual,
    unsigned int virtualValues);
typedef Bool tXkbVirtualModsToReal(
    XkbDescPtr xkb,
    unsigned int virtual_mask,
    unsigned int* mask_rtrn);
typedef Bool tXkbComputeEffectiveMap(
    XkbDescPtr xkb,
    XkbKeyTypePtr type,
    unsigned char* map_rtrn);
typedef Status tXkbInitCanonicalKeyTypes(
    XkbDescPtr xkb,
    unsigned int which,
    int keypadVMod);
typedef XkbDescPtr tXkbAllocKeyboard(void );
typedef void tXkbFreeKeyboard(XkbDescPtr xkb, unsigned int which, Bool freeDesc);
typedef Status tXkbAllocClientMap(
    XkbDescPtr xkb,
    unsigned int which,
    unsigned int nTypes);
typedef Status tXkbAllocServerMap(
    XkbDescPtr xkb,
    unsigned int which,
    unsigned int nActions);
typedef void tXkbFreeClientMap(XkbDescPtr xkb, unsigned int what, Bool freeMap);
typedef void tXkbFreeServerMap(XkbDescPtr xkb, unsigned int what, Bool freeMap);
typedef XkbKeyTypePtr tXkbAddKeyType(
    XkbDescPtr xkb,
    Atom name,
    int map_count,
    Bool want_preserve,
    int num_lvls);
typedef Status tXkbAllocIndicatorMaps(XkbDescPtr xkb);
typedef void tXkbFreeIndicatorMaps(XkbDescPtr xkb);
typedef XkbDescPtr tXkbGetMap(
    Display* dpy,
    unsigned int which,
    unsigned int deviceSpec);
typedef Status tXkbGetUpdatedMap(Display* dpy, unsigned int which, XkbDescPtr desc);
typedef Status tXkbGetMapChanges(
    Display* dpy,
    XkbDescPtr xkb,
    XkbMapChangesPtr changes);
typedef Status tXkbRefreshKeyboardMapping(XkbMapNotifyEvent* event);
typedef Status tXkbGetKeyTypes(
    Display* dpy,
    unsigned int first,
    unsigned int num,
    XkbDescPtr xkb);
typedef Status tXkbGetKeySyms(
    Display* dpy,
    unsigned int first,
    unsigned int num,
    XkbDescPtr xkb);
typedef Status tXkbGetKeyActions(
    Display* dpy,
    unsigned int first,
    unsigned int num,
    XkbDescPtr xkb);
typedef Status tXkbGetKeyBehaviors(
    Display* dpy,
    unsigned int firstKey,
    unsigned int nKeys,
    XkbDescPtr desc);
typedef Status tXkbGetVirtualMods(Display* dpy, unsigned int which, XkbDescPtr desc);
typedef Status tXkbGetKeyExplicitComponents(
    Display* dpy,
    unsigned int firstKey,
    unsigned int nKeys,
    XkbDescPtr desc);
typedef Status tXkbGetKeyModifierMap(
    Display* dpy,
    unsigned int firstKey,
    unsigned int nKeys,
    XkbDescPtr desc);
typedef Status tXkbGetKeyVirtualModMap(
    Display* dpy,
    unsigned int first,
    unsigned int num,
    XkbDescPtr xkb);
typedef Status tXkbAllocControls(XkbDescPtr xkb, unsigned int which);
typedef void tXkbFreeControls(XkbDescPtr xkb, unsigned int which, Bool freeMap);
typedef Status tXkbGetControls(Display* dpy, unsigned long which, XkbDescPtr desc);
typedef Bool tXkbSetControls(Display* dpy, unsigned long which, XkbDescPtr desc);
typedef void tXkbNoteControlsChanges(
    XkbControlsChangesPtr old,
    XkbControlsNotifyEvent* new_,
    unsigned int wanted);
typedef Status tXkbAllocCompatMap(
    XkbDescPtr xkb,
    unsigned int which,
    unsigned int nInterpret);
typedef void tXkbFreeCompatMap(XkbDescPtr xkb, unsigned int which, Bool freeMap);
typedef Status tXkbGetCompatMap(Display* dpy, unsigned int which, XkbDescPtr xkb);
typedef Bool tXkbSetCompatMap(
    Display* dpy,
    unsigned int which,
    XkbDescPtr xkb,
    Bool updateActions);
typedef XkbSymInterpretPtr tXkbAddSymInterpret(
    XkbDescPtr xkb,
    XkbSymInterpretPtr si,
    Bool updateMap,
    XkbChangesPtr changes);
typedef Status tXkbAllocNames(
    XkbDescPtr xkb,
    unsigned int which,
    int nTotalRG,
    int nTotalAliases);
typedef Status tXkbGetNames(Display* dpy, unsigned int which, XkbDescPtr desc);
typedef Bool tXkbSetNames(
    Display* dpy,
    unsigned int which,
    unsigned int firstType,
    unsigned int nTypes,
    XkbDescPtr desc);
typedef Bool tXkbChangeNames(Display* dpy, XkbDescPtr xkb, XkbNameChangesPtr changes);
typedef void tXkbFreeNames(XkbDescPtr xkb, unsigned int which, Bool freeMap);
typedef Status tXkbGetState(
    Display* dpy,
    unsigned int deviceSpec,
    XkbStatePtr rtrnState);
typedef Bool tXkbSetMap(Display* dpy, unsigned int which, XkbDescPtr desc);
typedef Bool tXkbChangeMap(Display* dpy, XkbDescPtr desc, XkbMapChangesPtr changes);
typedef Bool tXkbSetDetectableAutoRepeat(
    Display* dpy,
    Bool detectable,
    Bool* supported);
typedef Bool tXkbGetDetectableAutoRepeat(Display* dpy, Bool* supported);
typedef Bool tXkbSetAutoResetControls(
    Display* dpy,
    unsigned int changes,
    unsigned int* auto_ctrls,
    unsigned int* auto_values);
typedef Bool tXkbGetAutoResetControls(
    Display* dpy,
    unsigned int* auto_ctrls,
    unsigned int* auto_ctrl_values);
typedef Bool tXkbSetPerClientControls(
    Display* dpy,
    unsigned int change,
    unsigned int* values);
typedef Bool tXkbGetPerClientControls(Display* dpy, unsigned int* ctrls);
typedef Status tXkbCopyKeyType(XkbKeyTypePtr from, XkbKeyTypePtr into);
typedef Status tXkbCopyKeyTypes(
    XkbKeyTypePtr from,
    XkbKeyTypePtr into,
    int num_types);
typedef Status tXkbResizeKeyType(
    XkbDescPtr xkb,
    int type_ndx,
    int map_count,
    Bool want_preserve,
    int new_num_lvls);
typedef KeySym* tXkbResizeKeySyms(XkbDescPtr desc, int forKey, int symsNeeded);
typedef XkbAction* tXkbResizeKeyActions(XkbDescPtr desc, int forKey, int actsNeeded);
typedef Status tXkbChangeTypesOfKey(
    XkbDescPtr xkb,
    int key,
    int num_groups,
    unsigned int groups,
    int* newTypes,
    XkbMapChangesPtr pChanges);
typedef Status tXkbChangeKeycodeRange(
    XkbDescPtr xkb,
    int minKC,
    int maxKC,
    XkbChangesPtr changes);
typedef XkbComponentListPtr tXkbListComponents(
    Display* dpy,
    unsigned int deviceSpec,
    XkbComponentNamesPtr ptrns,
    int* max_inout);
typedef void tXkbFreeComponentList(XkbComponentListPtr list);
typedef XkbDescPtr tXkbGetKeyboard(
    Display* dpy,
    unsigned int which,
    unsigned int deviceSpec);
typedef XkbDescPtr tXkbGetKeyboardByName(
    Display* dpy,
    unsigned int deviceSpec,
    XkbComponentNamesPtr names,
    unsigned int want,
    unsigned int need,
    Bool load);
typedef int tXkbKeyTypesForCoreSymbols(
    XkbDescPtr xkb,
    int map_width,
    KeySym* core_syms,
    unsigned int protected_,
    int* types_inout,
    KeySym* xkb_syms_rtrn);
typedef Bool tXkbApplyCompatMapToKey(
    XkbDescPtr xkb,
#if NeedWidePrototypes
    unsigned int key,
#else
    KeyCode key,
#endif
    XkbChangesPtr changes);
typedef Bool tXkbUpdateMapFromCore(
    XkbDescPtr xkb,
#if NeedWidePrototypes
    unsigned int first_key,
#else
    KeyCode first_key,
#endif
    int num_keys,
    int map_width,
    KeySym* core_keysyms,
    XkbChangesPtr changes);
typedef XkbDeviceLedInfoPtr tXkbAddDeviceLedInfo(
    XkbDeviceInfoPtr devi,
    unsigned int ledClass,
    unsigned int ledId);
typedef Status tXkbResizeDeviceButtonActions(
    XkbDeviceInfoPtr devi,
    unsigned int newTotal);
typedef XkbDeviceInfoPtr tXkbAllocDeviceInfo(
    unsigned int deviceSpec,
    unsigned int nButtons,
    unsigned int szLeds);
typedef void tXkbFreeDeviceInfo(
    XkbDeviceInfoPtr devi,
    unsigned int which,
    Bool freeDevI);
typedef void tXkbNoteDeviceChanges(
    XkbDeviceChangesPtr old,
    XkbExtensionDeviceNotifyEvent* new_,
    unsigned int wanted);
typedef XkbDeviceInfoPtr tXkbGetDeviceInfo(
    Display* dpy,
    unsigned int which,
    unsigned int deviceSpec,
    unsigned int ledClass,
    unsigned int ledID);
typedef Status tXkbGetDeviceInfoChanges(
    Display* dpy,
    XkbDeviceInfoPtr devi,
    XkbDeviceChangesPtr changes);
typedef Status tXkbGetDeviceButtonActions(
    Display* dpy,
    XkbDeviceInfoPtr devi,
    Bool all,
    unsigned int first,
    unsigned int nBtns);
typedef Status tXkbGetDeviceLedInfo(
    Display* dpy,
    XkbDeviceInfoPtr devi,
    unsigned int ledClass,
    unsigned int ledId,
    unsigned int which);
typedef Bool tXkbSetDeviceInfo(
    Display* dpy,
    unsigned int which,
    XkbDeviceInfoPtr devi);
typedef Bool tXkbChangeDeviceInfo(
    Display* dpy,
    XkbDeviceInfoPtr desc,
    XkbDeviceChangesPtr changes);
typedef Bool tXkbSetDeviceLedInfo(
    Display* dpy,
    XkbDeviceInfoPtr devi,
    unsigned int ledClass,
    unsigned int ledID,
    unsigned int which);
typedef Bool tXkbSetDeviceButtonActions(
    Display* dpy,
    XkbDeviceInfoPtr devi,
    unsigned int first,
    unsigned int nBtns);
typedef char tXkbToControl(char c);
typedef Bool tXkbSetDebuggingFlags(
    Display* dpy,
    unsigned int mask,
    unsigned int flags,
    char* msg,
    unsigned int ctrls_mask,
    unsigned int ctrls,
    unsigned int* rtrn_flags,
    unsigned int* rtrn_ctrls);
typedef Bool tXkbApplyVirtualModChanges(
    XkbDescPtr xkb,
    unsigned int changed,
    XkbChangesPtr changes);
typedef Bool tXkbUpdateActionVirtualMods(
    XkbDescPtr xkb,
    XkbAction* act,
    unsigned int changed);
typedef void tXkbUpdateKeyTypeVirtualMods(
    XkbDescPtr xkb,
    XkbKeyTypePtr type,
    unsigned int changed,
    XkbChangesPtr changes);

/* Function implementation declarations. */
extern tXkbIgnoreExtension *XkbIgnoreExtension_impl;
extern tXkbOpenDisplay *XkbOpenDisplay_impl;
extern tXkbQueryExtension *XkbQueryExtension_impl;
extern tXkbUseExtension *XkbUseExtension_impl;
extern tXkbLibraryVersion *XkbLibraryVersion_impl;
extern tXkbSetXlibControls *XkbSetXlibControls_impl;
extern tXkbGetXlibControls *XkbGetXlibControls_impl;
extern tXkbXlibControlsImplemented *XkbXlibControlsImplemented_impl;
extern tXkbSetAtomFuncs *XkbSetAtomFuncs_impl;
extern tXkbKeycodeToKeysym *XkbKeycodeToKeysym_impl;
extern tXkbKeysymToModifiers *XkbKeysymToModifiers_impl;
extern tXkbLookupKeySym *XkbLookupKeySym_impl;
extern tXkbLookupKeyBinding *XkbLookupKeyBinding_impl;
extern tXkbTranslateKeyCode *XkbTranslateKeyCode_impl;
extern tXkbTranslateKeySym *XkbTranslateKeySym_impl;
extern tXkbSetAutoRepeatRate *XkbSetAutoRepeatRate_impl;
extern tXkbGetAutoRepeatRate *XkbGetAutoRepeatRate_impl;
extern tXkbChangeEnabledControls *XkbChangeEnabledControls_impl;
extern tXkbDeviceBell *XkbDeviceBell_impl;
extern tXkbForceDeviceBell *XkbForceDeviceBell_impl;
extern tXkbDeviceBellEvent *XkbDeviceBellEvent_impl;
extern tXkbBell *XkbBell_impl;
extern tXkbForceBell *XkbForceBell_impl;
extern tXkbBellEvent *XkbBellEvent_impl;
extern tXkbSelectEvents *XkbSelectEvents_impl;
extern tXkbSelectEventDetails *XkbSelectEventDetails_impl;
extern tXkbNoteMapChanges *XkbNoteMapChanges_impl;
extern tXkbNoteNameChanges *XkbNoteNameChanges_impl;
extern tXkbGetIndicatorState *XkbGetIndicatorState_impl;
extern tXkbGetDeviceIndicatorState *XkbGetDeviceIndicatorState_impl;
extern tXkbGetIndicatorMap *XkbGetIndicatorMap_impl;
extern tXkbSetIndicatorMap *XkbSetIndicatorMap_impl;
extern tXkbGetNamedIndicator *XkbGetNamedIndicator_impl;
extern tXkbGetNamedDeviceIndicator *XkbGetNamedDeviceIndicator_impl;
extern tXkbSetNamedIndicator *XkbSetNamedIndicator_impl;
extern tXkbSetNamedDeviceIndicator *XkbSetNamedDeviceIndicator_impl;
extern tXkbLockModifiers *XkbLockModifiers_impl;
extern tXkbLatchModifiers *XkbLatchModifiers_impl;
extern tXkbLockGroup *XkbLockGroup_impl;
extern tXkbLatchGroup *XkbLatchGroup_impl;
extern tXkbSetServerInternalMods *XkbSetServerInternalMods_impl;
extern tXkbSetIgnoreLockMods *XkbSetIgnoreLockMods_impl;
extern tXkbVirtualModsToReal *XkbVirtualModsToReal_impl;
extern tXkbComputeEffectiveMap *XkbComputeEffectiveMap_impl;
extern tXkbInitCanonicalKeyTypes *XkbInitCanonicalKeyTypes_impl;
extern tXkbAllocKeyboard *XkbAllocKeyboard_impl;
extern tXkbFreeKeyboard *XkbFreeKeyboard_impl;
extern tXkbAllocClientMap *XkbAllocClientMap_impl;
extern tXkbAllocServerMap *XkbAllocServerMap_impl;
extern tXkbFreeClientMap *XkbFreeClientMap_impl;
extern tXkbFreeServerMap *XkbFreeServerMap_impl;
extern tXkbAddKeyType *XkbAddKeyType_impl;
extern tXkbAllocIndicatorMaps *XkbAllocIndicatorMaps_impl;
extern tXkbFreeIndicatorMaps *XkbFreeIndicatorMaps_impl;
extern tXkbGetMap *XkbGetMap_impl;
extern tXkbGetUpdatedMap *XkbGetUpdatedMap_impl;
extern tXkbGetMapChanges *XkbGetMapChanges_impl;
extern tXkbRefreshKeyboardMapping *XkbRefreshKeyboardMapping_impl;
extern tXkbGetKeyTypes *XkbGetKeyTypes_impl;
extern tXkbGetKeySyms *XkbGetKeySyms_impl;
extern tXkbGetKeyActions *XkbGetKeyActions_impl;
extern tXkbGetKeyBehaviors *XkbGetKeyBehaviors_impl;
extern tXkbGetVirtualMods *XkbGetVirtualMods_impl;
extern tXkbGetKeyExplicitComponents *XkbGetKeyExplicitComponents_impl;
extern tXkbGetKeyModifierMap *XkbGetKeyModifierMap_impl;
extern tXkbGetKeyVirtualModMap *XkbGetKeyVirtualModMap_impl;
extern tXkbAllocControls *XkbAllocControls_impl;
extern tXkbFreeControls *XkbFreeControls_impl;
extern tXkbGetControls *XkbGetControls_impl;
extern tXkbSetControls *XkbSetControls_impl;
extern tXkbNoteControlsChanges *XkbNoteControlsChanges_impl;
extern tXkbAllocCompatMap *XkbAllocCompatMap_impl;
extern tXkbFreeCompatMap *XkbFreeCompatMap_impl;
extern tXkbGetCompatMap *XkbGetCompatMap_impl;
extern tXkbSetCompatMap *XkbSetCompatMap_impl;
extern tXkbAddSymInterpret *XkbAddSymInterpret_impl;
extern tXkbAllocNames *XkbAllocNames_impl;
extern tXkbGetNames *XkbGetNames_impl;
extern tXkbSetNames *XkbSetNames_impl;
extern tXkbChangeNames *XkbChangeNames_impl;
extern tXkbFreeNames *XkbFreeNames_impl;
extern tXkbGetState *XkbGetState_impl;
extern tXkbSetMap *XkbSetMap_impl;
extern tXkbChangeMap *XkbChangeMap_impl;
extern tXkbSetDetectableAutoRepeat *XkbSetDetectableAutoRepeat_impl;
extern tXkbGetDetectableAutoRepeat *XkbGetDetectableAutoRepeat_impl;
extern tXkbSetAutoResetControls *XkbSetAutoResetControls_impl;
extern tXkbGetAutoResetControls *XkbGetAutoResetControls_impl;
extern tXkbSetPerClientControls *XkbSetPerClientControls_impl;
extern tXkbGetPerClientControls *XkbGetPerClientControls_impl;
extern tXkbCopyKeyType *XkbCopyKeyType_impl;
extern tXkbCopyKeyTypes *XkbCopyKeyTypes_impl;
extern tXkbResizeKeyType *XkbResizeKeyType_impl;
extern tXkbResizeKeySyms *XkbResizeKeySyms_impl;
extern tXkbResizeKeyActions *XkbResizeKeyActions_impl;
extern tXkbChangeTypesOfKey *XkbChangeTypesOfKey_impl;
extern tXkbChangeKeycodeRange *XkbChangeKeycodeRange_impl;
extern tXkbListComponents *XkbListComponents_impl;
extern tXkbFreeComponentList *XkbFreeComponentList_impl;
extern tXkbGetKeyboard *XkbGetKeyboard_impl;
extern tXkbGetKeyboardByName *XkbGetKeyboardByName_impl;
extern tXkbKeyTypesForCoreSymbols *XkbKeyTypesForCoreSymbols_impl;
extern tXkbApplyCompatMapToKey *XkbApplyCompatMapToKey_impl;
extern tXkbUpdateMapFromCore *XkbUpdateMapFromCore_impl;
extern tXkbAddDeviceLedInfo *XkbAddDeviceLedInfo_impl;
extern tXkbResizeDeviceButtonActions *XkbResizeDeviceButtonActions_impl;
extern tXkbAllocDeviceInfo *XkbAllocDeviceInfo_impl;
extern tXkbFreeDeviceInfo *XkbFreeDeviceInfo_impl;
extern tXkbNoteDeviceChanges *XkbNoteDeviceChanges_impl;
extern tXkbGetDeviceInfo *XkbGetDeviceInfo_impl;
extern tXkbGetDeviceInfoChanges *XkbGetDeviceInfoChanges_impl;
extern tXkbGetDeviceButtonActions *XkbGetDeviceButtonActions_impl;
extern tXkbGetDeviceLedInfo *XkbGetDeviceLedInfo_impl;
extern tXkbSetDeviceInfo *XkbSetDeviceInfo_impl;
extern tXkbChangeDeviceInfo *XkbChangeDeviceInfo_impl;
extern tXkbSetDeviceLedInfo *XkbSetDeviceLedInfo_impl;
extern tXkbSetDeviceButtonActions *XkbSetDeviceButtonActions_impl;
extern tXkbToControl *XkbToControl_impl;
extern tXkbSetDebuggingFlags *XkbSetDebuggingFlags_impl;
extern tXkbApplyVirtualModChanges *XkbApplyVirtualModChanges_impl;
extern tXkbUpdateActionVirtualMods *XkbUpdateActionVirtualMods_impl;
extern tXkbUpdateKeyTypeVirtualMods *XkbUpdateKeyTypeVirtualMods_impl;

/* Private methods, only used by wrangler. */
int __x11ew_init_xkblib(void);
void __x11ew_exit_xkblib(void);

#ifdef __cplusplus
}
#endif

#endif  /* __X11EW_XKBLIB_H__ */
