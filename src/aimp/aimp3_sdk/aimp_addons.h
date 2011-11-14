#ifndef AIMP3_SDK_ADDONS_H
#define AIMP3_SDK_ADDONS_H

/* 
    AIMP SDK is ported by Alexey Ivanov, 2011
    Email: ivanbl4.geeks@gmail.com
*/
//{************************************************}
//{*                                              *}
//{*            AIMP Addons Plugins  API          *}
//{*             v3.00.923 (18.09.2011)           *}
//{*                                              *}
//{*              (c) Artem Izmaylov              *}
//{*                 www.aimp.ru                  *}
//{*             Mail: artem@aimp.ru              *}
//{*              ICQ: 345-908-513                *}
//{*                                              *}
//{************************************************}

#include <windows.h>
#include <unknwn.h>

#include <ObjBase.h>
#include <InitGuid.h> // need to force macro DEFINE_GUID to define guid instead declare. 
#include "aimp_core.h"

namespace AIMP3SDK
{

const int WM_AIMP_LANG_CHANGED = WM_USER + 101;

// IAIMPAddonPlugin.GetPluginFlags
const int AIMP_ADDON_FLAGS_HAS_DIALOG = 1;

// TAIMPMenuItemInfo.Flags
const int AIMP_MENUITEM_CHECKBOX   = 1;
const int AIMP_MENUITEM_CHECKED    = 2;
const int AIMP_MENUITEM_ENABLED    = 4;
const int AIMP_MENUITEM_RADIOITEM  = 8;

// IAIMPAddonsMenuManager.MenuCreate, MenuIDs
const int AIMP_MENUID_MAIN_OPTIONS   = 0;
const int AIMP_MENUID_MAIN_FUNCTION  = 2;
const int AIMP_MENUID_MAIN_CONFIGS   = 3;
const int AIMP_MENUID_UTILITIES      = 4;
const int AIMP_MENUID_PLS_ADD        = 5;
const int AIMP_MENUID_PLS_JUMP       = 6;
const int AIMP_MENUID_PLS_FNC        = 7;
const int AIMP_MENUID_PLS_SEND       = 8;
const int AIMP_MENUID_PLS_DEL        = 9;
const int AIMP_MENUID_ADD            = 10;
const int AIMP_MENUID_DEL            = 11;
const int AIMP_MENUID_SORT           = 13;
const int AIMP_MENUID_MISC           = 14;
const int AIMP_MENUID_PLS            = 15;
const int AIMP_MENUID_TRAY           = 17;
const int AIMP_MENUID_EQ_LIB         = 18;

// PropertyIDs for IAIMPAddonsPlaylistManager.EntryPropertyGetValue / EntryPropertySetValue
const int AIMP_PLAYLIST_ENTRY_PROPERTY_DISPLAYTEXT                = 0;  // READONLY! ABuffer: Pointer to array of WideChar, ABufferSize: size of array in Bytes
const int AIMP_PLAYLIST_ENTRY_PROPERTY_FILENAME                   = 1;  // ABuffer: Pointer to array of WideChar, ABufferSize: size of array in Bytes
const int AIMP_PLAYLIST_ENTRY_PROPERTY_INFO                       = 2;  // ABuffer: Pointer to TAIMPFileInfo, ABufferSize: size of TAIMPFileInfo structure
const int AIMP_PLAYLIST_ENTRY_PROPERTY_PLAYINGSWITCH              = 3;  // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_ENTRY_PROPERTY_STATISTICS                 = 4;  // READONLY! ABuffer: Pointer to TAIMPFileStatisticsInfo, ABufferSize: size of TAIMPFileStatisticsInfo structure
const int AIMP_PLAYLIST_ENTRY_PROPERTY_MARK                       = 5;  // ABuffer: Pointer to Integer, ABufferSize: SizeOf(Integer)
const int AIMP_PLAYLIST_ENTRY_PROPERTY_INDEX                      = 6;  // ABuffer: Pointer to Integer, ABufferSize: SizeOf(Integer)
const int AIMP_PLAYLIST_ENTRY_PROPERTY_SELECTED                   = 7;  // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)

// PropertyIDs for IAIMPAddonsPlaylistManager.StoragePropertyGetValue / StoragePropertySetValue
const int AIMP_PLAYLIST_STORAGE_PROPERTY_NAME                     = 0;  // ABuffer: Pointer to array of WideChar, ABufferSize: size of array in Bytes
const int AIMP_PLAYLIST_STORAGE_PROPERTY_READONLY                 = 1;  // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_GROUPPING                = 10; // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_GROUPPING_OVERRIDEN      = 11; // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_GROUPPING_TEMPLATE       = 12; // ABuffer: Pointer to array of WideChar, ABufferSize: size of array in Bytes
const int AIMP_PLAYLIST_STORAGE_PROPERTY_GROUPPING_AUTOMERGING    = 13; // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_FORMATING_OVERRIDEN      = 20; // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_FORMATING_LINE1_TEMPLATE = 21; // ABuffer: Pointer to array of WideChar, ABufferSize: size of array in Bytes
const int AIMP_PLAYLIST_STORAGE_PROPERTY_FORMATING_LINE2_TEMPLATE = 22; // ABuffer: Pointer to array of WideChar, ABufferSize: size of array in Bytes
const int AIMP_PLAYLIST_STORAGE_PROPERTY_VIEW_OVERRIDEN           = 30; // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_VIEW_DURATION            = 31; // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_VIEW_EXPAND_BUTTONS      = 32; // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_VIEW_MARKS               = 33; // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_VIEW_NUMBERS             = 34; // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_VIEW_NUMBERS_ABSOLUTE    = 35; // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_VIEW_SECOND_LINE         = 36; // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_VIEW_SWITCHES            = 37; // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_FOCUSINDEX               = 50; // ABuffer: Pointer to Integer, ABufferSize: SizeOf(Integer)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_TRACKINGINDEX            = 51; // ABuffer: Pointer to Integer, ABufferSize: SizeOf(Integer)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_DURATION                 = 52; // READONLY! ABuffer: Pointer to Int64 (64-bit Integer), ABufferSize: SizeOf(Int64)
const int AIMP_PLAYLIST_STORAGE_PROPERTY_SIZE                     = 53; // READONLY! ABuffer: Pointer to Int64 (64-bit Integer), ABufferSize: SizeOf(Int64)

// IAIMPAddonsPlaylistManager.StorageSort
const int AIMP_PLAYLIST_SORT_TYPE_TITLE      = 1;
const int AIMP_PLAYLIST_SORT_TYPE_FILENAME   = 2;
const int AIMP_PLAYLIST_SORT_TYPE_DURATION   = 3;
const int AIMP_PLAYLIST_SORT_TYPE_ARTIST     = 4;
const int AIMP_PLAYLIST_SORT_TYPE_INVERSE    = 5;
const int AIMP_PLAYLIST_SORT_TYPE_RANDOMIZE  = 6;

// IAIMPAddonsPlaylistManager.StorageGetFiles:
const int AIMP_PLAYLIST_GETFILES_VISIBLE  = 1; // Files from collapsed groups will be excluded from list
const int AIMP_PLAYLIST_GETFILES_SELECTED = 2; // Only selected files will be processed

// IAIMPAddonsPlaylistManager.FormatString Flags
const int AIMP_PLAYLIST_FORMAT_MODE_PREVIEW  = 1;
const int AIMP_PLAYLIST_FORMAT_MODE_FILEINFO = 2;
const int AIMP_PLAYLIST_FORMAT_MODE_CURRENT  = 3;

// PropertyIDs for IAIMPAddonsPlaylistManager.GroupPropertyGetValue / GroupPropertySetValue
const int AIMP_PLAYLIST_GROUP_PROPERTY_NAME                       = 0;  // READONLY! ABuffer: Pointer to array of WideChar, ABufferSize: size of array in Bytes
const int AIMP_PLAYLIST_GROUP_PROPERTY_EXPANDED                   = 1;  // ABuffer: Pointer to LongBool (32-bit Boolean), ABufferSize: SizeOf(LongBool)
const int AIMP_PLAYLIST_GROUP_PROPERTY_DURATION                   = 2;  // READONLY! ABuffer: Pointer to Int64 (64-bit Integer), ABufferSize: SizeOf(Int64)

// Flags for IAIMPAddonsPlaylistManagerListener.StorageChanged
const int AIMP_PLAYLIST_NOTIFY_NAME           = 1;
const int AIMP_PLAYLIST_NOTIFY_SELECTION      = 2;
const int AIMP_PLAYLIST_NOTIFY_TRACKINGINDEX  = 4;
const int AIMP_PLAYLIST_NOTIFY_PLAYINDEX      = 8;
const int AIMP_PLAYLIST_NOTIFY_FOCUSINDEX     = 16;
const int AIMP_PLAYLIST_NOTIFY_CONTENT        = 32;
const int AIMP_PLAYLIST_NOTIFY_ENTRYINFO      = 64;
const int AIMP_PLAYLIST_NOTIFY_STATISTICS     = 128;
const int AIMP_PLAYLIST_NOTIFY_PLAYINGSWITCHS = 256;

// AConfigPathIDs for IAIMPAddonsPlayerManager.ConfigGetPath
const int AIMP_CFG_PATH_PROFILE  = 0;
const int AIMP_CFG_PATH_PLS      = 1;
const int AIMP_CFG_PATH_LNG      = 2;
const int AIMP_CFG_PATH_SKINS    = 3;
const int AIMP_CFG_PATH_PLUGINS  = 4;
const int AIMP_CFG_PATH_ICONS    = 5;
const int AIMP_CFG_PATH_ML       = 6;
const int AIMP_CFG_PATH_MODULES  = 8;
const int AIMP_CFG_PATH_HELP     = 9;
const int AIMP_CFG_PATH_ML_PLS   = 10;

// AFlags for IAIMPAddonsPlayerManager.SupportsExts
const int AIMP_SUPPORTS_EXTS_FORMAT_AUDIO    = 2;
const int AIMP_SUPPORTS_EXTS_FORMAT_PLAYLIST = 1;

DEFINE_GUID(SID_IAIMPAddonsConfigFile,              0x41494D50, 0x0033, 0x434F, 0x52, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10);
DEFINE_GUID(SID_IAIMPAddonsCoverArtManager,         0x41494D50, 0x0033, 0x434F, 0x52, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11);
DEFINE_GUID(SID_IAIMPAddonsLanguageFile,            0x41494D50, 0x0033, 0x434F, 0x52, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12);
DEFINE_GUID(SID_IAIMPAddonsMenuManager,             0x41494D50, 0x0033, 0x434F, 0x52, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13);
DEFINE_GUID(SID_IAIMPAddonsOptionsDialog,           0x41494D50, 0x0033, 0x434F, 0x52, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14);
DEFINE_GUID(SID_IAIMPAddonsPlayerManager,           0x41494D50, 0x0033, 0x434F, 0x52, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15);
DEFINE_GUID(SID_IAIMPAddonsPlaylistManager,         0x41494D50, 0x0033, 0x434F, 0x52, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x16);
DEFINE_GUID(SID_IAIMPAddonsPlaylistManagerListener, 0x41494D50, 0x0033, 0x434F, 0x52, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17);
DEFINE_GUID(SID_IAIMPAddonsPlaylistStrings,         0x41494D50, 0x0033, 0x434F, 0x52, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18);
DEFINE_GUID(SID_IAIMPAddonsSkinsManager,            0x41494D50, 0x0033, 0x434F, 0x52, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19);

typedef Pointer HPLS;
typedef Pointer HPLSENTRY;
typedef Pointer HPLSGROUP;
typedef Pointer HAIMPMENU;

// Universal Handle for Active Playlist
const HPLS ActivePlaylistHandle = (HPLS)-1;

typedef void (WINAPI *TAIMPMenuProc)(Pointer UserData, HAIMPMENU Handle);

#pragma pack(push, 1)
struct TAIMPMenuItemInfo
{
    DWORD StructSize; // SizeOf(TAIMPMenuItemInfo)
    HBITMAP Bitmap;   // 0 - no glyph
    PWideChar Caption;
    DWORD Flags;   // Combination of AIMP_MENUITEM_XXX flags
    TAIMPMenuProc Proc;
    DWORD ShortCut;
    Pointer UserData;
};
#pragma pack(pop)

typedef TAIMPMenuItemInfo* PAIMPMenuItemInfo;

#pragma pack(push, 1)
struct TAIMPFileInfo
{
    DWORD StructSize; // SizeOf(TAIMPFileInfo)
    //
    LongBool Active;
    DWORD BitRate;
    DWORD Channels;
    DWORD Duration;
    Int64 FileSize;
    DWORD Mark;
    DWORD SampleRate;
    DWORD TrackNumber;
    //
    DWORD AlbumLength;
    DWORD ArtistLength;
    DWORD DateLength;
    DWORD FileNameLength;
    DWORD GenreLength;
    DWORD TitleLength;
    //
    PWideChar Album;
    PWideChar Artist;
    PWideChar Date;
    PWideChar FileName;
    PWideChar Genre;
    PWideChar Title;
};
#pragma pack(pop)

typedef TAIMPFileInfo* PAIMPFileInfo;

#pragma pack(push, 1)
struct TAIMPFileStatisticsInfo
{
    Integer Mark;
    TDateTime AddDate;
    Integer PlayCount;
    TDateTime PlayDate; // Details of TDateTime see at http://www.delphibasics.co.uk/RTL.asp?Name=TDateTime
};
#pragma pack(pop)

typedef TAIMPFileStatisticsInfo* PAIMPFileStatisticsInfo;

#pragma pack(push, 1)
struct TAIMPSkinInfo 
{
    DWORD StructSize; // SizeOf(TAIMPSkinInfo)
    PWideChar AuthorBuffer;
    DWORD AuthorBufferLength;
    PWideChar InfoBuffer;
    DWORD InfoBufferLength;
    PWideChar NameBuffer;
    DWORD NameBufferLength;
    HBITMAP Preview;
};
#pragma pack(pop)

typedef TAIMPSkinInfo* PAIMPSkinInfo;

typedef Integer (WINAPI *TAIMPAddonsPlaylistManagerCompareProc)(PAIMPFileInfo AFileInfo1, PAIMPFileInfo AFileInfo2, Pointer AUserData);
typedef LongBool (WINAPI *TAIMPAddonsPlaylistManagerDeleteProc)(PAIMPFileInfo AFileInfo, Pointer AUserData);

// Must be implemented by Plugin
class IAIMPAddonsOptionsDialogFrame : public IUnknown
{
public:
    virtual HWND WINAPI FrameCreate(HWND AParentWindow) = 0;
    virtual Pointer WINAPI FrameData() = 0; // unused
    virtual Integer WINAPI FrameFlags() = 0; // unused
    virtual PWideChar WINAPI FrameName() = 0;
    virtual void WINAPI FrameFree(HWND AWindow) = 0;
    virtual void WINAPI FrameLoadConfigNotify() = 0;
    virtual void WINAPI FrameSaveConfigNotify() = 0;
};

class IAIMPAddonsOptionsDialog : public IUnknown
{
public:
    //[SID_IAIMPAddonsOptionsDialog]

    // Add custom frame
    virtual HRESULT WINAPI FrameAdd(IAIMPAddonsOptionsDialogFrame* AFrame) = 0;
    // Remove custom frame
    virtual HRESULT WINAPI FrameRemove(IAIMPAddonsOptionsDialogFrame* AFrame) = 0;
    // Call this method, when something changed on your frame
    virtual HRESULT WINAPI FrameModified(IAIMPAddonsOptionsDialogFrame* AFrame) = 0;
    // AForceShow - Execute Options Dialog, if dialog is not shown
    virtual HRESULT WINAPI FrameShow(IAIMPAddonsOptionsDialogFrame* AFrame, LongBool AForceShow) = 0;
};

// Must be implemented by Plugin
class IAIMPAddonsFileInfoRepository : public IUnknown
{
public:
    // You can fill custom info for AFile using AInfo property
    // If you was processed request, return S_OK
    virtual HRESULT WINAPI GetInfo(const PWideChar AFile, PAIMPFileInfo AInfo) = 0;
};

// Must be implemented by Plugin
class IAIMPAddonsPlayingQueueController: public IUnknown
{
public:
    // [In\Out] params
    // In: Current Playlist ID & EntryIndex
    // Out: Next / Previous Playlist ID & EntryIndex
    // Notes:
    //   If previous controller has processed request, you don't receive it
    //   return S_OK if you was processed request or E_FAIL otherwise
    // Priorities:
    //   1) Queue
    //   2) Plugins
    //   3) Shuffle Manager
    //   4) Playlist
    virtual HRESULT WINAPI GetFile(HPLS ID, Integer AEntryIndex, LongBool ANext) = 0;
};

class IAIMPAddonsConfigFile : public IUnknown
{
public:
    //[SID_IAIMPAddonsConfigFile]

    // functions returns S_OK, if value exists in configuration file
    virtual HRESULT WINAPI ReadString(const PWideChar ASectionName, const PWideChar AItemName, PWideChar AValueBuffer,
                                      Integer ASectionNameSizeInChars, Integer AItemNameSizeInChars, Integer AValueBufferSizeInChars) = 0;
    virtual HRESULT WINAPI ReadInteger(const PWideChar ASectionName, const PWideChar AItemName,
                                       Integer ASectionNameSizeInChars, Integer AItemNameSizeInChars, Integer* AValue) = 0;
    virtual HRESULT WINAPI WriteString(const PWideChar ASectionName, const PWideChar AItemName, const PWideChar AValueBuffer,
                                       Integer ASectionNameSizeInChars, Integer AItemNameSizeInChars, Integer AValueBufferSizeInChars) = 0;
    virtual HRESULT WINAPI WriteInteger(const PWideChar ASectionName, const PWideChar AItemName,
                                        Integer ASectionNameSizeInChars, Integer AItemNameSizeInChars, Integer AValue) = 0;
    virtual HRESULT WINAPI SectionExists(const PWideChar ASectionName, Integer ASectionNameSizeInChars) = 0;
    virtual HRESULT WINAPI SectionRemove(const PWideChar ASectionName, Integer ASectionNameSizeInChars) = 0;
};

class IAIMPAddonsLanguageFile : public IUnknown
{
public:
    //[SID_IAIMPAddonsLanguageFile]

    virtual Integer Version() = 0; ///??? why not stdcall
    virtual Integer WINAPI CurrentFile(PWideChar ABuffer, Integer ABufferSizeInChars) = 0;
    virtual HRESULT WINAPI SectionExists(const PWideChar ASectionName, Integer ASectionNameSizeInChars) = 0;
    virtual HRESULT WINAPI ReadString(const PWideChar ASectionName, PWideChar AItemName, PWideChar AValueBuffer,
                                      Integer ASectionNameSizeInChars, Integer AItemNameSizeInChars, Integer AValueBufferSizeInChars) = 0;
    // When Language changed AIMP will send to WndHandle "WM_AIMP_LANG_CHANGED" message
    virtual HRESULT WINAPI Notification(HWND AWndHandl, LongBool ARegister) = 0;
};

class IAIMPAddonsMenuManager : public IUnknown
{
public:
    //[SID_IAIMPAddonsMenuManager]
    virtual HAIMPMENU WINAPI MenuCreate(DWORD AMenuID, PAIMPMenuItemInfo AItemInfo) = 0; // AMenuID: see AIMP_MENUID_XXX
    virtual HAIMPMENU WINAPI MenuCreateEx(HAIMPMENU AParentMenu, PAIMPMenuItemInfo AItemInfo) = 0;
    virtual DWORD WINAPI MenuTextToShortCut(PWideChar ABuffer, Integer ABufferSizeInChars) = 0;
    virtual HRESULT WINAPI MenuRemove(HAIMPMENU AHandle) = 0;
    virtual HRESULT WINAPI MenuUpdate(HAIMPMENU AHandle, PAIMPMenuItemInfo AItemInfo) = 0;
};

class IAIMPAddonsPlaylistStrings : public IUnknown
{
public:
    //[SID_IAIMPAddonsPlaylistStrings]

    virtual HRESULT WINAPI ItemAdd(const PWideChar AFileName, PAIMPFileInfo AInfo) = 0;
    virtual Integer WINAPI ItemGetCount() = 0;
    virtual HRESULT WINAPI ItemGetFileName(Integer AIndex, PWideChar ABuffer, Integer ABufferSizeInChars) = 0;
    virtual HRESULT WINAPI ItemGetInfo(Integer AIndex, PAIMPFileInfo AInfo) = 0;
};

// must be implemented by plugin
class IAIMPAddonsPlaylistManagerListener : public IUnknown
{
public:
    //[SID_IAIMPAddonsPlaylistManagerListener]

    virtual void StorageActivated(HPLS ID) = 0; ///??? why not stdcall
    virtual void StorageAdded(HPLS ID) = 0; ///??? why not stdcall
    virtual void StorageChanged(HPLS ID, Cardinal AFlags) = 0; ///??? why not stdcall
    virtual void StorageRemoved(HPLS ID) = 0; ///??? why not stdcall
};

// See ActivePlaylistHandle constant
class IAIMPAddonsPlaylistManager : public IUnknown
{
public:
    //[SID_IAIMPAddonsPlaylistManager]

    // AIMP_PLAYLIST_FORMAT_MODE_PREVIEW  - template will be expand as preview
    // AIMP_PLAYLIST_FORMAT_MODE_FILEINFO - put to AData param pointer to TAIMPFileInfo struct
    // AIMP_PLAYLIST_FORMAT_MODE_CURRENT  - format current file info
    // AString buffer will be automaticly freed, you must make copy
    virtual HRESULT WINAPI FormatString(const PWideChar ATemplate, Integer ATemplateSizeInChars,
                                        Integer AMode, Pointer AData, PWideChar* AString) = 0;
    // Listeners
    virtual HRESULT WINAPI ListenerAdd(IAIMPAddonsPlaylistManagerListener* AListener) = 0;
    virtual HRESULT WINAPI ListenerRemove(IAIMPAddonsPlaylistManagerListener* AListener) = 0;
    // See AIMP_PLAYLIST_ENTRY_PROPERTY_XXX
    virtual HRESULT WINAPI EntryDelete(HPLSENTRY AEntry) = 0;
    virtual HRESULT WINAPI EntryGetGroup(HPLSENTRY AEntry, HPLSGROUP* AGroup) = 0;
    virtual HRESULT WINAPI EntryPropertyGetValue(HPLSENTRY AEntry, Integer APropertyID, Pointer ABuffer, Integer ABufferSize) = 0;
    virtual HRESULT WINAPI EntryPropertySetValue(HPLSENTRY AEntry, Integer APropertyID, const Pointer ABuffer, Integer ABufferSize) = 0;
    virtual HRESULT WINAPI EntryReloadInfo(HPLSENTRY AEntry) = 0;
    // See AIMP_PLAYLIST_GROUP_PROPERTY_XXX
    virtual HRESULT WINAPI GroupPropertyGetValue(HPLSGROUP AGroup, Integer APropertyID, Pointer ABuffer, Integer ABufferSize) = 0;
    virtual HRESULT WINAPI GroupPropertySetValue(HPLSGROUP AGroup, Integer APropertyID, const Pointer ABuffer, Integer ABufferSize) = 0;
    //
    virtual HPLS WINAPI StorageActiveGet() = 0;
    virtual HRESULT WINAPI StorageActiveSet(HPLS ID) = 0;
    virtual HRESULT WINAPI StorageAddEntries(HPLS ID, IAIMPAddonsPlaylistStrings* AObjects) = 0; // Add Objects to playlist. "Objects" can contains: shortcuts, files, folder, playlists
    virtual HPLS WINAPI StorageCreate(const PWideChar AName, LongBool AActivate) = 0;
    virtual HPLS WINAPI StorageCreateFromFile(const PWideChar AFileName, LongBool AActivate, LongBool AStartPlay) = 0;
    virtual HPLS WINAPI StoragePlayingGet()= 0;
    //
    virtual HPLS WINAPI StorageGet(Integer AIndex) = 0;
    virtual Integer WINAPI StorageGetCount() = 0; // Count of loaded playlists
    virtual HPLSENTRY WINAPI StorageGetEntry(HPLS ID, Integer AEntryIndex) = 0;
    virtual Integer WINAPI StorageGetEntryCount(HPLS ID) = 0;
    virtual HRESULT WINAPI StorageGetFiles(HPLS ID, Integer AFlags, IAIMPAddonsPlaylistStrings** AFiles) = 0; // Flags: Use combination of the AIMP_PLAYLIST_GETFILES_XXX flags
    virtual HPLSGROUP WINAPI StorageGetGroup(HPLS ID, Integer AGroupIndex) = 0;
    virtual Integer WINAPI StorageGetGroupCount(HPLS ID) = 0;
    //
    virtual HRESULT WINAPI StorageDelete(HPLS ID, Integer AEntryIndex) = 0;
    virtual HRESULT WINAPI StorageDeleteAll(HPLS ID) = 0;
    virtual HRESULT WINAPI StorageDeleteByFilter(HPLS ID, LongBool APhysically,
                                                 TAIMPAddonsPlaylistManagerDeleteProc AFilterProc, Pointer AUserData) = 0;
    virtual HRESULT WINAPI StorageRemove(HPLS ID) = 0; // Remove playlist storage from manager (like "close playlist")
    //
    virtual HRESULT WINAPI StorageSort(HPLS ID, Integer ASortType) = 0; // Predefined Sorting, see AIMP_PLAYLIST_SORT_TYPE_XXX
    virtual HRESULT WINAPI StorageSortCustom(HPLS ID, TAIMPAddonsPlaylistManagerCompareProc ACompareProc, Pointer AUserData) = 0;
    virtual HRESULT WINAPI StorageSortTemplate(HPLS ID, const PWideChar ABuffer, Integer ABufferSizeInChars) = 0;
    // Lock / Unlock playlist calculation and drawing
    virtual HRESULT WINAPI StorageBeginUpdate(HPLS ID) = 0;
    virtual HRESULT WINAPI StorageEndUpdate(HPLS ID) = 0;
    // See AIMP_PLAYLIST_STORAGE_PROPERTY_XXX
    virtual HRESULT WINAPI StoragePropertyGetValue(HPLS ID, Integer APropertyID, Pointer ABuffer, Integer ABufferSize) = 0;
    virtual HRESULT WINAPI StoragePropertySetValue(HPLS ID, Integer APropertyID, const Pointer ABuffer, Integer ABufferSize) = 0;
    // Queue
    virtual HRESULT WINAPI QueueEntryAdd(HPLSENTRY AEntry, LongBool AInsertAtQueueBegining) = 0;
    virtual HRESULT WINAPI QueueEntryRemove(HPLSENTRY AEntry) = 0;
};

class IAIMPAddonsCoverArtManager : public IUnknown
{
public:
    //[SID_IAIMPAddonsCoverArtManager]

    // Picture will be proportional stretched to ADisplaySize value, if it assigned
    // ACoverArtFileName: can be nil (todo: doc)
    virtual HBITMAP WINAPI CoverArtGetForFile(const PWideChar AFileName, const TSize* ADisplaySize,
                                              PWideChar ACoverArtFileNameBuffer, Integer ACoverArtFileNameBufferSizeInChars) = 0;
    // Work with CoverArt of playing file,
    // if file is playing and CoverArt exists, functions returns S_OK
    virtual HRESULT WINAPI CoverArtDraw(HDC DC, const TRect* R) = 0; // CoverArt will be proportional stretched to R value
    virtual HRESULT WINAPI CoverArtGetFileName(PWideChar ABuffer, Integer ABufferSizeInChars) = 0;
    virtual HRESULT WINAPI CoverArtGetSize(TSize* ASize) = 0;
};

class IAIMPAddonsPlayerManager : public IUnknown
{
public:
    //[SID_IAIMPAddonsPlayerManager]

    virtual HRESULT WINAPI PlayEntry(HPLSENTRY AEntry) = 0;
    virtual HRESULT WINAPI PlayFile(const PWideChar AFileName, LongBool AFailIfNotExistsInPlaylist) = 0;
    virtual HRESULT WINAPI PlayStorage(HPLS ID, Integer AEntryIndex = -1) = 0;
    // Register / Unregister custom FileInfo repository, you can put own info about the any file
    virtual HRESULT WINAPI FileInfoRepository(IAIMPAddonsFileInfoRepository* ARepository, LongBool ARegister) = 0;
    // if AFileName = nil: Get information about currently playing file
    virtual HRESULT WINAPI FileInfoQuery(const PWideChar AFileName, PAIMPFileInfo AInfo) = 0;
    // Regiset / Unregister custom playing queue controller
    virtual HRESULT WINAPI PlayingQueueController(IAIMPAddonsPlayingQueueController* AController, LongBool ARegister) = 0;
    // see AIMP_CFG_PATH_XXX
    virtual HRESULT WINAPI ConfigGetPath(Integer AConfigPathID, PWideChar ABuffer, Integer ABufferSizeInChars) = 0;
    // see AIMP_SUPPORTS_EXTS_XXX
    virtual HRESULT WINAPI SupportsExts(Cardinal AFlags, PWideChar ABuffer, Integer ABufferSizeInChars) = 0;
};

class IAIMPAddonsSkinsManager : public IUnknown
{
public:
    //[SID_IAIMPAddonsSkinsManager]

    // AColorHue & AColorHueIntensity - optional
    virtual HRESULT WINAPI GetCurrentSettings(const PWideChar ASkinLocalFileNameBuffer, Integer ASkinLocalFileNameBufferSizeInChars,
                                              PInteger AColorHue, PInteger AColorHueIntensity) = 0;
    // Get Info about Skin
    // + Skin can be placed anywhere
    // + if AFileNameBuffer contains empty string - function return information about build-in skin
    // WARNING!!! You must manually destroy TAIMPSkinInfo.Preview if it no longer need
    virtual HRESULT GetSkinInfo(const PWideChar AFileNameBuffer, Integer AFileNameBufferSizeInChars, PAIMPSkinInfo ASkinInfo) = 0; ///??? why not stdcall

    // Skin must be placed in %AIMP_Skins% directory (see IAIMPAddonsPlayerManager.ConfigGetPath)
    // AColorHue: [0..255], Default: 0 (don't change hue)
    // AColorHueIntensity [0..100], Default: 100 (don't change Hue Intensity), depends from AColorHue value
    virtual HRESULT WINAPI Select(const PWideChar ASkinLocalFileName, Integer AColorHue, Integer AColorHueIntensity) = 0;
    // Conversion between HSL and RGB color spaces
    virtual HRESULT WINAPI HSLToRGB(Byte H, Byte S, Byte L, Byte* R, Byte* G, Byte* B) = 0;
    virtual HRESULT WINAPI RGBToHSL(Byte R, Byte G, Byte B, Byte* H, Byte* S, Byte* L) = 0;
};

class IAIMPAddonPlugin : public IUnknown
{
public:
    virtual const PWideChar WINAPI GetPluginAuthor() = 0;
    virtual const PWideChar WINAPI GetPluginInfo() = 0;
    virtual const PWideChar WINAPI GetPluginName() = 0;
    virtual DWORD   WINAPI GetPluginFlags() = 0; // See AIMP_ADDON_FLAGS_XXX
    virtual HRESULT WINAPI Initialize(IAIMPCoreUnit* coreUnit) = 0;
    virtual HRESULT WINAPI Finalize() = 0;
    virtual HRESULT WINAPI ShowSettingsDialog(HWND parentWindow) = 0;
};

} // namespace AIMP3SDK

#endif // #ifndef AIMP3_SDK_ADDONS_H
