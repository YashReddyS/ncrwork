#include<stdio.h>

struct Time{
	int hh,mm,ss;
};
void main(){
	struct Time t1,t2;
	t1.hh=11;
	t1.mm=23;
	t1.ss=48;
	printf("The time is %d:%d:%d",t1.hh,t1.mm,t1.ss);
	getch();
}