#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define temp 0
#define perm 1
#define infinity 999
#define NIL -1

int arr[MAX][MAX],state[MAX],pred[MAX],length[MAX],n=6;
void create();
void prim();
int min_temp();
int main()
{
    create();
    prim();
    printf("vertex\tlength\tpredecessor\n\n");
    for(int i=0;i<n;i++)
    {
    printf("%d\t%d\t%d\n",i,length[i],pred[i]);
    }
    return 0;
}
void create()
{
    arr[0][4]=10;
    arr[2][0]=2;
    arr[2][3]=14;
    arr[0][3]=3;
    arr[0][1]=6;
    arr[1][3]=11;
    arr[2][4]=8;
    arr[4][3]=7;
    arr[3][5]=5;
    arr[1][5]=9;
    arr[4][5]=4;
    arr[4][0]=10;
    arr[0][2]=2;
    arr[3][2]=14;
    arr[3][0]=3;
    arr[1][0]=6;
    arr[3][1]=11;
    arr[4][2]=8;
    arr[3][4]=7;
    arr[5][3]=5;
    arr[5][1]=9;
    arr[5][4]=4;
}
void prim()
{
    int current;
    for(int i=0;i<n;i++)
    {
        state[i]=temp;
        length[i]=infinity;
        pred[i]=NIL;
    }
    length[0]=0;
    for(int j=0;j<n;j++)
    {
    current=min_temp();
    state[current]=perm;
    if(current!=NIL)
    {
    for(int i=0;i<n;i++)
    {
        if(arr[current][i]!=0)
        {
            if((length[i]>arr[current][i])&&(state[i]==temp))
            {
                length[i]=arr[current][i];
                pred[i]=current;
            }
        }
    }
    }
    else
        return;
    }
}
int min_temp()
{
    int k=NIL;
    int min=infinity;
    for(int i=0;i<n;i++)
    {
        if(length[i]<min&&state[i]==temp)
        {
            min=length[i];
            k=i;
        }
    }
    return k;
}
