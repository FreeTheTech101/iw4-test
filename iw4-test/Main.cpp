#include "stdafx.h"
#include "steam_api.h"

void PartyBypass();
void Stats();
void Load();

char* exampleName = "Unimportant Idiot";

__declspec(dllexport) void __cdecl SteamAPI_RunCallbacks()
{
	// Prevent debugger shit
}

ISteamMatchmaking* __cdecl SteamMatchmaking()
{
	return (ISteamMatchmaking*)CSteamBase::GetInterface(INTERFACE_STEAMMATCHMAKING007);
}

ISteamFriends* __cdecl SteamFriends()
{
	return (ISteamFriends*)CSteamBase::GetInterface(INTERFACE_STEAMFRIENDS005);
}

const char* IWClient_HandleLobbyData(const char* key)
{
	netadr_t address = currentLobbyTarget;

	if (!strcmp(key, "addr"))
	{
		return va("%d", address.ip[0] | (address.ip[1] << 8) | (address.ip[2] << 16) | (address.ip[3] << 24));
	}
	else if (!strcmp(key, "port"))
	{
		return va("%d", htons(currentLobbyTarget.port));
	}

	return "212";
}

unsigned int oneAtATimeHash(char* inpStr)
{
	unsigned int value = 0,temp = 0;
	for(size_t i=0;i<strlen(inpStr);i++)
	{
		char ctext = tolower(inpStr[i]);
		temp = ctext;
		temp += value;
		value = temp << 10;
		temp += value;
		value = temp >> 6;
		value ^= temp;
	}
	temp = value << 3;
	temp += value;
	unsigned int temp2 = temp >> 11;
	temp = temp2 ^ temp;
	temp2 = temp << 15;
	value = temp2 + temp;
	if(value < 2) value += 2;
	return value;
}

hostent* WINAPI custom_gethostbyname(const char* name) {
	// if the name is IWNet's stuff...
	unsigned int ip1 = oneAtATimeHash("ip1.pc.iw4.iwnet.infinityward.com");
	unsigned int log1 = oneAtATimeHash("log1.pc.iw4.iwnet.infinityward.com");
	unsigned int match1 = oneAtATimeHash("match1.pc.iw4.iwnet.infinityward.com");
	unsigned int web1 = oneAtATimeHash("web1.pc.iw4.iwnet.infinityward.com");
	unsigned int blob1 = oneAtATimeHash("blob1.pc.iw4.iwnet.infinityward.com");

	unsigned int current = oneAtATimeHash((char*)name);
	char* hostname = (char*)name;

	if (current == log1 || current == match1 || current == blob1 || current == ip1 || current == web1)
	{

		hostname = "127.0.0.1";
	}

	return gethostbyname(hostname);
}

DWORD SteamUserStuff = 0x47BDA0;
DWORD returnSuccess = 0x451169;
DWORD otherStuff = 0x42B210;

void __declspec(naked) steamInitPatch()
{
	__asm
	{
		call SteamUserStuff
		test al, al
		jz returnSafe
		jmp returnSuccess

returnSuccess:
		call otherStuff
		test al, al
		jz returnSafe
		jmp returnSuccess

returnSafe:
		mov al, 1
		retn
	}
}

void loadGameOverlay()
{
	try
	{
		std::string m_steamDir;
		HKEY hRegKey;

		if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "Software\\Valve\\Steam", 0, KEY_QUERY_VALUE, &hRegKey) == ERROR_SUCCESS)
		{
			char pchSteamDir[MAX_PATH];
			DWORD dwLength = sizeof(pchSteamDir);
			RegQueryValueExA(hRegKey, "InstallPath", NULL, NULL, (BYTE*)pchSteamDir, &dwLength);
			RegCloseKey(hRegKey);

			m_steamDir = pchSteamDir;
		}

		LoadLibrary(va("%s\\gameoverlayrenderer.dll", m_steamDir.c_str()));
	}
	catch (int e)
	{
	}
}

CallHook imageVersionCheckHook;
DWORD imageVersionCheckHookLoc = 0x53A456;

void __declspec(naked) ImageVersionCheckHookFunc()
{
	__asm
	{
		cmp eax, 9
			je returnSafely

			jmp imageVersionCheckHook.pOriginal

returnSafely:
		mov al, 1
			add esp, 18h
			retn
	}
}

void Con_ToggleConsole()
{
	// possibly cls.keyCatchers?
	*(DWORD*)0xB2C538 ^= 1;

	// g_consoleField
	Field_Clear((void*)0xA1B6B0);

	// show console output?
	*(BYTE*)0xA15F38 = 0;
}

CallHook clKeyEventToggleConsoleHook1;
DWORD clKeyEventToggleConsoleHook1Loc =	0x4F690C;

StompHook clKeyEventToggleConsoleHook2;
DWORD clKeyEventToggleConsoleHook2Loc = 0x4F65A5;

char ingameUsername[32];

char* GetUsername()
{
	if((BOOL)(*dvarName) && strcmp((*dvarName)->current.string, ""))
	{
		strncpy(ingameUsername, (*dvarName)->current.string, sizeof(ingameUsername));
	}
	else
	{
		strncpy(ingameUsername, exampleName, sizeof(ingameUsername));
	}

	return ingameUsername;
}

void PatchMW2()
{
	// Ignore DVAR error
	nop(0x5EC371, 5);
	nop(0x5EC44E, 5);
	nop(0x5EC4FA, 5);
	nop(0x5EC5A7, 5);

	// Entirely remove steam support... we don't want you to get banned :D
	*(WORD*)0x45114E = 0x01B0;
	nop(0x451145, 5);
	call(0x451160, steamInitPatch, PATCH_JUMP);

	// external console
	nop(0x60BB58, 11);

	// SteamNetworking stuff
	*(BYTE*)0x4E6650 = 0xC3;

	// Stats stuff
	*(BYTE*)0x44AAF0 = 0xC3;
	*(BYTE*)0x467CC0 = 0xC3;

	// IDK what this does, could be important though...
	nop(0x593A1A, 3);
	nop(0x593A52, 2);
	//nop(0x593A6B, 2);

	// This looks dangerous to patch
	nop(0x594260, 5);

	// No improper quit popup
	*(BYTE*)0x4113BB = 0xEB;

	// Ignore popup_getting_data (need to pix the playlist stuff instead of patching this)
	*(BYTE*)0x473829 = 0xEB;

	// Let's assume we're online and we call ourself 'STEAM'
	*(BYTE*)0x4FC2D8 = 0xEB;
	*(BYTE*)0x4FC2F4 = 0xEB;
	*(BYTE*)0x649D6F0 = 1;

	// m2demo stuff
	*(DWORD*)0x6431D1 = (DWORD)"data";

	// allow vid_restart even if 'connected'
	memset((void*)0x4CA1FA, 0x90, 6);

	// Disable 'x' commands (except UPNP, that should be added lateron)
	//nop(0x4059E5, 5);

	// alt-tab support
	*(BYTE*)0x45ACE0 = 0xB0;
	*(BYTE*)0x45ACE1 = 0x01;
	*(BYTE*)0x45ACE2 = 0xC3;

	// xblive_rankedmatch
	*(DWORD*)0x420A34 = DVAR_FLAG_NONE;

	// cg_fov
	*(BYTE*)0x4F8E35 = DVAR_FLAG_SAVED;
	*(float*)0x6E5788 = 90.0f;

	// remove fs_game check for moddable rawfiles - allows non-fs_game to modify rawfiles
	*(WORD*)0x61AB76 = 0x9090;

	// remove limit on IWD file loading
	//memset((void*)0x643B94, 0x90, 6);
	*(BYTE*)0x642BF3 = 0xEB;

	// Force debug logging
	nop(0x4AA89F, 2);
	nop(0x4AA8A1, 6);

	// Configstring stuff
	*(BYTE*)0x5AC2C3 = 0xEB; // CL_ParseGamestate

	// protocol version (workaround for hacks)
	*(int*)0x4FB501 = PROTOCOL; // was 8E

	// protocol command
	*(int*)0x4D36A9 = PROTOCOL; // was 8E
	*(int*)0x4D36AE = PROTOCOL; // was 8E
	*(int*)0x4D36B3 = PROTOCOL; // was 8E

	// Test
	ReallocateAssetPool(ASSET_TYPE_WEAPON, 2400);

	FreeConsole();
	Stats();
	Load();
	PartyBypass();
	loadGameOverlay();

	imageVersionCheckHook.initialize(imageVersionCheckHookLoc, ImageVersionCheckHookFunc);
	imageVersionCheckHook.installHook();

	clKeyEventToggleConsoleHook1.initialize(clKeyEventToggleConsoleHook1Loc, Con_ToggleConsole);
	clKeyEventToggleConsoleHook1.installHook();

	clKeyEventToggleConsoleHook2.initialize(clKeyEventToggleConsoleHook2Loc, Con_ToggleConsole);
	clKeyEventToggleConsoleHook2.installHook();

	*(DWORD*)0x6D75B0 = (DWORD)SteamMatchmaking;
	*(DWORD*)0x6D75EC = (DWORD)SteamFriends;
	*(DWORD*)0x405309 = (DWORD)exampleName;
	*(DWORD*)0x6D7458 = (DWORD)custom_gethostbyname;
}

void Sys_Init()
{
	if(!strcmp((char*)0x6E9638, "177"))
	{
		PatchMW2();
	}
	
}