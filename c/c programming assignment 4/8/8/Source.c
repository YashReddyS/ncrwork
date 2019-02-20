#include<stdio.h>
#include<string.h>

int main() {

	int n, i;
	scanf_s("%d", &n);

	char *p[10];

	for (i = 0; i < n; i++)
		p[i] = (int *)malloc(10 * sizeof(int));

	for (i = 0; i < n; i++)
		scanf_s("%s", p[i]);

	for (i = 0; i < n; i++)
		printf("%s", p[i]);

	int a;
	scanf_s("%d", &a);


	return 0;
}