#include <stdio.h>
#include <stdlib.h>

int arr[10]={1,2,3,4,5,6,7,8,9,10};
int rec(int i,int j);
int main()
{
    int i=0,j=9;
    printf("%d",rec(i,j));
    return 0;
}
int rec(int i,int j)
{
    if(i==j)
        return arr[i];
    int mid,left,right;
    mid=(i+j)/2;
    left=rec(i,mid);
    right=rec(mid+1,j);
    return left+right;
}
