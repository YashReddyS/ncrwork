#include<stdio.h>

int main() {


	int n, i;

	scanf_s("%x", &n);

	int t = n;

	int sum = 0, m = 1;

	for (i = 0; i < 4; i++) {

		sum = sum + (m & t);
		t = t >> 1;

	}
	if (sum > 2)
		printf("atleast 3 are on\n");
	else
		printf("atleast 3 are not on \n");

	t = n;
	sum = 0;
	int b = 16;

	while (t > 0) {
		//printf("%x\n", t % 16);
		//printf("%x\n", sum*b);
		sum = sum * 16 + t % 16;
		t = t / 16;	
	}
	printf("%x\n", sum);
	t = n;
	
	printf("%x", (t % 16)*16*16*16 + t / 16);

	

	





	getchar();
	getchar();
	return 0;
}