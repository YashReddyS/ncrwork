// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#define MYLIB_EXPORTS
#include "Dll1.h"
#include<iostream>

using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
	case DLL_PROCESS_ATTACH:cout << "DLL process attached" << endl; break;
    case DLL_THREAD_ATTACH:cout << "DLL thraed attached" << endl; break;
    case DLL_THREAD_DETACH:cout << "DLL thread detached" << endl; break;
    case DLL_PROCESS_DETACH:cout << "DLL process detached" << endl; break;
  
    }
    return TRUE;
}

int add(int op1, int op2)
{
	return op1 + op2;
}

int  sub(int op1, int op2)
{
	return op1 - op2;
}

int  mul(int op1, int op2)
{
	return op1 * op2;
}

int  divi(int op1, int op2)
{
	return op1 / op2;
}


