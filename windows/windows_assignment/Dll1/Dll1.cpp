// Dll1.cpp : Defines the exported functions for the DLL application.
//



#include "stdafx.h"
#define EXPORTING_DLL
#include "Dll1.h"


BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	return TRUE;
}

