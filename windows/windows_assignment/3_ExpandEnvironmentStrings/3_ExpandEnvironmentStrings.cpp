// 3_ExpandEnvironmentStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>

using namespace std;

int main()
{
	const DWORD buffSize = 50;
	char *buffer = new char[buffSize];
	int flag = GetEnvironmentVariableA("TEMP", buffer, buffSize);

	if (flag != 0 && flag < buffSize)
	{
		buffer[flag + 1] = '\0';
		cout << buffer << endl;
	}
	else if (buffSize < flag)
	{
		buffer = new char[flag + 1];
		buffer[flag + 1] = '\0';
		GetEnvironmentVariableA("TEMP", buffer, buffSize);
		cout << buffer << endl;
	}
	else
		cout << "Failed" << endl;

	delete(buffer);
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
