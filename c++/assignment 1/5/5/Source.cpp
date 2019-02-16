#include<iostream>

using namespace std;

class distance1;
class distance2;

class distance1{

	float meters;
	float centimeters;

	distance1() {
		meters = 0;
		centimeters = 0;
	}

	distance1(float a,float b) {
		meters = a; 
		centimeters = b;
	}

	friend class distance2;

	
	void disp() 
	{
		cout << meters << endl;
		cout << centimeters << endl;
	}

	void add(distance1 d1, distance2 d2);
	friend int main();
	
};


class distance2{

	float feet;
	float inches;

	distance2(float a, float b) {
		feet = a;
		inches = b;
	}

	friend class distance1;

	
	void disp()
	{
		cout << feet << endl;
		cout << inches << endl;
	}

	void add(distance1 d1, distance2 d2);
	friend int main();
};
void distance2::add(distance1 d1, distance2 d2) {

	feet = d1.meters*3.28084 + d2.feet;
	inches = d1.centimeters*0.393701 + d2.inches;

}

void distance1::add(distance1 d1, distance2 d2) {

	meters = d1.meters + d2.feet*0.3048;
	centimeters = d1.centimeters + d2.inches*2.54;

}


int main(){

	distance1 d1(1, 1);
	distance2 d2(1, 1);

	distance1 d3;

	d3.add(d1, d2);

	d3.disp();


	getchar();
	return 0;
}