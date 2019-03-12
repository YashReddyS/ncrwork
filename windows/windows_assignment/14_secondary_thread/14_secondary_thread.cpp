// 12_implement_threads.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>
#include<stdlib.h>


using namespace std;


/*HANDLE CreateThread(
	LPSECURITY_ATTRIBUTES   lpThreadAttributes,
	SIZE_T                  dwStackSize,
	LPTHREAD_START_ROUTINE  lpStartAddress,
	__drv_aliasesMem LPVOID lpParameter,
	DWORD                   dwCreationFlags,
	LPDWORD                 lpThreadId
)*/;

DWORD WINAPI threadFunction(LPVOID lpParam);

int main()
{
	DWORD dwThreadId;
	HANDLE hThread;
	int thread_arg;
	DWORD exit_code;

	hThread = CreateThread(
		NULL,                   // default security attributes
		0,                      // use default stack size  
		threadFunction,       // thread function name
		&thread_arg,          // argument to thread function 
		0,                      // use default creation flags 
		&dwThreadId);   // returns the thread identifier 	

	if (hThread == NULL)
		ExitProcess(3);
	else
		cout << "Thread created" << endl;
	
	WaitForSingleObject(hThread, 15000);
	GetExitCodeThread(hThread, &exit_code);
	
	cout << "thread execution completed with exit code " << exit_code << endl;

	cout << "this is primary thread" << endl;

	getchar();
	return 0;
}



DWORD WINAPI threadFunction(LPVOID thread_arg) {

	for (int i = 1; i <= 200; i++) {
		system("cls");
		cout << i << endl;
		Sleep(1);
	}

	cout << "thread execution finished" << endl;
	ExitThread(4);
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
