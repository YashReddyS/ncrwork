#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void deletecommon(char *, char *);
int delete(char *, char);

int main()
{
	char *s2 = (char *)malloc(sizeof(char));
	char *s1 = (char *)malloc(sizeof(char));

	scanf("%s", s1);
	fflush(stdin);
	scanf("%s", s2);

	deletecommon(s1,s2);

	printf("\n%s", s1);
	printf("\n%s",s2);

	return 0;
}

void deletecommon(char *sp1, char *sp2) {
	while (*sp1 != '\0') {
		if(delete(sp2, *sp1)){
			delete(sp1, *sp1);
			continue;
		}
		if (*sp1 == '\0')
			break;
		sp1++;
	}
}


int delete(char *str, char c) {
	char *ptr = str;
	int present = 0;
	while (*str != '\0') {
		if (*str != c) {
			*ptr = *str;
			ptr++;
		}
		else
			present = 1;
		str++;
	}
	*ptr = '\0';
	return present;
}
