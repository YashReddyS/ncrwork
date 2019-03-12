#include<stdio.h>
#include<stdlib.h>

int strlen1(char *s) {
	int count = 0;
	while (s[count++] != '\0');
	return count-1;
}
void strrev1(char *str) {

	char *p1, *p2;
	char temp;
	for (p1 = str, p2 = str + strlen(str) - 1; p1 < p2; p1++, p2--) {
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}

}
void strcpy1(char *s1, char *s2) {

	while (*s2 != '\0')
	{
		*s1++ = *s2++;
	}	
}
void strcat1(char *s1, char *s2) {

	int i = strlen(s1), j;
	for (j = 0; s2[j] != '\0'; i++, j++) {
		s1[i] = s2[j];
	}
	s1[i] = '\0';
}
int strcmp1(char *s1, char *s2) {
	int ret;
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			break;
		if (*s2 == '\0')
			break;
		s1++;
		s2++;
	}
	return *s1 - *s2;
}

int main()
{
	int choice;

	char str1[50];
	char str2[50];

	while (1) {

		int choice;
		printf_s("Enter 1st string:");
		gets(str1);
		printf_s("Enter 2nd string:");
		gets(str2);

		printf_s("--- enter Your Choice ---\n");
		printf_s("1.String Compare\n");
		printf_s("2.String Concat\n");
		printf_s("3.String Reverse\n");
		printf_s("4.String Copy\n");
		printf_s("5.String length\n");
		printf_s("6.Exit\n");
		printf_s("choice:");

		scanf_s("%d",&choice);

		switch (choice)
		{
		case 1:printf_s("Output of strcmp function is %d\n",strcmp1(str1,str2));break;
		case 2: strcat1(str1,str2);break;
		case 3: strrev1(str1);break;
		case 4: strcpy1(str1,str2);break;
		case 5: printf_s("Length of first string is %d",strlen1(str1)); break;
		case 6: exit(1); break;
		default: printf_s("enter the right choice");
		}

		printf_s("1st string:%s\n", str1);
		printf_s("2nd string:%s\n", str2);

		getchar();

		printf_s("Press 'Y' to continue,any other to exit:");
		if ('y' == getchar()) {
			getchar();
			system("cls");
		}
		else
			exit(0);
	}

	
	getchar();
	return 0;
}