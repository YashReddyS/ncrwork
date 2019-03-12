// 5_ CreateFile_WriteFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main(int argc,CHAR *argv[])
{
	HANDLE hFile;

	if (argc == 1)
		cout << "failed" << endl;
	else if (argc == 2)
	{

		hFile = CreateFileA(argv[1], GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hFile == INVALID_HANDLE_VALUE)
		{
			cout << "Could not create a File" << endl;
		}
		else
		{
			char content[100];
			DWORD BytesWritten;
			cout << "Enter the string to be written" << endl;
			scanf("%[^\n]s", content);
			int flag = WriteFile(hFile, content, strlen(content), &BytesWritten, NULL);
			if (flag == 0)
			{
				cout << "Failed to Write to File" << endl;
			}
			else if (BytesWritten != strlen(content))
			{
				printf("Written %ld bytes to the file", BytesWritten);
			}
			else
			{
				cout << endl << "Successful" << endl;
			}
		}
	}
	else
		cout << "Failed to Write to File" << endl;	
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
