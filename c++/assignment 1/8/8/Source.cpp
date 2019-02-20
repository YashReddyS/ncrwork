#include<iostream>

using namespace std;

class Employee {
	float sal;
	int rollno;
public:
	Employee() {
		rollno = 0;
		sal = 0;
		cout << "Created" << endl;
	}
	Employee(int rn, float s) {
		sal = s;
		rollno = rn;
		cout << "Created" << endl;
	}
	void display(Employee e) {
		cout << endl << "Called by Value :" << endl << e.sal << endl << e.rollno << endl << "//It will create a new object" << endl;
	}
	void display1(Employee &e) {
		cout << endl << "Called by Reference :" << endl << e.sal << endl << e.rollno << endl << "//It will not create a new object" << endl;
	}
	void size() {
		cout << endl << "Size is : " << sizeof(*this) << endl;
	}
	~Employee() {
		cout << endl << "Destroyed";
	}
};

int main() {
	{
		Employee e1, e2(10, 200);
		e1.display(e1);
		e1.display1(e1);
		e1.size();
		e2.display(e2);
		e2.display1(e2);
		e2.size();
	}
	cout << endl;
	system("pause");
}