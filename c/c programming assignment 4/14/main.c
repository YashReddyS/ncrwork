#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
     char *s = (char *)malloc(sizeof(char));

     scanf("%s",s);

     for(i = 0;s[i] != '\0';i++){
        for(j = i;s[j] != '\0';j++){
            printf("%c",s[j]);
        }
        for(j = 0;j < i;j++){
            printf("%c",s[j]);
        }
        printf("%c",' ');
     }
     return 0;
}
