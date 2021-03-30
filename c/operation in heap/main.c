#include <stdio.h>
#include <stdlib.h>

int arr[100];
int i=0;
void insert(int);
void restore_up();
void delete(int);
void restore_down(int);
int main()
{
    arr[0]=100000;
    int n,j,b=0;
    while(b<7)
    {
        b++;
    printf("Enter the marks :\t");
    scanf("%d",&n);
    insert(n);
    }
    printf("Enter the marks to be deleted\t");
    scanf("%d",&j);
    delete(j);
    return 0;
}
void insert(int n)
{
    i++;
    arr[i]=n;
    restore_up();
    for(int l=1;arr[l]!=NULL;l++)
    {
        printf("%d\t",arr[l]);
    }
    puts("");
}
void restore_up()
{
    int k=i/2;
    while(arr[k]<arr[i])
    {
        int l;
        l=arr[i];
        arr[i]=arr[k];
        arr[k]=l;
        i=k;
        k=k/2;
    }
    return;
}
void delete(int j)
{
    int m=1;
    while(arr[m]!=j)
        m++;
    arr[m]=arr[i];
    arr[i]=NULL;
    i--;
    restore_down(m);
    puts("");
    for(int l=1;arr[l]!=NULL;l++)
    {
        printf("%d\t",arr[l]);
    }
    return;
}
void restore_down(int m)
{
    int lchild,rchild;
    lchild=2*m;
    rchild=2*m+1;
    while(arr[m]<arr[lchild]&&arr[m]<arr[rchild])
    {
        int v;
        v=arr[m];
        if(arr[m]<arr[lchild])
        {
        arr[m]=arr[lchild];
        arr[lchild]=v;
        m=lchild;
        }
        else if(arr[m]<arr[rchild])
        {
        arr[m]=arr[rchild];
        arr[rchild]=v;
        m=lchild;
        }
        lchild=m*2;
        rchild=lchild+1;
    }
    return;
}
