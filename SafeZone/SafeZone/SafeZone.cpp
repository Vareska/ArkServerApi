#include "SafeZone.h"
#include "SafeZoneHooks.h"
#include "SafeZoneCommands.h"
#include "SafeZoneConfig.h"
#pragma comment(lib, "ArkApi.lib")

void Init()
{
	AllocConsole();
	FILE* pCout;
	freopen_s(&pCout, "conout$", "w", stdout);
	Log::Get().Init("SafeZone");
	InitConfig();
	InitHooks();
	InitCommands();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Init();
		break;
	case DLL_PROCESS_DETACH:
		RemoveHooks();
		RemoveCommands();
		break;
	}
	return TRUE;
}