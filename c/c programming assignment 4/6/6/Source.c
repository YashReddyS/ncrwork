#include<stdio.h>

int main() {

	char str[10];
	scanf_s("%s", str);
	rev(str);
	int a;
	scanf_s("%d", &a);
	return 0;
}

int rev(char *s) {
	if (*s == '\0')
		return;
	rev(s + 1);
	printf("%c", *s);

}