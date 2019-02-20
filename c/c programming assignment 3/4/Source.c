#include<Stdio.h>
#include<Stdlib.h>
void hexoc(int);
int hex2bin(int);
void mask(int);
void bitsh(int);

int main() {
	int h, a;
	scanf_s("%x", &h);
	scanf_s("%d", &a);
	switch (a) {
	case 1: hexoc(h); break;
	case 2: mask(h); break;
	case 3: bitsh(h); break;
	default: exit(0);
	}
	scanf_s("%d", &a);
	return 0;
}

void hexoc(int h) {
	if (h == 0x0)
		return;
	int sum, n, base;

	sum = 0x0;
	base = 1;
	n = hex2bin(h % 16);
	int k = 4;
	while (k--) {
		sum += !(n % 10) * base;
		n = n / 10;
		base = base * 2;
	}
	hexoc(h / 16);
	printf("%x", sum);

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

void mask(int h) {
	int n, m;
	scanf_s("%d", &n);
	scanf_s("%x", &m);
	switch (n) {
	case 1:printf("%x", h&m); break;
	case 2:printf("%x", h^m); break;
	case 3:printf("%x", h | m); break;
	}
}

void bitsh(int h) {
	char a;
	int n;
	scanf_s("%d", &n);
	scanf_s(" %c", &a);
	if (a == 'l') {
		
		h = h << n;
	}
	else if (a == 'r') {
		h = h >> n;
	}
	printf("%x", h);
}







