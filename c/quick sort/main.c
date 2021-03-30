#include <stdio.h>
#include <stdlib.h>

void quick(int arr[],int low,int up);
int partition(int arr[],int low,int up);
void display(int arr[]);
int count =0;
int main()
{
    int arr[15]={3,9,6,1,50,54,2,27,15,5,12,100,64,35,92},low=0,up=14;
    quick(arr,low,up);
    display(arr);
    printf("\n%d",count);
    return 0;
}
void quick(int arr[],int low,int up)
{
    int pivot;
    if(low>=up)
        return;
    pivot=partition(arr,low,up);
    quick(arr,low,pivot);
    quick(arr,pivot+1,up);
}
int partition(int arr[],int low,int up)
{
    int i=low+1,j=up,pivot=low,k;
    while(i<=j)
    {
        while(arr[pivot]>arr[i]&&i<up)
        {
            count++;
            i++;
        }
        while(arr[pivot]<arr[j])
        {
            count++;
            j--;
        }
        if(i<j)
        {
            count+=5;
        k=arr[j];
        arr[j]=arr[i];
        arr[i]=k;
        i++;
        j--;
        }
        else
        i++;
    }
    count+=3;
    k=arr[pivot];
    arr[pivot]=arr[j];
    arr[j]=k;
    return j;
}
void display(int arr[])
{
    count+=15;
    for(int i=0;i<15;i++)
        printf("%d\t",arr[i]);
    puts("");
}
