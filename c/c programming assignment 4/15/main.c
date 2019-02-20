#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *s1 = (char *)malloc(sizeof(char));
    char *s2 = (char *)malloc(sizeof(char));



    scanf("%s",s1);
    scanf("%s",s2);
    strrev(s1);
    printf("\n%s",s1);
    strcpy(s1,s2);
    printf("\n%s",s1);
    printf("%s",strcat(s1,s2));
    printf("\n%s",s1);
    printf("%s",strcmp(s1,s2));

    return 0;
}

void strrev(char *s){
    static int c = 0;
    if(*s == '\0'){
        c--;
        return;
    }
    c++;
    strrev(s+1);

    if(c>0){
        replace((s-c),s);
        c-=2;
    }
}

void strcpy(char *s1,char *s2){
    while(*s2 != '\0'){
        *s1++ = *s2++;
    }
    *s1 = '\0';
}

void strcat(char *s1,char *s2){
    while(*s1 != '\0'){
        s1++;
    }
    strcpy(s1,s2);
}

void replace(char *a,char *b){
    char temp;
    temp = *a;
    *a= *b;
    *b = temp;
}

