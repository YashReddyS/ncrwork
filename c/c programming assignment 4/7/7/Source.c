#include<stdio.h>
#include<string.h>

int main() {

	int n, i, j;
	scanf_s("%d", &n);

	int **arr = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		arr[i] = (int *)malloc(10 * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf_s("%s", arr[i]);
	}

	char temp[20];
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (strcmp(arr[i], arr[j]) > 0) {
				strcpy_s(temp,20, arr[i]);
				strcpy_s(arr[i],20 ,arr[j]);
				strcpy_s(arr[j],20 ,temp);
			}
		}
	}

	for (i = 0; i < n; i++) {
		printf("%s\n", arr[i]);
	}

	int a;
	scanf_s("%d", &a);
	return 0;
}