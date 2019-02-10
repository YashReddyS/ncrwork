#include<stdio.h>

int main() {

	char s[5][25] = {
		"we will teach you how to",
		"Move a mountain",
		"Level a building",
		"Erase the past",
		"Make a million",
	};

	char *ptr = NULL;
	int i, j, c = 0;

	for (i = 0; i < 5; i++) {
		for (j = 0; j <= 25; j++) {
			if (s[i][j] == 'e')
				c++;
		}
	}
	printf("%d", c);
	int a;
	scanf_s("%d", &a);
	return 0;
}
	