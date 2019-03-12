// 1_multiByteToWideChar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>

using namespace std;

int main()
{
	char ANSIString[100];
	cout << "Enter the ANSI String to be converted" << endl;
	cin >> ANSIString;

	wchar_t WCHARString[100];
	cout << "Enter the wide character string to be converted" << endl;
	wcin >> WCHARString;

	char *ConvertedWCHAR;
	wchar_t *ConvertedANSI;
	int buffer_size;
	
	buffer_size = MultiByteToWideChar(CP_UTF8, 0, ANSIString, -1, NULL, 0);
	ConvertedANSI = new wchar_t[buffer_size];

	int flag = MultiByteToWideChar(CP_UTF8, 0, ANSIString, -1, ConvertedANSI, buffer_size);
	if (flag == 0)
		cout << "Conversion to Wide_Char failed" << endl;
	else
		wcout << "Corresponding Wide Character String for ANSI String is - " << ConvertedANSI << endl;
	buffer_size = WideCharToMultiByte(CP_UTF8, 0, WCHARString, -1, NULL, 0, NULL, NULL);
	ConvertedWCHAR = new char[buffer_size];
	
	flag = WideCharToMultiByte(CP_UTF8, 0, WCHARString, -1, ConvertedWCHAR, buffer_size, NULL, NULL);
	if (flag == 0)
		wcout << "Conversion to ANSI Failed" << endl;
	else
		cout << "Corresponding ANSI Character String for Wide Character is -" << ConvertedWCHAR << endl;

	delete(ConvertedWCHAR);
	delete(ConvertedANSI);
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
