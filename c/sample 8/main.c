#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *i;
    char *c;
    float *f;
    double *d;
printf("int*\t%u\nchar*\t%u\nfloat*\t%u\ndouble*\t%u\n",sizeof(i),sizeof(c),sizeof(f),sizeof(d));
    return 0;
}
