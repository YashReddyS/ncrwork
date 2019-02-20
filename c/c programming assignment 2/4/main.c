#include<stdio.h>

int main()
{
	int a, b,c=0,i,j;
	scanf("%d%d", &a, &b);
	for (i = a;i <= b;i++)
	{
		for (j = 2;j*j <= i;j++)
		{
			if (i%j == 0)
				c++;

		}
		if (c<1)
		{
			printf("%d\n", i);
		}
		c = 0;
	}
	scanf("%d",c);
	return 0;
}
