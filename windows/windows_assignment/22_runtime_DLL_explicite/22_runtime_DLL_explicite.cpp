// 21_implement_DLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<windows.h>

using namespace std;

int main()
{
	typedef VOID(*DLLPROC) (LPTSTR);
	
	HINSTANCE hinstDLL;
	int (*fun)(int,int);
	BOOL fFreeDLL;

	int op1, op2;
	cout << endl << "enter first operand:";
	cin >> op1;
	cout << "enter second operand:";
	cin >> op2;

	hinstDLL = LoadLibrary(L"Dll1.dll");

	if (hinstDLL != NULL)
	{
		fun = (int (*)(int, int))GetProcAddress(hinstDLL, "add");
		if (fun != NULL)
			cout << op1 << "+" << op2 << "=" << fun(op1, op2) << endl;

		fun = (int(*)(int, int))GetProcAddress(hinstDLL, "sub");
		if (fun != NULL)
			cout << op1 << "-" << op2 << "=" << fun(op1, op2) << endl;

		fun = (int(*)(int, int))GetProcAddress(hinstDLL, "mul");
		if (fun != NULL)
			cout << op1 << "*" << op2 << "=" << fun(op1, op2) << endl;

		fun = (int(*)(int, int))GetProcAddress(hinstDLL, "divi");
		if (fun != NULL)
			cout << op1 << "/" << op2 << "=" << fun(op1, op2) << endl;


		fFreeDLL = FreeLibrary(hinstDLL);
	}

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
