#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define infinity 999
#define NIL -1
int n=4,arr[MAX][MAX],D[MAX][MAX],pred[MAX][MAX];
void create();
void m_war();
void display(int arr[MAX][MAX]);
int main()
{
    create();
    m_war();
    display(arr);
    puts("Shortest path matrix");
    display(D);
    puts("Predecessor matrix");
    display(pred);
    return 0;
}
void create()
{
    arr[0][1]=2;
    arr[1][0]=3;
    arr[1][2]=4;
    arr[2][1]=6;
    arr[1][3]=7;
    arr[0][3]=9;
    arr[3][0]=14;
    arr[3][2]=4;
    arr[2][3]=2;
    arr[0][0]=0;
    arr[1][1]=0;
    arr[2][2]=0;
    arr[3][3]=0;
    arr[0][2]=0;
    arr[3][1]=0;
    arr[2][0]=0;
}
void m_war()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==0)
            {
             D[i][j]=infinity;
             pred[i][j]=NIL;
            }
             else
             {
             D[i][j]=arr[i][j];
             pred[i][j]=i;
             }
        }
    }
for(int k=0;k<n;k++)
 {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(D[i][j]>D[i][k]+D[k][j])
            {
                D[i][j]=D[i][k]+D[k][j];
                pred[i][j]=pred[k][j];
            }
        }
    }
}
}
void display(int array[MAX][MAX])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           printf("%d\t",array[i][j]);
        }
        puts("");
    }
}
