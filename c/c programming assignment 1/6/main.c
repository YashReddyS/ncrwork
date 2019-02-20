#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i,n,k;
    scanf("%d",&n);
    printf("1");
    for (i = 4; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            printf("1");
        else
            printf("0");
    }
    return 0;

}
