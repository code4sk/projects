#include <stdio.h>
#include <stdlib.h>

void func(int g);
int n,arr[100];
int main()
{
    int g=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    while(g<=n)
    {
        func(g);
        g++;
    }
    return 0;
}
void func(int g)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
        int c=0;
        int min=10000000;
        for(int j=i;c<g;j++)
        {
            if(arr[j]<min)
                min=arr[j];
                c++;
        }
        if(max<min)
            max=min;
    }
    printf("%d\t",max);
}
