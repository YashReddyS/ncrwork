#include<stdio.h>
#include<string.h>

int main() {

	
	char s1[20], s2[20];

	scanf_s("%s", s1);
	scanf_s("%s", s2);

	printf("%d",any(s1, s2));

	int a;
	scanf_s("%d", &a);
	return 0;
}

int any(char *s1, char *s2) {
	int i,j;
	for (i = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++) {
			if (strcmp(s1+i, s2+j) == 0)
				return i;
		}
	}
	return -1;
}