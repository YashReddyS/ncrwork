#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);

    itob(n);
    printf("\n");
    itoh(n);
}

void itoh(int n)
{
 int a[16]={0},i=0,j;
 while(n>0)
 {
     a[i++]=n%16;
     n=n/16;
 }
 for(j=i-1;j>=0;j--)
 printf("%x",a[j]);
}

void itob(int n)
{
 int a[16]={0},i=0,j;
 while(n>0)
 {
     a[i++]=n%2;
     n=n/2;
 }
 for(j=i-1;j>=0;j--)
 printf("%d",a[j]);
}
