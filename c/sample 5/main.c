#include <stdio.h>
#include <stdlib.h>

void rec();
int main()
{
    rec();
    return 0;
}
void rec()
{
    char c,g;
    if((c=getchar())!='\n')
    {
        g=getchar();
       //rec();
    }
       printf("%c%c",c,g);
}
