#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    if(n < 0 || (n % 10 == 0 && n != 0)) {
            printf("not a palindrome number");
            exit(0);
        }

        int r = 0;
        while(n > r) {
            r = r * 10 + n % 10;
            n /= 10;
        }

        if(n == r || n == r/10)
             printf("palindrome number");
        else
             printf("not a palindrome number");
    return 0;

}
