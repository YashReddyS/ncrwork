#include <stdio.h>
#include <stdlib.h>

float si(float,float,float);
float ci(float,float,float,int);

int main()
{
    float p,r,t;

    scanf("%f",&p);
    scanf("%f",&t);
    scanf("%f",&r);

    printf("%f\n",si(p,t,r));
    printf("%f\n",ci(p,t,r,1));
    printf("%f\n",ci(p,t,r,2));
    printf("%f\n",ci(p,t,r,4));
    printf("%f\n",ci(p,t,r,12));
    printf("%f\n",ci(p,t,r,365));
    return 0;
}

float si(float p,float t,float r){
return (p * t * r)/100 ;
}

float ci(float p,float t,float r,int n){
    return  p * (pow(1 + (r / (n * 100)),n*t)) - p;
}
