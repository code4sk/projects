#include <stdio.h>
#include <stdlib.h>

int main()
{
    char alph;
    int u=0,l=0,i;
    for( i=1;i<=10;i=i+1)
    {
        scanf("%c",&alph);
        fflush(stdin);

if(alph<='Z')
{
    ++u;
}
else
{
    ++l;
}


    }
    if(u>l)
    {
        puts("no of uppercase is more");
    }
    if(l>u)
    {
        puts("no of lowercase is more");
    }
    if(l==u)
       {
           puts("no of upper and lowercase are same");
       }
    return 0;
}
