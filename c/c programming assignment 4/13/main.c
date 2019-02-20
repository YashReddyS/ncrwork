#include <stdio.h>
#include <stdlib.h>

void expand(char *,char *);

int main()
{
    char *s1 = (char *)malloc(sizeof(char));
    char *s2 = (char *)malloc(sizeof(char));

    scanf("%s",s1);

    expand(s1,s2);

    printf("\n%s",s1);
    printf("\n%s",s2);

    return 0;
}

void expand(char *s1,char *s2){
    char c;
    while(*s1 != '\0'){
            if(*s1 == '-'){
                for(c = *(s1-1)+1;c <= *(s1+1)-1;c++){
                    *s2 = c;
                    s2++;
                }
            }
            else{
                    *s2 = *s1;
                    s2++;
            }
        s1++;
    }
    *s2 = '\0';
}
