#include "Mutes.h"
#include "MuteManager.h"
#include "MuteHooks.h"
#include "MuteCommands.h"
#include "MuteConfig.h"
#pragma comment(lib, "ArkApi.lib")

void Init()
{
	AllocConsole();
	FILE* pCout;
	freopen_s(&pCout, "conout$", "w", stdout);
	Log::Get().Init("Mutes");
	InitConfig();
	InitHooks();
	InitCommands();
	Log::GetLog()->info("Mutes Loaded.");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Init();
		break;
	case DLL_PROCESS_DETACH:
		SaveConfig();
		RemoveHooks();
		RemoveCommands();
		break;
	}
	return TRUE;
}