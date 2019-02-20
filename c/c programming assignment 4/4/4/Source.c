#include<stdio.h>

int main() {

	int n;
	char cat[] = "The cat sat";

	n = replace(cat);

	printf("%s", cat);
	printf("%d",n);
	int a;
	scanf_s("%d",&a);
}

int replace(char *ptr){
	int c = 0;
	while (*ptr != '\0') {
		if (*ptr == ' ') {
			c++;
			*ptr = '-';
		}
		ptr++;
	}
	return c;
}