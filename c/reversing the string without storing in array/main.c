#include <stdio.h>
#include <stdlib.h>

void reverse();
int main()
{
    reverse();
    return 0;
}
void reverse()
{
    char c;
    if((c=getchar())!='\n')
       reverse();
       putchar(c);
}
