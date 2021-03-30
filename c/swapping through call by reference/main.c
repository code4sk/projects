#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("number before swapping are %d %d\n",a,b);
    swap(&a,&b);
    printf("number after swapping are %d %d",a,b);
    return 0;
}
swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
