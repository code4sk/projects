#include <stdio.h>
#include <stdlib.h>

void copy(int arr[],int temp[],int low,int up);
void display(int temp[]);
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2);
void merge_sort(int arr[],int low1,int up1);
void m_sort(int arr[],int n);
void merge_pass(int arr[],int temp[],int size,int n);
int main()
{
    int up=9,low=0,n=10;
    int arr[10]={10,5,4,3,2,8,6,7,9,1};
    m_sort(arr,n);
    display(arr);
    return 0;
}
void merge(int arr[],int temp[],int low1,int up1,int low2,int up2)
{
    int i=low1,j=low2,k=low1;
    while(i<=up1&&j<=up2)
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=up1)
        temp[k++]=arr[i++];
    while(j<=up2)
        temp[k++]=arr[j++];
}
void display(int temp[])
{
    for(int i=0;i<10;i++)
        printf("%d\t",temp[i]);
}
void merge_sort(int arr[],int low,int up)
{
    int mid;
    int temp[10];
    if(up>low)
    {
        mid=(up+low)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,up);
        merge(arr,temp,low,mid,mid+1,up);
        copy(arr,temp,low,up);
    }
}
void copy(int arr[],int temp[],int low,int up)
{
    for(int i=low;i<=up;i++)
        arr[i]=temp[i];
}
void m_sort(int arr[],int n)
{
    int temp[10];
    int size=1;
    while(size<n)
    {
        merge_pass(arr,temp,size,n);
        size=size*2;
    }
}
void merge_pass(int arr[],int temp[],int size,int n)
{
    int i,low1,up1,low2,up2;
    low1=0;
    while(low1+size<n)
    {
        up1=low1+size-1;
        low2=up1+1;
        up2=low2+size-1;
        if(up2>=n)
            up2=n-1;
        merge(arr,temp,low1,up1,low2,up2);
        low1=up2+1;
    }
    for(i=low1;i<=n-1;i++)
        temp[i]=arr[i];
    copy(arr,temp,0,n-1);
}
