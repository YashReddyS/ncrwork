#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,r,sum = 0;
    scanf("%d",&n);

    while (n != 0)
    {
        r = n%10;
        sum += r*r*r;
        n /= 10;
    }

    if(sum == n)
        printf("Armstrong number");
    else
        printf("not an Armstrong number");

    return 0;
}
