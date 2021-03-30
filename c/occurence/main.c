#include <stdio.h>
#include <stdlib.h>

void sort(int []);
void occur(int []);
int main()
{
    int num[6]={1,1,1,4,5,5},arr[6];
    sort(num);
    for(int i=0;i<6;i++)
        printf("%d,",num[i]);
        printf("\b ");
        occur(num);
    return 0;
}
void sort(int arr[])
{
    for(int i=0;i<6;i++)
    {
        for(int j=i+1;j<6;j++)
        {
        if(arr[i]>arr[j])
        {
         int temp;
         temp=arr[i];
         arr[i]=arr[j];
         arr[j]=temp;
        }
        }
    }
}
void occur(int arr[])
{
    int k=1,n=arr[0];
    for(int i=1;i<6;i++)
    {
        if(n==arr[i])
        {
            k++;
            continue;
        }
        printf("\n%d\t%d",n,k);
        k=1;
        n=arr[i];
    }
     printf("\n%d\t%d",n,k);
}
