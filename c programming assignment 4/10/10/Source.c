#include<stdio.h>

void delete(char *, char);

int main() {

	char s1[10],c;

	scanf_s("%s", s1);
	fflush(stdin);
	scanf_s("%c", &c);

	delete(s1, c);

	printf("%s", s1);

	int b;
	scanf_s("%d", &b);
	return 0;
}

void delete(char *str, char c) {
	char *ptr = str;
	while(*str != '\0') {
		if (*str != c) {
			*ptr = *str;
			ptr++;
		}
		str++;
	}
	*ptr = '\0';
}