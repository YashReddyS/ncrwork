#include<stdio.h>

int main(int argc,int *argv) {

	FILE *fp;
	fopen_s(&fp, argv[1], "w+");

	if (fp == NULL)
		printf("err");

	char ch;
	while ((ch = getchar()) != '\n') {
			fputc(~ch, fp);
	}

	fseek(fp, 0, SEEK_SET);

	printf("\n");
	while (!feof(fp)) {
		printf("%c", ~fgetc(fp));
	}

	getchar();
	return 0;

}