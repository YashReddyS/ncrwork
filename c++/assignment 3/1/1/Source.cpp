#include<iostream>

using namespace std;
template <class t>
int linearSearch(t a[],int n,t x) {

	int f = 0;
	for (int i = 0; i < n; i++) {
	
		if (x == a[i]) {
		
			f = 1;
			break;
		
		}
	
	}
	return f;

}

int main() {

	int a[3] = {1,2,3};
	int a1;
	cin >> a1;

	if (linearSearch(a, 3, a1))
		cout << "found";
	else
		cout << "not found";

	float b[3] = { 1,2.245,3 };
	float b1;
	cin >> b1;

	if (linearSearch(b, 3, b1))
		cout << "found";
	else
		cout << "not found";

	double c[3] = {1,2,3.342342323};
	double c1;
	cin >> c1;

	if (linearSearch(c, 3, c1))
		cout << "found";
	else
		cout << "not found";






	getchar();
	getchar();
	return 0;
}