#include <stdio.h>
#include <stdlib.h>

int count = 0;

void copy(int arr[],int temp[],int low,int up);
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2);
void merge_sort(int arr[],int low,int up);
int main()
{
    int arr[15]={3,9,6,1,50,54,2,27,15,5,12,100,64,35,92},i=0,j=14;
    merge_sort(arr,i,j);
    for(int m=0;m<15;m++)
        printf("%d\t",arr[m]);
    printf("\n%d",count);
    return 0;
}
void merge_sort(int arr[],int low,int up)
{
    int mid,temp[15];
    if(low<up)
    {
        count++;
        mid=(up+low)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,up);
        merge(arr,temp,low,mid,mid+1,up);
        copy(arr,temp,low,up);
    }
}
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2)
{
    int i=low1,j=low2,k=low1;
    while((i<=up1)&&(j<=up2))
    {
        count++;
        if(arr[i]<=arr[j])
        temp[k++]=arr[i++];
        else
        temp[k++]=arr[j++];
    }
    while(i<=up1)
    {
        count++;
        temp[k++]=arr[i++];
    }
    while(j<=up2)
    {
        count++;
        temp[k++]=arr[j++];
    }
}
void copy(int arr[],int temp[],int low,int up)
{
    for(int i=low;i<=up;i++)
        arr[i]=temp[i];
    count+=up-low+1;
}
