#include <iostream>
using namespace std;
void subset(int arr[],int n,int r,int index,int data[],int i);
int main()
{
    int arr[6]={3,2,1,6,5,4};
    int data[3];
    subset(arr,6,3,0,data,0);
    return 0;
}
void subset(int arr[],int n,int r,int index,int data[],int i)
{
    if(index==r)
    {
        for(int j=0;j<r;j++)
            cout<<data[j]<<ends;
            cout<<endl;
        return;
    }
    if(i>=n)
        return;
    data[index]=arr[i];
    subset(arr,n,r,index+1,data,i+1);
    subset(arr,n,r,index,data,i+1);
}
