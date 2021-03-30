#include <stdio.h>
#include <stdlib.h>

int *calc(int *c);
int main()
{
    int *ptr,a,b;
    ptr=calc(&a);
    (*ptr)++;
    printf("%d",*ptr);
    return 0;
}
int *calc(int *c)
{
    scanf("%d",c);
    fflush(stdin);
    return c;
}

