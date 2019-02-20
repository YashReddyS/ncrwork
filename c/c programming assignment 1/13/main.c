#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,p,b;

    scanf("%d",&n);
    scanf("%d",&p);
    scanf("%d",&b);

    invertponwards(n,p,b);

}

void invertponwards(int n,int p,int b){

    int i = 0,j;
    int sum = 0,base = 1;
    while (n > 0) {
        if(i >= p && i < p+b){
            sum = sum + base*!(n%2);
        }
        else{
            sum = sum + base*(n%2);
        }
        n = n / 2;
        base = base * 2;
        i++;
    }
        printf("\n%d",sum);
}
