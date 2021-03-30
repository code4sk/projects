#include <stdio.h>
#include <stdlib.h>

int i=0;
void card();
int main()
{
    card();
    return 0;
}
void card()
{
    char n;
    if((n=getchar())!='\n'&&i!=16)
   {
        i++;
        putchar(n);
        if(i==4||i==8||i==12)
        {
            putchar('-');
        }
         card();
    }
}
