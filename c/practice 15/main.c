#include <stdio.h>
#include <stdlib.h>

int arr[10]={10,3,4,8,2,1,5,9,7,6},n=10,temp[10];
void isort();
void display(int arr[]);
void shell_sort();
int partition(int low,int up);
void merge(int low1,int up1,int low2,int up2);
void merge_sort(int low,int up);
void m_sort();
void merge_pass(int);
void copy(int low,int up);
void quick(int low,int up);
int main()
{
    quick(0,9);
    display(arr);
    return 0;
}
void display(int arr[])
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
    puts("");
}
void isort()
{
    int k,j;
    for(int i=1;i<n;i++)
    {
        k=arr[i];
        for(j=i-1;j>=0&&arr[j]>k;j--)
            arr[j+1]=arr[j];
            arr[j+1]=k;
    }
}
void shell_sort()
{
    int k,j,incr;
    incr=5;
    while(incr>=1)
    {
    for(int i=incr;i<n;i++)
    {
        k=arr[i];
        for(j=i-incr;j>=0&&arr[j]>k;j=j-incr)
            arr[j+incr]=arr[j];
            arr[j+incr]=k;
    }
    incr=incr-2;
    }
}
void merge(int low1,int up1,int low2,int up2)
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
void merge_sort(int low,int up)
{
    if(low==up)
        return;
    else
    {
        int mid;
        mid=(low+up)/2;
        merge_sort(low,mid);
        merge_sort(mid+1,up);
        merge(low,mid,mid+1,up);
        copy(low,up);
    }
}
void copy(int low,int up)
{
    for(int i=low;i<=up;i++)
        arr[i]=temp[i];
}
void m_sort()
{
    int size=1;
    while(size<=n)
    {
        merge_pass(size);
        size=size*2;
    }
}
void merge_pass(int size)
{
    int up1,up2,low1,low2;
    low1=0;
    while(low1+size<n)
    {
        up1=low1+size-1;
        low2=up1+1;
        up2=low2+size-1;
        if(up2>n-1)
            up2=n-1;
        merge(low1,up1,low2,up2);
        low1=up2+1;
    }
    for(int i=low1;i<n;i++)
        temp[i]=arr[i];
    copy(0,9);
}
void quick(int low,int up)
{
    int p;
    if(low>=up)
        return;
    else
    {
        p=partition(low,up);
        quick(low,p-1);
        quick(p+1,up);
    }
}
int partition(int low,int up)
{
    int p=low,i,j,temp;
    i=low+1;
    j=up;
    while(i<=j)
    {
    while(arr[i]<arr[p]&&i<up)
        i++;
    while(arr[j]>arr[p])
        j--;
    if(i<j)
        {
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
        else
            i++;
     }
     temp=arr[p];
     arr[p]=arr[j];
     arr[j]=temp;
     return j;
}
