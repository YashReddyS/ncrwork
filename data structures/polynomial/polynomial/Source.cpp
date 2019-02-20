#include<iostream>
#include<list>

using namespace std;

struct pol {
	int pow;
	int coeff;
};

int main() {

	int a[2];

	list <int []> p1;
	list <itn []> p2;


	struct pol p[6]
		
	p1.push_back(1);
	p1.push_back(2);
	p1.push_back(3);

	p2.push_back(4);
	p2.push_back(5);
	p2.push_back(6);



	list <int> p3;
	for (int i = 0; i < 3; i++) {

		p3.push_back(p1.front() + p2.front());
		p1.pop_front();
		p2.pop_front();
	}


	for (auto itr = p3.begin(); itr != p3.end(); itr++)
		cout << *itr << " ";



	

	getchar();
	return 0;
}