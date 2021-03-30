#include <stdio.h>
#include <stdlib.h>

int arr[10]={1,2,3,4,5,6,7,8,9,10};
int b_search(int n,int i,int j);
int main()
{
    int n;
    while(1)
    {
    puts("Enter the element to search");
    scanf("%d",&n);
    printf("%d\n",b_search(n,0,9));
    }
    return 0;
}
int b_search(int n,int i,int j)
{
    if(i>j)
        return 0;
    int mid;
    mid=(i+j)/2;
    if(n==arr[mid])
        return 1;
    if(n<arr[mid])
        return b_search(n,i,mid-1);
    else if(n>arr[mid])
        return b_search(n,mid+1,j);
}
