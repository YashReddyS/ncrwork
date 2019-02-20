#include<stdio.h>

int main(int argc,char *argv[]) {

	FILE *fp;
	fopen_s(&fp, "Source.c", "r");

	while(!feof(fp)) {
		printf("%c", fgetc(fp));
	}

	getchar();
	return 0;
}