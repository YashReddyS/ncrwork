// 7_calc.ex_notepad.exe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>

using namespace std;

int main(int argc,TCHAR *argv[])
{
	HANDLE hProcess[2];
	STARTUPINFO si[2];
	PROCESS_INFORMATION pi[2];

	int No_of_Processes = 2;
	for (int i = 0; i < 2; i++)
	{
		ZeroMemory(&si[i], sizeof(si[i]));
		si[i].cb = sizeof(si[i]);
		ZeroMemory(&pi[i], sizeof(pi[i]));

		CreateProcess(NULL, argv[i + 1], NULL, NULL, FALSE, 0, NULL, NULL, &si[i], &pi[i]);
		cout << "Process Id - " << pi[i].dwProcessId << endl;
		cout << "Handle Id - " << pi[i].hProcess << endl;
	
	}
	for (int i = 0; i < 2; i++) {
		WaitForSingleObject(pi[i].hProcess, INFINITE);
		CloseHandle(pi[i].hProcess);
		CloseHandle(pi[i].hThread);
	}
	system("pause");
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
