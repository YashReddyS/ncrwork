#include <stdio.h>

int main()
{
	int sum = 0, max, min, i, n, s;
	scanf_s("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}

	scanf_s("%d", &s);

	max = 0;
	min = 0;

	while (max <= n) {
		if (sum == s)
			break;
		else if (sum < s) {
			sum = sum + a[max];
			max++;
			printf("max = %d\n", max);
		}
		else {
			sum = sum - a[min];
			min++;
			printf("min = %d\n", min);
		}
	}
	if (max > n)
		printf("no subarray found");
	else
		printf("%d %d", min, max - 1);
	scanf_s("%d",&s);
	return 0;
}
