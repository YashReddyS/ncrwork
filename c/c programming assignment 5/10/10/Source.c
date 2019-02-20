#include<stdio.h>
#include<string.h>

void getcap(char *);
void getcou(char *);

void main() {

//	printf("%s", getcap("india"));
	getcap("usa");
	getcou("delhi");
	getchar();
}

void getcap(const char *ip){

	int i = 0;
	FILE *fp;
	fopen_s(&fp, "new.txt", "r+");

	if (fp == NULL)
		printf("err");

	char cou[20], c;
	char cap[20];

	while (!feof(fp)){
		i = 0;
		while ((c = fgetc(fp)) != '-') {
			cou[i++] = c;
		}
		cou[i] = '\0';
		
		i = 0;
		while ((c = fgetc(fp)) != '\n') {
			cap[i++] = c;
		}
		cap[i] = '\0';

		if (strcmp(ip, cou) == 0) {
			printf("\n%s", cap);
			fclose(fp);
			break;
		}
	}
}

void getcou(const char *ip) {

	int i = 0;
	FILE *fp;
	fopen_s(&fp, "new.txt", "r+");

	if (fp == NULL)
		printf("err");

	char cou[20], c;
	char cap[20];

	while (!feof(fp)) {
		i = 0;
		while ((c = fgetc(fp)) != '-') {
			cou[i++] = c;
		}
		cou[i] = '\0';

		i = 0;
		while ((c = fgetc(fp)) != '\n') {
			cap[i++] = c;
		}
		cap[i] = '\0';

		if (strcmp(ip, cap) == 0) {
			printf("\n%s", cou);
			fclose(fp);
			break;
		}
	}
}

