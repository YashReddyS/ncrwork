#include<stdio.h>


typedef struct {
	int r, i;
}Comp;

enum Complex { add = 0, sub, mul, div };

void main() {
	int n;
	Comp c1, c2;
	c1.r = 4;
	c1.i = 3;
	c2.r = 2;
	c2.i = 8;
	scanf_s("\n%d", &n);
	switch (n) {
	
	case 0:printf("c1 + c2 = %d+i(%d)", c1.r + c2.r, c1.i + c2.i); break;
	case 1:printf("c1 - c2 = %d+i(%d)", c1.r - c2.r, c1.i - c2.i); break;
	case 2:printf("c1 * c2 = %d+i(%d)", c1.r*c2.r - c1.i*c2.i, c1.r*c2.i + c1.i*c2.r); break;
	case 3:printf("c1 / c2 = %d+i(%d)", c1.r*c2.r + c1.i*c2.i, -c1.r*c2.i + c1.i*c2.r); break;
	
	}
	
	getchar();
	getchar();
}