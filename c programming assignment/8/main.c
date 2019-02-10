#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n,sum=0;

   scanf("%f",&n);
   float hr=0,dr=0;
   if(n>=1&&n<=4000)
        {
            hr=n*0.10;
            dr=n*0.50;
  }
  else if(n>=4001&&n<=8000)
  {
      hr=n*0.20;
      dr=n*0.60;
  }
  else if(n>=8001&&n<=12000)
  {
    hr=n*0.25;
    dr=n*0.75;
  }
  else if(n>=12001)
  {
    hr= n*0.30;
    dr= n*0.80;
  }
    sum=n+hr+dr;
    printf("%.0f",sum);
}
