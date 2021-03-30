#include <stdio.h>
#include <stdlib.h>

void main()
{
char str[21],alph[11];
int num=0, total=0;
gets(str);
fflush(stdin);
gets(alph);
fflush(stdin);
for(int n=0;alph[n]!='\0';++n)
{
    ++total;
}
for(int i=0;alph[i]!='\0';++i)
{
    for(int j=0;str[j]!='\0';++j)
    {
        if(alph[i]==str[j])
        {
            num++;
            break;
    }

}
}
if(total==num)
    puts("yes");
else
    puts("no");
    printf("%d%d",total,num);

getch();
}
