#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void create(int n,int c);
int max_edge,arr[MAX][MAX],pow[MAX][MAX],n;
void delete(int);
void insert(int);
void display(int arr[MAX][MAX]);
void power_matrix();
void multiply(int arr1[MAX][MAX],int temp[MAX][MAX]);
int main()
{
    int c,l;
    while(1)
    {
    printf("Enter your choice\n1:Create\n2:Insert\n3:Delete\n4:Power matrix\n5:Display\n");
    scanf("%d",&l);
    switch(l)
    {
        case 1 :     printf("Enter your choice\n1:Undirected\n2:Directed\n");
                     scanf("%d",&c);
                     printf("Enter the number of vertices\t");
                     scanf("%d",&n);
                     switch(c)
                    {
                       case 1 : max_edge=(n*(n-1))/2;
                       break;
                       case 2 : max_edge=n*(n-1);
                    }
                     create(n,c);
                     break;
        case 2 :     insert(c);
                     break;
        case 3 :     delete(c);
                     break;
        case 4 :     power_matrix();
                     break;
        case 5 :     display(arr);
                     break;
    }
    }
    return 0;
}
void create(int n,int c)
{
    int origin,des;
    for(int i=0;i<max_edge;i++)
    {
        printf("Enter origin and destination(-1 -1 to quit)\n");
        scanf("%d%d",&origin,&des);
        if(origin==-1&&des==-1)
        break;
        else if(origin<0||des<0)
        {
            puts("Invalid operation");
            i--;
        }
        else
        {
            if(c==1)
            {
            arr[origin][des]=1;
            arr[des][origin]=1;
            }
            else
            {
               arr[origin][des]=1;
            }
        }
    }
}
void delete(int c)
{
    int org,des;
    puts("Enter origin and des");
    scanf("%d%d",&org,&des);
    if(c==1)
            {
            arr[org][des]=0;
            arr[des][org]=0;
            }
            else
            {
               arr[org][des]=0;
            }
}
void insert(int c)
{
    int org,des;
    puts("Enter origin and des");
    scanf("%d%d",&org,&des);
    if(c==1)
            {
            arr[org][des]=1;
            arr[des][org]=1;
            }
            else
            {
               arr[org][des]=1;
            }
}
void power_matrix()
{
    int arr1[MAX][MAX],temp[MAX][MAX]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        arr1[i][j]=arr[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        temp[i][j]=arr[i][j];
    }
    for(int k=0;k<n-1;k++)
    {
    multiply(arr1,temp);
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        arr1[i][j]=temp[i][j];
    }
    }
    display(temp);
}
void multiply(int arr1[MAX][MAX],int temp[MAX][MAX])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           temp[i][j]=0;
            for(int d=0;d<n;d++)
        {
           temp[i][j]=temp[i][j]+arr1[i][d]*arr[d][j];
        }
        }
    }
}
void display(int arr[MAX][MAX])
{
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                {
                    printf("%d\t",arr[i][j]);
                }
                puts("");
        }
}
