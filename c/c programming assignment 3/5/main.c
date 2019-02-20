#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[8]= {10,20,30,40,50,60,70,80};
    printf("\n%d",x);
    printf("\n%d",(x+2));
    printf("\n%d",*x);
    printf("\n%d",(*x+2));
    printf("\n%d",*(x+2));

}
