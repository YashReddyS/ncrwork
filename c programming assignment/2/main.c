#include <stdio.h>

int main()
{
    int n,i,al = 0,tab = 0,sp = 0,num = 0;
    char text[80];
    for(i = 0;i<80;i++){
        scanf("%c",&text[i]);
        if(text[i] == '\n')
            break;
        else if((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
            al++;
        else if(text[i] >= 48 && text[i] <= 57)
            num++;
        else if(text[i] == 32)
            sp++;
        else if(text[i] == 9)
            tab++;
    }
    printf("al %d\n",al);
    printf("num %d\n",num);
    printf("sp %d\n",sp);
    printf("tab %d",tab);

}
