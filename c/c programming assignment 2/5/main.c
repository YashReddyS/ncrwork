#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    scanf("%d",&n);

    rev(n);

    return 0;
}

void rev(int n){
    while(n>0){
        printf("%d",n%10);
        n = n/10;
    }
}
