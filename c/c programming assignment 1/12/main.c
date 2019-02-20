#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,b;

    scanf("%d",&n);
    scanf("%d",&b);

    printf("%d",rotate_right(n,b));

    return 0;
}

int rotate_right(int n,int b){

int m = n,p = 0;

    while(m>0){
        m = m / 10;
        p++;
    }

    while(b--){
       n = n/10 + (n % 10)*pow(10,p-1);
    }

    return n;
}
