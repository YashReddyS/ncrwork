// 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>

using namespace std;

int main()
{
	HANDLE hFile;
	
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	/*typedef struct _SECURITY_ATTRIBUTES {
		DWORD nLength;
		LPVOID lpSecurityDescriptor;
		BOOL bInheritHandle;
	} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;*/

	SECURITY_ATTRIBUTES s;
	s.bInheritHandle = TRUE;
	s.lpSecurityDescriptor = NULL;
	s.nLength = sizeof(s);
	
	

	hFile = CreateFile(L"test.txt", // name of the write
		GENERIC_ALL,          // open for writing
		FILE_SHARE_WRITE,       //share with child
		&s,                   
		CREATE_ALWAYS,             
		FILE_ATTRIBUTE_NORMAL,  // normal file
		NULL);                  // no attr. template

	TCHAR s1[] = { (TCHAR)hFile };
	
	CreateProcess(L"C:\\Users\\DELL\\Desktop\\ncrwork\\windows\\10\\Debug\\10.exe",   // No module name (use command line)
		s1,        // Command line
		&s,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable#
		TRUE,          // Set handle inheritance to TRUE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,            // Pointer to STARTUPINFO structur
		&pi           // Pointer to PROCESS_INFORMATION structure
		);


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
