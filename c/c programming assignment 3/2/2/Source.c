#include<stdio.h>
int main() {

	int n,i,t;
	scanf_s("%d",&n);
	int *a = (int *)malloc(n * sizeof(int));

	for (i = 0; i < n; i++) {
		scanf_s("%d",&a[i]);
	}
	int j = 0;
	for (i = 0; i < n; i++) {
		if (a[i] < 0) {
			if (i != j) {
				t = a[j];
				a[j] = a[i];
				a[i] = t;
			}
			j++;
		}
	}

	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	scanf_s("%d", &t);
;	return 0;
}