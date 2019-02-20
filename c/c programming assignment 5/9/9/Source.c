#include<stdio.h>

int main() {

	FILE *fp;
	fopen_s(&fp, "new.txt", "w+");

	if (fp == NULL)
		printf("err");

	char ch;
	while ((ch = getchar())!= '\n') {
		if (ch >= 65 && ch <= 90) {
			ch = ch + 32;
			fputc(ch, fp);
		}

		else if (ch >= 97 && ch <= 122) {
			ch = ch - 32;
			fputc(ch, fp);
		}

		else {
			fputc(ch, fp);
		}


	}

	getchar();
	return 0;

}