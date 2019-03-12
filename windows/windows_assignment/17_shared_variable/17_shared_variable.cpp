// 16_createchild_priority.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>

#define THREAD_COUNT 100

using namespace std;

DWORD WINAPI threadFunction(LPVOID lparam);

int main(int argc, TCHAR *argv[])
{
	HANDLE hThread[THREAD_COUNT];
	
	int lparam = 0;
	DWORD   dwThreadId[THREAD_COUNT];
	for (int i = 0; i < THREAD_COUNT; i++) {
		 hThread[i] = CreateThread(
			NULL,                   // default security attributes
			0,                      // use default stack size  
			threadFunction,       // thread function name
			&lparam,          // argument to thread function 
			0,                      // use default creation flags 
			&dwThreadId[i]);   // returns the thread identifier 
	}

	WaitForMultipleObjects(2, hThread, TRUE, INFINITE);
	
	cout << lparam << endl;
}

DWORD WINAPI threadFunction(LPVOID lparam) {
	*(int*)lparam = *(int *)lparam + 1;
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
