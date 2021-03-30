#include <stdio.h>
#include <stdlib.h>

int main()
{
    int inpt;
    int num=0,max,min;
    while(num<=24)
    {
       scanf("%d",&inpt);
        fflush(stdin);
        ++num;
        if(inpt>=max)
        {max=inpt;}
        if(inpt<=min)
        {
            min=inpt;
        }
    }
    printf("max value is %d and min value is %d",max,min);
    return 0;
}
