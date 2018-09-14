// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

DWORD _ijlGetLibVersion;
DWORD _ijlInit;
DWORD _ijlFree;
DWORD _ijlRead;
DWORD _ijlWrite;
DWORD _ijlErrorStr;

extern "C" __declspec(dllexport) __declspec(naked) void ijlGetLibVersion() {
	__asm {
		jmp _ijlGetLibVersion
	}
}
extern "C" __declspec(dllexport) __declspec(naked) void ijlInit() {
	__asm {
		jmp _ijlInit
	}
}
extern "C" __declspec(dllexport) __declspec(naked) void ijlFree() {
	__asm {
		jmp _ijlFree
	}
}
extern "C" __declspec(dllexport) __declspec(naked) void ijlRead() {
	__asm {
		jmp _ijlRead
	}
}
extern "C" __declspec(dllexport) __declspec(naked) void ijlWrite() {
	__asm {
		jmp _ijlWrite
	}
}
extern "C" __declspec(dllexport) __declspec(naked) void ijlErrorStr() {
	__asm {
		jmp _ijlErrorStr
	}
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	DisableThreadLibraryCalls(hModule);

	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		HMODULE hModule = LoadLibraryA("ijl15.dll.old");

		_ijlGetLibVersion = (DWORD)GetProcAddress(hModule, "ijlGetLibVersion");
		_ijlInit = (DWORD)GetProcAddress(hModule, "ijlInit");
		_ijlFree = (DWORD)GetProcAddress(hModule, "ijlFree");
		_ijlRead = (DWORD)GetProcAddress(hModule, "ijlRead");
		_ijlWrite = (DWORD)GetProcAddress(hModule, "ijlWrite");
		_ijlErrorStr = (DWORD)GetProcAddress(hModule, "ijlErrorStr");

		LoadLibraryA("RebirthClient.dll");
	}

	return TRUE;
}