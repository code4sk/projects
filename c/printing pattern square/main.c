#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    scanf("%d",&a);
    fflush(stdin);
    for(int i=0;i<a;i++)
    {
        printf("%d",a);
    }
    for(int j=0;j<(a-1);j++)
    {
    puts("");
    printf("%d",a);
    if(j<(a-2))
    {
    for(int l=0;l<(a-2);l++)
    {
        if(a<10)
        {
        printf(" ");
        }
        else
        {
         if(a<100)
        {
            printf("  ");

        }
        else
        {
         if(a<1000)
        {
            printf("   ");
        }
        }
        }
    }
    printf("%d",a);
    continue;
    }
    }
    for(int k=0;k<(a-1);k++)
    {
        printf("%d",a);
    }
    return 0;
}
