#pragma once
/*
 *      Copyright (C) 2005-2011 Team XBMC
 *      http://www.xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, write to
 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *  http://www.gnu.org/copyleft/gpl.html
 *
 */

#include "cores/dvdplayer/DVDDemuxers/DVDDemuxUtils.h"
#include "addons/include/xbmc_pvr_types.h"
#include "../../addons/library.xbmc.addon/libXBMC_addon.h"
#include "../../addons/library.xbmc.gui/libXBMC_gui.h"

typedef void (*AddOnLogCallback)(void *addonData, const ADDON::addon_log_t loglevel, const char *msg);
typedef void (*AddOnQueueNotification)(void *addonData, const ADDON::queue_msg_t type, const char *msg);
typedef bool (*AddOnGetSetting)(void *addonData, const char *settingName, void *settingValue);
typedef char* (*AddOnUnknownToUTF8)(const char *sourceDest);
typedef const char* (*AddOnGetLocalizedString)(const void* addonData, long dwCode);
typedef const char* (*AddOnGetDVDMenuLanguage)(const void* addonData);

typedef struct CB_AddOn
{
  AddOnLogCallback        Log;
  AddOnQueueNotification  QueueNotification;
  AddOnGetSetting         GetSetting;
  AddOnUnknownToUTF8      UnknownToUTF8;
  AddOnGetLocalizedString GetLocalizedString;
  AddOnGetDVDMenuLanguage GetDVDMenuLanguage;
} CB_AddOnLib;

typedef void (*GUILock)();
typedef void (*GUIUnlock)();
typedef int (*GUIGetScreenHeight)();
typedef int (*GUIGetScreenWidth)();
typedef int (*GUIGetVideoResolution)();
typedef GUIHANDLE   (*GUIWindow_New)(void *addonData, const char *xmlFilename, const char *defaultSkin, bool forceFallback, bool asDialog);
typedef void        (*GUIWindow_Delete)(void *addonData, GUIHANDLE handle);
typedef void        (*GUIWindow_SetCallbacks)(void *addonData, GUIHANDLE handle, GUIHANDLE clienthandle, bool (*)(GUIHANDLE handle), bool (*)(GUIHANDLE handle, int), bool (*)(GUIHANDLE handle, int), bool (*)(GUIHANDLE handle, int));
typedef bool        (*GUIWindow_Show)(void *addonData, GUIHANDLE handle);
typedef bool        (*GUIWindow_Close)(void *addonData, GUIHANDLE handle);
typedef bool        (*GUIWindow_DoModal)(void *addonData, GUIHANDLE handle);
typedef bool        (*GUIWindow_SetFocusId)(void *addonData, GUIHANDLE handle, int iControlId);
typedef int         (*GUIWindow_GetFocusId)(void *addonData, GUIHANDLE handle);
typedef bool        (*GUIWindow_SetCoordinateResolution)(void *addonData, GUIHANDLE handle, int res);
typedef void        (*GUIWindow_SetProperty)(void *addonData, GUIHANDLE handle, const char *key, const char *value);
typedef void        (*GUIWindow_SetPropertyInt)(void *addonData, GUIHANDLE handle, const char *key, int value);
typedef void        (*GUIWindow_SetPropertyBool)(void *addonData, GUIHANDLE handle, const char *key, bool value);
typedef void        (*GUIWindow_SetPropertyDouble)(void *addonData, GUIHANDLE handle, const char *key, double value);
typedef const char* (*GUIWindow_GetProperty)(void *addonData, GUIHANDLE handle, const char *key);
typedef int         (*GUIWindow_GetPropertyInt)(void *addonData, GUIHANDLE handle, const char *key);
typedef bool        (*GUIWindow_GetPropertyBool)(void *addonData, GUIHANDLE handle, const char *key);
typedef double      (*GUIWindow_GetPropertyDouble)(void *addonData, GUIHANDLE handle, const char *key);
typedef void        (*GUIWindow_ClearProperties)(void *addonData, GUIHANDLE handle);
typedef int         (*GUIWindow_GetListSize)(void *addonData, GUIHANDLE handle);
typedef void        (*GUIWindow_ClearList)(void *addonData, GUIHANDLE handle);
typedef GUIHANDLE   (*GUIWindow_AddItem)(void *addonData, GUIHANDLE handle, GUIHANDLE item, int itemPosition);
typedef GUIHANDLE   (*GUIWindow_AddStringItem)(void *addonData, GUIHANDLE handle, const char *itemName, int itemPosition);
typedef void        (*GUIWindow_RemoveItem)(void *addonData, GUIHANDLE handle, int itemPosition);
typedef GUIHANDLE   (*GUIWindow_GetListItem)(void *addonData, GUIHANDLE handle, int listPos);
typedef void        (*GUIWindow_SetCurrentListPosition)(void *addonData, GUIHANDLE handle, int listPos);
typedef int         (*GUIWindow_GetCurrentListPosition)(void *addonData, GUIHANDLE handle);
typedef GUIHANDLE   (*GUIWindow_GetControl_Spin)(void *addonData, GUIHANDLE handle, int controlId);
typedef GUIHANDLE   (*GUIWindow_GetControl_Button)(void *addonData, GUIHANDLE handle, int controlId);
typedef GUIHANDLE   (*GUIWindow_GetControl_RadioButton)(void *addonData, GUIHANDLE handle, int controlId);
typedef GUIHANDLE   (*GUIWindow_GetControl_Edit)(void *addonData, GUIHANDLE handle, int controlId);
typedef GUIHANDLE   (*GUIWindow_GetControl_Progress)(void *addonData, GUIHANDLE handle, int controlId);
typedef void        (*GUIWindow_SetControlLabel)(void *addonData, GUIHANDLE handle, int controlId, const char *label);
typedef void        (*GUIControl_Spin_SetVisible)(void *addonData, GUIHANDLE spinhandle, bool yesNo);
typedef void        (*GUIControl_Spin_SetText)(void *addonData, GUIHANDLE spinhandle, const char *label);
typedef void        (*GUIControl_Spin_Clear)(void *addonData, GUIHANDLE spinhandle);
typedef void        (*GUIControl_Spin_AddLabel)(void *addonData, GUIHANDLE spinhandle, const char *label, int iValue);
typedef int         (*GUIControl_Spin_GetValue)(void *addonData, GUIHANDLE spinhandle);
typedef void        (*GUIControl_Spin_SetValue)(void *addonData, GUIHANDLE spinhandle, int iValue);
typedef void        (*GUIControl_RadioButton_SetVisible)(void *addonData, GUIHANDLE handle, bool yesNo);
typedef void        (*GUIControl_RadioButton_SetText)(void *addonData, GUIHANDLE handle, const char *label);
typedef void        (*GUIControl_RadioButton_SetSelected)(void *addonData, GUIHANDLE handle, bool yesNo);
typedef bool        (*GUIControl_RadioButton_IsSelected)(void *addonData, GUIHANDLE handle);
typedef void        (*GUIControl_Progress_SetPercentage)(void *addonData, GUIHANDLE handle, float fPercent);
typedef float       (*GUIControl_Progress_GetPercentage)(void *addonData, GUIHANDLE handle);
typedef void        (*GUIControl_Progress_SetInfo)(void *addonData, GUIHANDLE handle, int iInfo);
typedef int         (*GUIControl_Progress_GetInfo)(void *addonData, GUIHANDLE handle);
typedef const char* (*GUIControl_Progress_GetDescription)(void *addonData, GUIHANDLE handle);
typedef GUIHANDLE   (*GUIListItem_Create)(void *addonData, const char *label, const char *label2, const char *iconImage, const char *thumbnailImage, const char *path);
typedef const char* (*GUIListItem_GetLabel)(void *addonData, GUIHANDLE handle);
typedef void        (*GUIListItem_SetLabel)(void *addonData, GUIHANDLE handle, const char *label);
typedef const char* (*GUIListItem_GetLabel2)(void *addonData, GUIHANDLE handle);
typedef void        (*GUIListItem_SetLabel2)(void *addonData, GUIHANDLE handle, const char *label);
typedef void        (*GUIListItem_SetIconImage)(void *addonData, GUIHANDLE handle, const char *image);
typedef void        (*GUIListItem_SetThumbnailImage)(void *addonData, GUIHANDLE handle, const char *image);
typedef void        (*GUIListItem_SetInfo)(void *addonData, GUIHANDLE handle, const char *info);
typedef void        (*GUIListItem_SetProperty)(void *addonData, GUIHANDLE handle, const char *key, const char *value);
typedef const char* (*GUIListItem_GetProperty)(void *addonData, GUIHANDLE handle, const char *key);
typedef void        (*GUIListItem_SetPath)(void *addonData, GUIHANDLE handle, const char *path);

typedef struct CB_GUILib
{
  GUILock                             Lock;
  GUIUnlock                           Unlock;
  GUIGetScreenHeight                  GetScreenHeight;
  GUIGetScreenWidth                   GetScreenWidth;
  GUIGetVideoResolution               GetVideoResolution;
  GUIWindow_New                       Window_New;
  GUIWindow_Delete                    Window_Delete;
  GUIWindow_SetCallbacks              Window_SetCallbacks;
  GUIWindow_Show                      Window_Show;
  GUIWindow_Close                     Window_Close;
  GUIWindow_DoModal                   Window_DoModal;
  GUIWindow_SetFocusId                Window_SetFocusId;
  GUIWindow_GetFocusId                Window_GetFocusId;
  GUIWindow_SetCoordinateResolution   Window_SetCoordinateResolution;
  GUIWindow_SetProperty               Window_SetProperty;
  GUIWindow_SetPropertyInt            Window_SetPropertyInt;
  GUIWindow_SetPropertyBool           Window_SetPropertyBool;
  GUIWindow_SetPropertyDouble         Window_SetPropertyDouble;
  GUIWindow_GetProperty               Window_GetProperty;
  GUIWindow_GetPropertyInt            Window_GetPropertyInt;
  GUIWindow_GetPropertyBool           Window_GetPropertyBool;
  GUIWindow_GetPropertyDouble         Window_GetPropertyDouble;
  GUIWindow_ClearProperties           Window_ClearProperties;
  GUIWindow_GetListSize               Window_GetListSize;
  GUIWindow_ClearList                 Window_ClearList;
  GUIWindow_AddItem                   Window_AddItem;
  GUIWindow_AddStringItem             Window_AddStringItem;
  GUIWindow_RemoveItem                Window_RemoveItem;
  GUIWindow_GetListItem               Window_GetListItem;
  GUIWindow_SetCurrentListPosition    Window_SetCurrentListPosition;
  GUIWindow_GetCurrentListPosition    Window_GetCurrentListPosition;
  GUIWindow_GetControl_Spin           Window_GetControl_Spin;
  GUIWindow_GetControl_Button         Window_GetControl_Button;
  GUIWindow_GetControl_RadioButton    Window_GetControl_RadioButton;
  GUIWindow_GetControl_Edit           Window_GetControl_Edit;
  GUIWindow_GetControl_Progress       Window_GetControl_Progress;
  GUIWindow_SetControlLabel           Window_SetControlLabel;
  GUIControl_Spin_SetVisible          Control_Spin_SetVisible;
  GUIControl_Spin_SetText             Control_Spin_SetText;
  GUIControl_Spin_Clear               Control_Spin_Clear;
  GUIControl_Spin_AddLabel            Control_Spin_AddLabel;
  GUIControl_Spin_GetValue            Control_Spin_GetValue;
  GUIControl_Spin_SetValue            Control_Spin_SetValue;
  GUIControl_RadioButton_SetVisible   Control_RadioButton_SetVisible;
  GUIControl_RadioButton_SetText      Control_RadioButton_SetText;
  GUIControl_RadioButton_SetSelected  Control_RadioButton_SetSelected;
  GUIControl_RadioButton_IsSelected   Control_RadioButton_IsSelected;
  GUIControl_Progress_SetPercentage   Control_Progress_SetPercentage;
  GUIControl_Progress_GetPercentage   Control_Progress_GetPercentage;
  GUIControl_Progress_SetInfo         Control_Progress_SetInfo;
  GUIControl_Progress_GetInfo         Control_Progress_GetInfo;
  GUIControl_Progress_GetDescription  Control_Progress_GetDescription;
  GUIListItem_Create                  ListItem_Create;
  GUIListItem_GetLabel                ListItem_GetLabel;
  GUIListItem_SetLabel                ListItem_SetLabel;
  GUIListItem_GetLabel2               ListItem_GetLabel2;
  GUIListItem_SetLabel2               ListItem_SetLabel2;
  GUIListItem_SetIconImage            ListItem_SetIconImage;
  GUIListItem_SetThumbnailImage       ListItem_SetThumbnailImage;
  GUIListItem_SetInfo                 ListItem_SetInfo;
  GUIListItem_SetProperty             ListItem_SetProperty;
  GUIListItem_GetProperty             ListItem_GetProperty;
  GUIListItem_SetPath                 ListItem_SetPath;

} CB_GUILib;

typedef void (*PVRTransferEpgEntry)(void *userData, const PVR_HANDLE handle, const EPG_TAG *epgentry);
typedef void (*PVRTransferChannelEntry)(void *userData, const PVR_HANDLE handle, const PVR_CHANNEL *chan);
typedef void (*PVRTransferTimerEntry)(void *userData, const PVR_HANDLE handle, const PVR_TIMER *timer);
typedef void (*PVRTransferRecordingEntry)(void *userData, const PVR_HANDLE handle, const PVR_RECORDING *recording);
typedef void (*PVRAddMenuHook)(void *addonData, PVR_MENUHOOK *hook);
typedef void (*PVRRecording)(void *addonData, const char *Name, const char *FileName, bool On);
typedef void (*PVRTriggerChannelUpdate)(void *addonData);
typedef void (*PVRTriggerTimerUpdate)(void *addonData);
typedef void (*PVRTriggerRecordingUpdate)(void *addonData);
typedef void (*PVRTriggerChannelGroupsUpdate)(void *addonData);

typedef void (*PVRTransferChannelGroup)(void *addonData, const PVR_HANDLE handle, const PVR_CHANNEL_GROUP *group);
typedef void (*PVRTransferChannelGroupMember)(void *addonData, const PVR_HANDLE handle, const PVR_CHANNEL_GROUP_MEMBER *member);

typedef void (*PVRFreeDemuxPacket)(void *addonData, DemuxPacket* pPacket);
typedef DemuxPacket* (*PVRAllocateDemuxPacket)(void *addonData, int iDataSize);

typedef struct CB_PVRLib
{
  PVRTransferEpgEntry           TransferEpgEntry;
  PVRTransferChannelEntry       TransferChannelEntry;
  PVRTransferTimerEntry         TransferTimerEntry;
  PVRTransferRecordingEntry     TransferRecordingEntry;
  PVRAddMenuHook                AddMenuHook;
  PVRRecording                  Recording;
  PVRTriggerChannelUpdate       TriggerChannelUpdate;
  PVRTriggerTimerUpdate         TriggerTimerUpdate;
  PVRTriggerRecordingUpdate     TriggerRecordingUpdate;
  PVRTriggerChannelGroupsUpdate TriggerChannelGroupsUpdate;
  PVRFreeDemuxPacket            FreeDemuxPacket;
  PVRAllocateDemuxPacket        AllocateDemuxPacket;
  PVRTransferChannelGroup       TransferChannelGroup;
  PVRTransferChannelGroupMember TransferChannelGroupMember;

} CB_PVRLib;


typedef CB_AddOnLib* (*XBMCAddOnLib_RegisterMe)(void *addonData);
typedef void (*XBMCAddOnLib_UnRegisterMe)(void *addonData, CB_AddOnLib *cbTable);
typedef CB_GUILib* (*XBMCGUILib_RegisterMe)(void *addonData);
typedef void (*XBMCGUILib_UnRegisterMe)(void *addonData, CB_GUILib *cbTable);
typedef CB_PVRLib* (*XBMCPVRLib_RegisterMe)(void *addonData);
typedef void (*XBMCPVRLib_UnRegisterMe)(void *addonData, CB_PVRLib *cbTable);

typedef struct AddonCB
{
  char                      *libBasePath;                  ///> Never, never change this!!!
  void                      *addonData;
  XBMCAddOnLib_RegisterMe    AddOnLib_RegisterMe;
  XBMCAddOnLib_UnRegisterMe  AddOnLib_UnRegisterMe;
  XBMCGUILib_RegisterMe      GUILib_RegisterMe;
  XBMCGUILib_UnRegisterMe    GUILib_UnRegisterMe;
  XBMCPVRLib_RegisterMe      PVRLib_RegisterMe;
  XBMCPVRLib_UnRegisterMe    PVRLib_UnRegisterMe;
} AddonCB;


namespace ADDON
{

class CAddon;
class CAddonCallbacksAddon;
class CAddonCallbacksGUI;
class CAddonCallbacksPVR;

class CAddonCallbacks
{
public:
  CAddonCallbacks(CAddon* addon);
  ~CAddonCallbacks();
  AddonCB *GetCallbacks() { return m_callbacks; }

  static CB_AddOnLib* AddOnLib_RegisterMe(void *addonData);
  static void AddOnLib_UnRegisterMe(void *addonData, CB_AddOnLib *cbTable);
  static CB_GUILib* GUILib_RegisterMe(void *addonData);
  static void GUILib_UnRegisterMe(void *addonData, CB_GUILib *cbTable);
  static CB_PVRLib* PVRLib_RegisterMe(void *addonData);
  static void PVRLib_UnRegisterMe(void *addonData, CB_PVRLib *cbTable);

  CAddonCallbacksAddon *GetHelperAddon() { return m_helperAddon; }
  CAddonCallbacksGUI *GetHelperGUI() { return m_helperGUI; }
  CAddonCallbacksPVR *GetHelperPVR() { return m_helperPVR; }

private:
  AddonCB             *m_callbacks;
  CAddon              *m_addon;
  CAddonCallbacksAddon *m_helperAddon;
  CAddonCallbacksGUI   *m_helperGUI;
  CAddonCallbacksPVR   *m_helperPVR;
};

}; /* namespace ADDON */
