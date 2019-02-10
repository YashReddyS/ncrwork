#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a,b;
    scanf("%x",&a);
    scanf("%d",&b);

   b2h(b);
    h2b(a);
}

void h2b(int h) {
	if (h == 0x0)
		return;
	h2b(h / 16);
	printf("%d",hex2bin(h % 16));
}

int hex2bin(int h) {
	switch (h) {
	case 0:return 0000;
	case 1:return 0001;
	case 2:return 0010;
	case 3:return 0011;
	case 4:return 0100;
	case 5:return 0101;
	case 6:return 0110;
	case 7:return 0111;
	case 8:return 1000;
	case 9:return 1001;
	case 10:return 1010;
	case 11:return 1011;
	case 12:return 1100;
	case 13:return 1101;
	case 14:return 1110;
	case 15:return 1111;
	}
}

void b2h(int n){
    int sum = 0,b=1;
    while(n>0){
            sum = sum + b*n%10;
            n = n/10;
            b = b * 2;
    }
    printf("%x\n",sum);
}
