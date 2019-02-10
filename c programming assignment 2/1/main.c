#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);

    b2d(a);
    d2b(b);
}

void b2d(int n){
    int sum = 0,b=1;
    while(n>0){
            sum = sum + b*n%10;
            n = n/10;
            b = b*2;
    }
    printf("\n%d",sum);
}

void d2b(int n){
    int binaryNum[1000];

    int i = 0,j;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

   printf("\n");
    for (j = i - 1; j >= 0; j--)
        printf("%d",binaryNum[j]);


}
