#include <stdio.h>
#include <stdlib.h>

void build();
void restore(int i);
int arr[11]={10000,4,8,1,2,6,3,7,5,10,9};
int main()
{
    build();
    for(int i=1;i<11;i++)
        printf("%d\t",arr[i]);
    return 0;
}
void build()
{
    for(int i=1;i<11;i++)
    {
        restore(11-i);
    }
}
void restore(int i)
{
    while(arr[i]>arr[i/2])
    {
        int temp=arr[i];
        arr[i]=arr[i/2];
        arr[i/2]=temp;
        i=i/2;
    }
}
