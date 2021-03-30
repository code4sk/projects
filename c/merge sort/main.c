#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[5]={3,24,55,110,420},arr2[5]={6,7,10,51,90},i=0,j=0,k=0,n1=5,n2=5,arr3[10]={0};
    scanf("%d", &i);
    while(i<=n1-1&&j<=n2-1)
    {
        if(arr1[i]<arr2[j])
        {
            arr3[k++]=arr1[i++];
        }
        else
        {
            arr3[k++]=arr2[j++];
        }
    }
    while(i<=n1-1)
        arr3[k++]=arr1[i++];
    while(j<=n2-1)
        arr3[k++]=arr2[j++];
    for(int m=0;m<n1+n2;m++)
        printf("%d\t",arr3[m]);
    return 0;
}
