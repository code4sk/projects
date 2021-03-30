#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int a=0,b[100][2]={0},c,d,e;
    char str[35];
    gets(str);
    for(int i=0;i<=strlen(str);i++)
    {
        if(str[i]!=' '&&i!=(strlen(str)))
        {
            a++;
            continue;
        }
        else
        {
            b[a][0]=a;
            b[a][1]++;
                a=0;
        }
    }
    for(int i=1;i<10;i++)
        printf("%d\t%d\n",b[i][0],b[i][1]);
    return 0;
}
