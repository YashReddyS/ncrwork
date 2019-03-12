// 19_initialize_critical_section.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<Windows.h>

#define THREAD_COUNT 50

DWORD WINAPI threadFunction(LPVOID lparam);

using namespace std;

CRITICAL_SECTION csCriticalSection;
int iCriticalSectionData = 0;

int main()
{
	HANDLE hThread[THREAD_COUNT];
	DWORD   dwThreadIdArray[THREAD_COUNT];
	LPVOID pDataArray[THREAD_COUNT];

	//HANDLE CreateThread(
	//	LPSECURITY_ATTRIBUTES   lpThreadAttributes,
	//	SIZE_T                  dwStackSize,
	//	LPTHREAD_START_ROUTINE  lpStartAddress,
	//	__drv_aliasesMem LPVOID lpParameter,
	//	DWORD                   dwCreationFlags,
	//	LPDWORD                 lpThreadId
	//)


	

	InitializeCriticalSection(&csCriticalSection);

	for (int i = 0; i < THREAD_COUNT; i++) {

		hThread[i] = CreateThread(
			NULL,                   // default security attributes
			0,                      // use default stack size  
			threadFunction,       // thread function name
			pDataArray[i],          // argument to thread function 
			0,                      // use default creation flags 
			&dwThreadIdArray[i]);
	}

	WaitForMultipleObjects(THREAD_COUNT,hThread,TRUE,INFINITE);

	DeleteCriticalSection(&csCriticalSection);
	cout << iCriticalSectionData << endl;
}

DWORD WINAPI threadFunction(LPVOID lparam) {

	EnterCriticalSection(&csCriticalSection);

	iCriticalSectionData++;

	LeaveCriticalSection(&csCriticalSection);

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
