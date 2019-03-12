// 16_createchild_priority.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>

using namespace std;

DWORD WINAPI threadFunction(LPVOID lparam);

int main(int argc, TCHAR *argv[])
{
	HANDLE hProcess = GetCurrentProcess();
	
	if (SetPriorityClass(hProcess, BELOW_NORMAL_PRIORITY_CLASS))
		cout << "BELOW NORMAL PRIORITY CLASS set by the child process" << endl;
	else
		cout << "priority set filed" << endl;


	int lparam;
	DWORD   dwThreadId;
	HANDLE hThread = CreateThread(
		NULL,                   // default security attributes
		0,                      // use default stack size  
		threadFunction,       // thread function name
		&lparam,          // argument to thread function 
		0,                      // use default creation flags 
		&dwThreadId);   // returns the thread identifier 

	if (SetThreadPriority(hThread, THREAD_PRIORITY_LOWEST))
		cout << "thread priority set to lowest" << endl;
	else
		cout << "thread priority set failed" << endl;

}

DWORD WINAPI threadFunction(LPVOID lparam) {
	
	for (int i = 1; i <= 200; i++) {
		system("cls");
		cout << i << endl;
		Sleep(10);
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
