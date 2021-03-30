#include <stdio.h>
#include <stdlib.h>
int main()
{
    char alph[21]="shubham kapoor", *ptr;
    ptr=alph;
    for(int i=0;i<5;i++)
    printf("%s\n",(ptr+i));


    return 0;
}
