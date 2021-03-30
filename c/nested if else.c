#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
    char chr;
    puts("enter grade");
    chr=getchar();
    fflush(stdin);
    if(chr=='A')
        printf("45%\n");
    if(chr=='B')
        printf("40%\n");
    if(chr=='C')
        printf("30%\n");
    if(chr=='D')
        printf("25%\n");



}
