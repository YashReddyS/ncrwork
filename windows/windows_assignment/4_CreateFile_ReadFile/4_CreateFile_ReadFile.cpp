// 4_CreateFile_ReadFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <windows.h>

#define SIZE 20

using namespace std;

int main()
{
	HANDLE File_Ptr;
	DWORD dword = 1;
	char buffer[SIZE] = { 0 };

	File_Ptr = CreateFileA(
		"readme.txt",
		GENERIC_READ,
		0, 
		NULL, 
		OPEN_EXISTING, 
		FILE_ATTRIBUTE_READONLY,
		NULL);
	if (File_Ptr == INVALID_HANDLE_VALUE)
	{
		cout << "Couldn't Open File" << endl;
	}
	else
	{
		int offset = 19;
		while (1)
		{
			if (FALSE == ReadFile(File_Ptr, buffer, offset, &dword, NULL))
			{
				cout << "Couldn't Read File" << endl;
			}
			else if (dword == offset)
			{
				buffer[offset] = '\0';
				cout << buffer;
			}
			else if (dword == 0)
			{
				cout << endl << "END OF FILE" << endl;
				break;
			}
			else if (dword < offset)
			{

				buffer[dword] = '\0';
				cout << buffer;
			}
		}
	}
	CloseHandle(File_Ptr);
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
