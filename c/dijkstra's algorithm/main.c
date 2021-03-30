#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define temp 0
#define perm 1
#define infinity 9999
#define NIL -1
#define I 0
#define W 1
void create();
void display();
void dijkstra();
int n=8,c,arr[MAX][MAX],state[MAX],pred[MAX],pathlen[MAX],queue[MAX],front=0,rear=-1,status[MAX];
int min_temp();
void push(int);
int pop();
void bell();
int main()
{
    int d=0;
    create();
    display();
    dijkstra();
    puts("dijkstra");
    while(d<n)
    {
        printf("%d\t%d\n",d,pathlen[d]);
        d++;
    }
    d=0;
    bell();
    puts("bell");
    while(d<n)
    {
        printf("%d\t%d\n",d,pathlen[d]);
        d++;
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
void display()
{
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
           printf("%d\t",arr[i][j]);
        }
        puts("");
    }
}
void dijkstra()
{
    int current;
    for(int l=0;l<8;l++)
    {
        state[l]=temp;
        pred[l]=NIL;
        pathlen[l]=infinity;
    }
    pathlen[0]=0;
    current=min_temp();
    while(1)
    {
    for(int j=0;j<n;j++)
    {
        if(state[j]==temp&&arr[current][j]!=0)
        {
            if(pathlen[j]>pathlen[current]+arr[current][j])
            {
            pathlen[j]=pathlen[current]+arr[current][j];
            pred[j]=current;
            }
        }
    }
    current=min_temp();
    if(current==NIL)
        return;
    state[current]=perm;
    }
}
int min_temp()
{
    int k=NIL;
    int min=infinity;
    for(int i=0;i<n;i++)
    {
        if(pathlen[i]<min&&state[i]==temp)
        {
            min=pathlen[i];
            k=i;
        }
    }
    return k;
}
void push(int k)
{
    rear++;
    queue[rear]=k;
}
int pop()
{
  return queue[front++];
}
void bell()
{
    int current;
    for(int l=0;l<8;l++)
    {
        pred[l]=NIL;
        pathlen[l]=infinity;
    }
    pathlen[0]=0;
    push(0);
    status[0]=W;
    while(front<=rear)
    {
    current=pop();
    status[current]=I;
    for(int j=0;j<n;j++)
    {
        if(arr[current][j]!=0)
        {
            if(pathlen[j]>pathlen[current]+arr[current][j])
            {
            pathlen[j]=pathlen[current]+arr[current][j];
            pred[j]=current;
            push(j);
            status[j]=W;
            }
        }
    }
    }
}
