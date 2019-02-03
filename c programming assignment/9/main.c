#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i = 1;i<= n;i++){

        for(j = n;j>=1;j--){
         if(j<=i)
            printf("%d ",j);
         else
            printf("  ");
        }

        for(j = 2;j<=n;j++){
         if(j > i)
            break;
         printf("%d ",j);
        }

        printf("\n");

    }
}
