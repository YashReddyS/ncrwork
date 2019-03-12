// 29_semaphores.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<iostream>
#include<windows.h>

using namespace std;
#define THREADCOUNT 4
#define SEM_COUNT 2

HANDLE ghSemaphore;
DWORD WINAPI ThreadFunction(LPVOID lpParam);

int main()
{
	HANDLE hThreads[THREADCOUNT];
	DWORD dwThreadId;

	ghSemaphore = CreateSemaphore(
		NULL,           // default security attributes
		SEM_COUNT,  // initial count
		SEM_COUNT,  // maximum count
		NULL);

	if (ghSemaphore == NULL)
	{
		cout << "Creation of Semaphore Failed" << endl;
	}

	for (int i = 0; i < THREADCOUNT; i++)
	{
		hThreads[i] = CreateThread(NULL, 0, ThreadFunction, NULL, 0, &dwThreadId);
		if (hThreads[i] == NULL)
		{
			cout << "Creation of Thread " << (i + 1) << " Failed" << endl;
		}
	}

	WaitForMultipleObjects(THREADCOUNT, hThreads, TRUE, INFINITE);

	for (int i = 0; i < THREADCOUNT; i++)
	{
		CloseHandle(hThreads[i]);
	}
	CloseHandle(ghSemaphore);
	system("pause");
}
DWORD WINAPI ThreadFunction(LPVOID lpParam)
{
	DWORD dwResult;
	dwResult = WaitForSingleObject(ghSemaphore, 0);

	switch (dwResult)
	{
	case WAIT_OBJECT_0:cout << "Inside the Thread with Id " << GetCurrentThreadId() << endl;
		long count;
		if (!ReleaseSemaphore(ghSemaphore, 1, &count))
		{
			cout << "Failed to Release Semaphore" << endl;
		}
		cout << "Semaphore Count is - " << count << endl;
		break;
	case WAIT_TIMEOUT:cout << "Wait Timeout..Id - " << GetCurrentThreadId() << endl;
		break;
	}
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
