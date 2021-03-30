#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[21],sbstr[21];
    int o,c,j=0;
    gets(str);
    fflush(stdin);
    printf("enter the starting and ending position of substring\n");
    scanf("%d%d",&o,&c);
    fflush(stdin);
    for(int i=o-1;i<=c-1;i++,j++)
    {
        sbstr[j]=str[i];


    }
    sbstr[j]='\0';
    printf("%s",sbstr);
    fflush(stdout);

    return 0;
}
