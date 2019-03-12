// 24_reason_WaitForSingleObject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<iostream>
#include<windows.h>

using namespace std;

DWORD WINAPI ThreadFunction1(LPVOID lpParam);
DWORD WINAPI ThreadFunction2(LPVOID lpParam);
DWORD WINAPI ThreadFunction3(LPVOID lpParam);

void CheckReturn(DWORD returnvalue)
{
	switch (returnvalue)
	{
	case WAIT_ABANDONED: cout << "Wait Abandoned Id - " << GetCurrentThreadId() << endl;
		break;
	case WAIT_TIMEOUT:cout << "TimeOut Expired Id - " << GetCurrentThreadId() << endl;
		break;
	case WAIT_OBJECT_0:cout << "Object Signalled Id - " << GetCurrentThreadId() << endl;
		break;
	case WAIT_FAILED:cout << "Wait Failed Id - " << GetCurrentThreadId() << " Error - " << GetLastError() << endl;
		break;
	}
}
int main()
{
	HANDLE hThread1, hThread2, hThread3;
	DWORD dwThreadId;

	hThread1 = CreateThread(NULL, 0, ThreadFunction1, NULL, 0, &dwThreadId);
	cout << "Thread 1 - " << GetThreadId(hThread1);
	CheckReturn(WaitForSingleObject(hThread1, INFINITE));
	hThread2 = CreateThread(NULL, 0, ThreadFunction2, NULL, 0, &dwThreadId);
	cout << "Thread 2 - " << GetThreadId(hThread2);
	CheckReturn(WaitForSingleObject(hThread2, 1000));
	hThread3 = CreateThread(NULL, 0, ThreadFunction3, NULL, 0, &dwThreadId);
	cout << "Thread 3 - " << GetThreadId(hThread3);
	CheckReturn(WaitForSingleObject(hThread3, 1000));

	CloseHandle(hThread1);
	CloseHandle(hThread2);
	CloseHandle(hThread3);

	system("pause");
}
DWORD WINAPI ThreadFunction1(LPVOID lpParam)
{
	cout << "In Thread 1" << endl;
	return 0;
}
DWORD WINAPI ThreadFunction2(LPVOID lpParam)
{
	cout << "In Thread 2" << endl;
	return 0;
}
DWORD WINAPI ThreadFunction3(LPVOID lpParam)
{
	cout << "In Thread 3" << endl;
	Sleep(2000);
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
