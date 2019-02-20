#include<stdio.h>

void main() {

	struct str {
		int n;
		char ch;
	};

	union un {
		int n;
		char ch;
	};

	struct str s;
	union un u;

	printf("%d\n", sizeof(s));
	printf("%d", sizeof(u));
	

	getchar();
}