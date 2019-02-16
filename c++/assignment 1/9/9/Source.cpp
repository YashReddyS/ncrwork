#include<iostream>

using namespace std;

void swap_value(int a, int b) {

	a = a + b;
	b = a - b;
	a = a - b;

}

void swap_reference(int &a, int &b) {

	a = a + b;
	b = a - b;
	a = a - b;
}

int main() {
	
	int a,b,n;

	cin >> a;
	cin >> b;
	cout << "enter your choice" << endl;

	cin >> n;

	switch (n) {
		
	case 1: swap_value(a, b); break;
	case 2: swap_reference(a, b); break;

	}

	cout << a << " " << b << endl;

	getchar();
	return 0;
}



