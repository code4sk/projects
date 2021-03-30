#include <stdio.h>
#include <stdlib.h>

int main()
{
    char alph[21],*ptr;
    int size=0;
    scanf("%s",&alph);
    ptr=alph;
    printf("%s\n",ptr);
    for(ptr=alph;*ptr!='\0';ptr++)
        ++size;
        printf("%d",size);

    return 0;
}
