#include <stdio.h>
#include <limits.h>

int main()
{
    int sum = 0;
    float c = 0;
    int n = 1;
    int min = INT_MAX;
    int max = INT_MIN;
    while(1 == 1){
        scanf("%d",&n);
        if(n<0)
            break;
        c++;
        sum = sum + n;
        if(max<n)
            max = n;
        if(min>n)
            min = n;
    };
    printf("%d ",c);
    printf("%f ",sum/c);
    printf("%d ",max);
    printf("%d ",min);
    return 0;
}
