#include<iostream>

using namespace std;

class employee {

	int empno;
	char name[20];
	int salary;


public:
	void set_data() {
		cin >> *this;
	}

	void read_data(){
		cout << *this<<endl;
	}

	friend istream& operator>>(istream &, employee&);
	friend ostream& operator<<(ostream &, employee);

};

istream& operator>>(istream &cin, employee &e) {

	cin >> e.empno;
	cin >> e.name;
	cin >> e.salary;

	return cin;
}

ostream& operator<<(ostream &cout, employee e) {

	cout << e.empno;
	cout << e.name;
	cout << e.salary;

	return cout;
}



int main() {

	employee e[2];

	for(int i = 0;i<2;i++)
	e[i].set_data();

	for (int i = 0; i < 2; i++)
	e[i].read_data();



	getchar();
	getchar();
	return 0;
}


