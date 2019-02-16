#include<iostream>

using namespace std;

class complex {

	float real;
	float imag;

public:

	complex() {
	}

	complex(float a) {
		real = a;
		imag = a;
	}

	complex(float a,float b) {
		real = a;
		imag = b;
	}


	friend void mul(complex &, complex &);
	friend void add(complex &, complex &);
	
};

void add(complex &a,complex &b) {

	printf("\n%f + ", a.real + b.real);
	printf("i%f\n", a.imag + b.imag);

}

void mul(complex &a, complex &b) {

	printf("\n%f + ", (a.real * b.real) - (a.imag + b.imag));
	printf("i%f\n", (a.real * b.imag) + (a.imag * b.real));

}



int main() {

	complex c1(3, 5);
	complex c2(2, 4);

	add(c1,c2);
	mul(c1, c2);


	getchar();
	return 0;
}