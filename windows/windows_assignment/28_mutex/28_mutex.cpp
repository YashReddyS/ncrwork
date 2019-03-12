// 28_mutex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<iostream>
#include<windows.h>

#define THREADCOUNT 8

using namespace std;

HANDLE hMutex;
DWORD WINAPI ThreadFunction(LPVOID lpParam);

int main()
{
	HANDLE hThreads[THREADCOUNT];
	DWORD dwThreadId;
	hMutex = CreateMutexA(NULL, FALSE, "Global_Mutex");

	if (hMutex == NULL)
	{
		cout << "Creation of Mutex Failed" << endl;
	}
	for (int i = 0; i < THREADCOUNT; i++)
	{
		hThreads[i] = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId);
		if (hThreads[i] == NULL)
		{
			cout << "Creation of Thread " << (i + 1) << " Failed" << endl;
		}
	}

	WaitForMultipleObjects(8, hThreads, TRUE, INFINITE);

	for (int i = 0; i < THREADCOUNT; i++)
		CloseHandle(hThreads[i]);
	CloseHandle(hMutex);
	
	system("pause");
}
DWORD WINAPI ThreadFunction(LPVOID lpParam)
{
	DWORD dwWaitResult;
	dwWaitResult = WaitForSingleObject(hMutex, INFINITE);
	switch (dwWaitResult)
	{
	case WAIT_OBJECT_0:cout << "In Thread ...With Id " << GetCurrentThreadId() << endl;
		Sleep(2000);
		ReleaseMutex(hMutex);
		break;
	case WAIT_ABANDONED:return FALSE;
		break;
	}
	return TRUE;
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
