#include <stdio.h>
#include <stdlib.h>
int n=1;
int len(char* );
void rdisp(char *);
int main()
{
    char str[21];
    printf("Enter your name:\t");
    gets(str);
    n=len(str);
    printf("\n%d\n",n);
    rdisp(str);
    return 0;
}
int len(char *str)
{
    char temp;
    if(*(str)=='\0')
    {
        n--;
        return n;
    }
    else
    {
        n++;
        n=len(++str);
    }
}
void rdisp(char *str)
{
    if(*(str)=='\0')
    {
        return;
    }
    else
    {
    rdisp(str+1);
    putchar(*str);
    }
    return;
}
