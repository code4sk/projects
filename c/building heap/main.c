#include <stdio.h>
#include <stdlib.h>

int arr[9]={1000,25,9,28,45,12,19,13,35};
void restore_up();
int i=8;
int main()
{
    restore_up();
    for(int m=1;m<=i;m++)
        printf("%d\t",arr[m]);
    return 0;
}
void restore_up()
{
    int j,m=2;
    int k;
    while(m!=i+1)
    {
        int l;
        j=m;
        k=j/2;
        while(arr[k]<arr[j])
        {
        l=arr[k];
        arr[k]=arr[j];
        arr[j]=l;
        j=k;
        k=j/2;
        }
        m++;
    }
}
