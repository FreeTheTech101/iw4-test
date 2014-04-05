// ==========================================================
// MW2 coop
// 
// Component: IW4SP
// Sub-component: steam_api
// Purpose: Game-specific code implementations.
//
// Initial author: NTAuthority
// Started: 2014-03-02
// ==========================================================

#include "stdafx.h"

// function definitions
extern "C"
{
	Cbuf_AddText_t Cbuf_AddText = (Cbuf_AddText_t)0x404B20;

	CL_AddReliableCommand_t CL_AddReliableCommand = (CL_AddReliableCommand_t)0x454F40;
	CL_IsCgameInitialized_t CL_IsCgameInitialized = (CL_IsCgameInitialized_t)0x43EB20;

	Cmd_AddCommand_t Cmd_AddCommand = (Cmd_AddCommand_t)0x470090;
	Cmd_AddServerCommand_t Cmd_AddServerCommand = (Cmd_AddServerCommand_t)0x4DCE00;
	Cmd_ExecuteSingleCommand_t Cmd_ExecuteSingleCommand = (Cmd_ExecuteSingleCommand_t)0x609540;
	Cmd_SetAutoComplete_t Cmd_SetAutoComplete = (Cmd_SetAutoComplete_t)0x40EDC0;

	Com_Error_t Com_Error = (Com_Error_t)0x4B22D0;
	Com_ParseExt_t Com_ParseExt = (Com_ParseExt_t)0x4C0350;
	Com_ParseExt2_t Com_ParseExt2 = (Com_ParseExt2_t)0x474D60;
	Com_BeginParseSession_t Com_BeginParseSession = (Com_BeginParseSession_t)0x4AAB80;
	Com_EndParseSession_t Com_EndParseSession = (Com_EndParseSession_t)0x4B80B0;
	Com_Printf_t Com_Printf = (Com_Printf_t)0x402500;
	Com_Milliseconds_t Com_Milliseconds = (Com_Milliseconds_t)0x42A660;
	Com_PrintError_t Com_PrintError = (Com_PrintError_t)0x4F8C70;

	DB_FindXAssetHeader_t DB_FindXAssetHeader = (DB_FindXAssetHeader_t)0x407930;
	DB_FindXAssetHeader_MW3_t DB_FindXAssetHeader_MW3 = (DB_FindXAssetHeader_MW3_t)0;
	DB_LoadXAssets_t DB_LoadXAssets = (DB_LoadXAssets_t)0x4E5930;

	Dvar_RegisterBool_t Dvar_RegisterBool = (Dvar_RegisterBool_t)0x4CE1A0;
	Dvar_RegisterFloat_t Dvar_RegisterFloat = (Dvar_RegisterFloat_t)0x648440;
	Dvar_RegisterFloat2_t Dvar_RegisterFloat2 = (Dvar_RegisterFloat2_t)0x4F6070;
	Dvar_RegisterFloat3_t Dvar_RegisterFloat3 = (Dvar_RegisterFloat3_t)0x4EF8E0;
	Dvar_RegisterFloat4_t Dvar_RegisterFloat4 = (Dvar_RegisterFloat4_t)0x4F28E0;
	Dvar_RegisterInt_t Dvar_RegisterInt = (Dvar_RegisterInt_t)0x479830;
	Dvar_RegisterEnum_t Dvar_RegisterEnum = (Dvar_RegisterEnum_t)0x412E40;
	Dvar_RegisterString_t Dvar_RegisterString = (Dvar_RegisterString_t)0x4FC7E0;
	Dvar_RegisterColor_t Dvar_RegisterColor = (Dvar_RegisterColor_t)0x471500;

	Dvar_FindVar_t Dvar_FindVar = (Dvar_FindVar_t)0x4D5390;
	Dvar_InfoString_Big_t Dvar_InfoString_Big = (Dvar_InfoString_Big_t)0x4D98A0;
	Dvar_SetCommand_t Dvar_SetCommand = (Dvar_SetCommand_t)0x4EE430;
	Dvar_SetStringByName_t Dvar_SetStringByName = (Dvar_SetStringByName_t)0x4F52E0;

	FS_FreeFile_t FS_FreeFile = (FS_FreeFile_t)0x4416B0;
	FS_ReadFile_t FS_ReadFile = (FS_ReadFile_t)0x4F4B90;
	FS_ListFiles_t FS_ListFiles = (FS_ListFiles_t)0x441BB0;
	FS_FreeFileList_t FS_FreeFileList = (FS_FreeFileList_t)0x4A5DE0;
	FS_FOpenFileAppend_t FS_FOpenFileAppend = (FS_FOpenFileAppend_t)0x410BB0;
	FS_FOpenFileAppend_t FS_FOpenFileWrite = (FS_FOpenFileAppend_t)0x4BA530;
	FS_FOpenFileRead_t FS_FOpenFileRead = (FS_FOpenFileRead_t)0x46CBF0;
	FS_FCloseFile_t FS_FCloseFile = (FS_FCloseFile_t)0x462000;
	FS_WriteFile_t FS_WriteFile = (FS_WriteFile_t)0x426450;
	FS_Write_t FS_Write = (FS_Write_t)0x4C06E0;
	FS_Read_t FS_Read = (FS_Read_t)0x4A04C0;
	FS_Seek_t FS_Seek = (FS_Seek_t)0x4A63D0;

	G_LogPrintf_t G_LogPrintf = (G_LogPrintf_t)0x4B0150;

	MSG_Init_t MSG_Init = (MSG_Init_t)0x45FCA0;
	MSG_ReadData_t MSG_ReadData = (MSG_ReadData_t)0x4527C0;
	MSG_ReadLong_t MSG_ReadLong = (MSG_ReadLong_t)0x4C9550;
	MSG_ReadShort_t MSG_ReadShort = (MSG_ReadShort_t)0x40BDD0;
	MSG_ReadInt64_t MSG_ReadInt64 = (MSG_ReadInt64_t)0x4F1850;
	MSG_ReadString_t MSG_ReadString = (MSG_ReadString_t)0x60E2B0;
	MSG_WriteByte_t MSG_WriteByte = (MSG_WriteByte_t)0x48C520;
	MSG_WriteData_t MSG_WriteData = (MSG_WriteData_t)0x4F4120;
	MSG_WriteLong_t MSG_WriteLong = (MSG_WriteLong_t)0x41CA20;

	NET_AdrToString_t NET_AdrToString = (NET_AdrToString_t)0x469880;
	NET_CompareAdr_t NET_CompareAdr = (NET_CompareAdr_t)0x4D0AA0;
	NET_StringToAdr_t NET_StringToAdr = (NET_StringToAdr_t)0x409010;

	SV_GameSendServerCommand_t SV_GameSendServerCommand = (SV_GameSendServerCommand_t)0x4BC3A0;

	TeleportPlayer_t TeleportPlayer = (TeleportPlayer_t)0x496850;

	Sys_SendPacket_t Sys_SendPacket = (Sys_SendPacket_t)0x48F500;
	Sys_ListFiles_t Sys_ListFiles = (Sys_ListFiles_t)0x45A660;
	Sys_FreeFileList_t Sys_FreeFileList = (Sys_FreeFileList_t)0x4D8580;

	Cmd_TokenizeString_t Cmd_TokenizeString = (Cmd_TokenizeString_t)0x463E40;
	Cmd_EndTokenizedString_t Cmd_EndTokenizedString = (Cmd_EndTokenizedString_t)0x4D9540;

	// other stuff
	CommandCB_t Cbuf_AddServerText_f = (CommandCB_t)0x4BB9B0;

	R_RegisterFont_t R_RegisterFont = (R_RegisterFont_t)0x505670;
	R_AddCmdDrawText_t R_AddCmdDrawText = (R_AddCmdDrawText_t)0x509D80;

	SL_GetString_t SL_GetString = (SL_GetString_t)0x4CDC10;

	// 159 stuff
	Field_Clear_t Field_Clear = (Field_Clear_t)0x437EB0;
};

dvar_t** dvarName = (dvar_t**)0xB2C680;

char* language = (char*)0x649E748;

source_t **sourceFiles = (source_t **)0x7C4A98;
keywordHash_t **menuParseKeywordHash = (keywordHash_t **)0x63AE928;

int version = 0;

// console commands
DWORD* cmd_id = (DWORD*)0x1AAC5D0;
DWORD* cmd_argc = (DWORD*)0x1AAC614;
DWORD** cmd_argv = (DWORD**)0x1AAC634;

const char *current_zone = nullptr;
bool _allowZoneChange = true;

searchpath_t* fs_searchpaths = (searchpath_t*)0x63D96E0;
int* clientState = (int*)0xB2C540;
gentity_t* g_entities = (gentity_t*)0x18835D8;
int* svs_numclients = (int*)0x31D938C;
client_t* svs_clients = (client_t*)0x31D9390;

DWORD* cmd_id_sv = (DWORD*)0x1ACF8A0;
DWORD* cmd_argc_sv = (DWORD*)0x1ACF8E4;
DWORD** cmd_argv_sv = (DWORD**)0x1ACF904;

typedef struct party_s
{
	BYTE pad1[544];
	int privateSlots;
	int publicSlots;
} party_t;

static party_t** partyIngame = (party_t**)0x1081C00;

int Party_NumPublicSlots(party_t* party)
{
	return party->publicSlots + party->privateSlots;
}

int Party_NumPublicSlots()
{
	return Party_NumPublicSlots(*partyIngame);
}

/*
============
Cmd_Argc
============
*/
int		Cmd_ArgcSV( void ) {
	return cmd_argc_sv[*cmd_id_sv];
}

/*
============
Cmd_Argv
============
*/
char	*Cmd_ArgvSV( int arg ) {
	if ( (unsigned)arg >= cmd_argc_sv[*cmd_id_sv] ) {
		return "";
	}
	return (char*)(cmd_argv_sv[*cmd_id_sv][arg]);	
}

void SV_GetStatus(svstatus_t* status)
{
	if (!status) return;

	int clientCount = 0;
	BYTE* clientAddress = (BYTE*)svs_clients;

	for (int i = 0; i < *svs_numclients; i++) {
		if (*clientAddress >= 3) {
			clientCount++;
		}

		clientAddress += 681872;
	}

	status->curClients = clientCount;
	status->maxClients = Party_NumPublicSlots();

	const char* mapname = GetStringConvar("mapname");
	strcpy(status->map, mapname);
}

bool SV_IsClientIP(unsigned int ip)
{
	BYTE* clientAddress = (BYTE*)svs_clients;

	for (int i = 0; i < *svs_numclients; i++) {
		if (*clientAddress >= 3) {
			netadr_t* adr = (netadr_t*)(clientAddress + 40);
			unsigned int clientIP = (adr->ip[3]) | (adr->ip[2] << 8) | (adr->ip[1] << 16) | (adr->ip[0] << 24);

			if (clientIP == ip)
			{
				return true;
			}
		}

		clientAddress += 681872;
	}

	return false;
}


/*
============
Cmd_Argc
============
*/
/*int		Cmd_Argc( void ) {
	return cmd_argc[*cmd_id];
}*/

/*
============
Cmd_Argv
============
*/
/*char	*Cmd_Argv( int arg ) {
	if ( (unsigned)arg >= cmd_argc[*cmd_id] ) {
		return "";
	}
	return (char*)(cmd_argv[*cmd_id][arg]);	
}*/

// get convar string
char* GetStringConvar(char* key) {
	dvar_t* var = Dvar_FindVar(key);

	if (!var) return "";

	return var->current.string;
}

typedef void (__cdecl* sendOOB_t)(int, int, int, int, int, int, const char*);
sendOOB_t OOBPrint = (sendOOB_t)0x4AEF00;

void OOBPrintT(int type, netadr_t netadr, const char* message)
{
	int* adr = (int*)&netadr;

	OOBPrint(type, *adr, *(adr + 1), *(adr + 2), 0xFFFFFFFF, *(adr + 4), message);
}

void NET_OutOfBandPrint(int type, netadr_t adr, const char* message, ...)
{
	va_list args;
	char buffer[65535];

	va_start(args, message);
	_vsnprintf(buffer, sizeof(buffer), message, args);
	va_end(args);

	OOBPrintT(type, adr, buffer);
}

typedef int (__cdecl * DB_GetXAssetSizeHandler_t)();
DB_GetXAssetSizeHandler_t* DB_GetXAssetSizeHandlers = (DB_GetXAssetSizeHandler_t*)0x799488;

void** DB_XAssetPool = (void**)0x7998A8;
unsigned int* g_poolSize = (unsigned int*)0x7995E8;

void* ReallocateAssetPool(int type, unsigned int newSize)
{
	int elSize = DB_GetXAssetSizeHandlers[type]();
	void* poolEntry = malloc(newSize * elSize);
	DB_XAssetPool[type] = poolEntry;
	g_poolSize[type] = newSize;
	return poolEntry;
}

// a funny thing is how this va() function could possibly come from leaked IW code.
#define VA_BUFFER_COUNT		4
#define VA_BUFFER_SIZE		4096

static char g_vaBuffer[VA_BUFFER_COUNT][VA_BUFFER_SIZE];
static int g_vaNextBufferIndex = 0;

const char *va( const char *fmt, ... )
{
	va_list ap;
	char *dest = &g_vaBuffer[g_vaNextBufferIndex][0];
	g_vaNextBufferIndex = (g_vaNextBufferIndex + 1) % VA_BUFFER_COUNT;
	va_start(ap, fmt);
	vsprintf( dest, fmt, ap );
	va_end(ap);
	return dest;
}

/*
===================
Info_RemoveKey
===================
*/
void Info_RemoveKey( char *s, const char *key ) {
	char	*start;
	char	pkey[MAX_INFO_KEY];
	char	value[MAX_INFO_VALUE];
	char	*o;

	if (strchr (key, '\\')) {
		return;
	}

	while (1)
	{
		start = s;
		if (*s == '\\')
			s++;
		o = pkey;
		while (*s != '\\')
		{
			if (!*s)
				return;
			*o++ = *s++;
		}
		*o = 0;
		s++;

		o = value;
		while (*s != '\\' && *s)
		{
			if (!*s)
				return;
			*o++ = *s++;
		}
		*o = 0;

		if (!strcmp (key, pkey) )
		{
			strcpy (start, s);	// remove this part
			return;
		}

		if (!*s)
			return;
	}

}

/*
==================
Info_SetValueForKey

Changes or adds a key/value pair
==================
*/
void Info_SetValueForKey( char *s, const char *key, const char *value ) {
	char    newi[MAX_INFO_STRING];
	const char* blacklist = "\\;\"";

	if ( strlen( s ) >= MAX_INFO_STRING ) {
		Com_Printf( 0, "Info_SetValueForKey: oversize infostring");
		return;
	}

	for(; *blacklist; ++blacklist)
	{
		if (strchr (key, *blacklist) || strchr (value, *blacklist))
		{
			Com_Printf (0, "Can't use keys or values with a '%c': %s = %s\n", *blacklist, key, value);
			return;
		}
	}

	Info_RemoveKey (s, key);
	if (!value || !strlen(value))
		return;

	_snprintf (newi, sizeof(newi), "\\%s\\%s", key, value);

	if (strlen(newi) + strlen(s) >= MAX_INFO_STRING)
	{
		Com_Printf (0, "Info string length exceeded\n");
		return;
	}

	strcat (newi, s);
	strcpy (s, newi);
}


#define	BIG_INFO_STRING		8192  // used for system info key only
#define	BIG_INFO_KEY		  8192
#define	BIG_INFO_VALUE		8192

/*
===============
Info_ValueForKey

Searches the string for the given
key and returns the associated value, or an empty string.
FIXME: overflow check?
===============
*/
char *Info_ValueForKey( const char *s, const char *key )
{
	char	pkey[BIG_INFO_KEY];
	static	char value[2][BIG_INFO_VALUE];	// use two buffers so compares
	// work without stomping on each other
	static	int	valueindex = 0;
	char	*o;

	if ( !s || !key ) {
		return "";
	}

	if ( strlen( s ) >= BIG_INFO_STRING ) {
		//Com_Error( ERR_DROP, "Info_ValueForKey: oversize infostring" );
		return "";
	}

	valueindex ^= 1;
	if (*s == '\\')
		s++;
	while (1)
	{
		o = pkey;
		while (*s != '\\')
		{
			if (!*s)
				return "";
			*o++ = *s++;
		}
		*o = 0;
		s++;

		o = value[valueindex];

		while (*s != '\\' && *s)
		{
			*o++ = *s++;
		}
		*o = 0;

		if (!_stricmp (key, pkey) )
			return value[valueindex];

		if (!*s)
			break;
		s++;
	}

	return "";
}