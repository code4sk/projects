#include <stdio.h>
#include <stdlib.h>

int main()
{
    double *p;
    char *t=new char;
    int x=100,y;
    *t='x';
    p=(double *)&x;
 //   p+=y=*p;
    printf("%ld",*p);
    return 0;
}

