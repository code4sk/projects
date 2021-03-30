#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define perm 0
#define temp 1
#define infinite 999999
#define NIL -1

void dijkstra();
int arr[MAX][MAX],pathlen[MAX],pred[MAX],status[MAX];
void create();
int min();
int main()
{
    create();
    for(int i=0;i<8;i++)
    {
        pathlen[i]=infinite;
        pred[i]=NIL;
        status[i]=temp;
    }
    dijkstra();
    for(int i=0;i<8;i++)
    {
        printf("%d\t%d\t%d\n",i,pathlen[i],pred[i]);
    }
    return 0;
}
void create()
{
    arr[0][2]=9;
    arr[2][0]=5;
    arr[0][1]=8;
    arr[1][5]=9;
    arr[0][4]=7;
    arr[2][1]=-4;
    arr[3][2]=6;
    arr[4][7]=16;
    arr[5][6]=-8;
    arr[6][3]=5;
    arr[6][7]=2;
    arr[5][0]=4;
    arr[3][5]=4;
    arr[5][7]=5;
    arr[2][3]=3;
    arr[3][1]=3;
}
void dijkstra()
{
    int c;
    pathlen[0]=0;
    c=min();
    status[0]=perm;
    while(1)
    {
       for(int i=0;i<8;i++)
       {
           if(arr[c][i]!=0&&status[i]==temp)
           {
               if(pathlen[i]>pathlen[c]+arr[c][i])
               {
                   pathlen[i]=pathlen[c]+arr[c][i];
                   pred[i]=c;
               }
           }
       }
       c=min();
       if(c==NIL)
       return;
       status[c]=perm;
    }
}
int min()
{
    int min=infinite;
    int k=NIL;
    for(int i=0;i<8;i++)
    {
        if(pathlen[i]<min&&status[i]==temp)
        {
            min=pathlen[i];
            k=i;
        }
    }
    return k;
}
