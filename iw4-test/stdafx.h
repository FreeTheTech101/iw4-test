#pragma once

#include "targetver.h"

#undef UNICODE

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <winsock.h>
#include <stdint.h>
#include "IW4.h"
#include "Hooking.h"
#include "ClientCommon.h"

#include "SteamBase.h"
#include "ISteamFriends005.h"
#include "ISteamMatchmaking007.h"