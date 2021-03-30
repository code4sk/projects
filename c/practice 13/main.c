#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr[MAX][MAX];
void create();
void war();
void display(int arr[MAX][MAX]);
int main()
{
    create();
    war();
    return 0;
}
void create()
{
    arr[0][0]=0;
    arr[1][1]=0;
    arr[2][2]=0;
    arr[3][3]=0;
    arr[1][0]=1;
    arr[0][1]=1;
    arr[0][3]=1;
    arr[3][0]=1;
    arr[2][3]=1;
    arr[3][2]=1;
    arr[1][3]=1;
    arr[1][2]=1;
    arr[0][2]=0;
    arr[2][1]=0;
    arr[2][0]=0;
    arr[3][1]=0;
}
void display(int arr[MAX][MAX])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        puts("");
    }
}
void war()
{
    int arr1[MAX][MAX];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            arr1[i][j]=arr[i][j];
        }
    }
    printf("P(-1):\n");
    display(arr1);
    for(int k=0;k<4;k++)
    {
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                arr1[i][j]=arr1[i][j]||(arr1[i][k]&&arr1[k][j]);
            }
        }
        printf("P(%d):\n",k);
        display(arr1);
    }
}
