#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define I 0
#define W 1
#define V 2
#define F 3
void create(int n,int c);
int max_edge,arr[MAX][MAX],n;
void display(int arr[MAX][MAX]);
int path_mat();
int queue[MAX],front=0,rear=-1,state[MAX],pred[MAX],dis[MAX],label[MAX],component=1,component1=1,stack[MAX],top=-1,d[MAX],time=0,f[MAX];
int pop();
int pops();
void push(int);
void pushs(int);
void BFS(int);
void DFS(int);
void RDFS(int);
int main()
{
    int c,l,g;
    while(1)
    {
    printf("Enter your choice\n1:Create\n2:Path matrix\n3:Display\n4:Traversal(BFS)\n5:Traversal(DFS)\n");
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
        case 2 :     path_mat();
                     break;
        case 3 :     display(arr);
                     break;
        case 4 :     for(int i=0;i<n;i++)
                      {
                        state[i]=I;
                      }
                     printf("Enter the starting vertex\n");
                     scanf("%d",&g);
                     BFS(g);
                     for(int v=0;v<n;v++)
                     {
                        if(state[v]==I)
                        {
                            component++;
                            BFS(v);
                        }
                     }
                     break;
        case 5 :     for(int i=0;i<n;i++)
                      {
                        state[i]=I;
                      }
                     printf("Enter the starting vertex\n");
                     scanf("%d",&g);
                     RDFS(g);
                     puts("");
                for(int v=0;v<n;v++)
                     {
                      if(state[v]==I)
                        {
                            component1++;
                            RDFS(v);
                        }
                     }
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
int path_mat()
{
    int arr1[MAX][MAX];
    for(int g=0;g<n;g++)
        {
            for(int h=0;h<n;h++)
                {
                    arr1[g][h]=arr[g][h];
                }
        }
    for(int i=-1;i<n;)
    {
       printf("P(%d)=\n",i);
       display(arr1);
       puts("");
       i++;
       for(int l=0;l<n;l++)
       {
           for(int m=0;m<n;m++)
           {
               if(arr1[l][m]==0)
               {
                   if((arr1[l][i]==1)&&(arr1[i][m]==1))
                   {
                       arr1[l][m]=1;
                   }
               }
           }
       }
    }
    return 0;
}
void push(int f)
{
    rear++;
    queue[rear]=f;
    return;
}
int pop()
{
    int temp;
    temp=queue[front];
    front++;
    return temp;
}
void BFS(int g)
{
    int a,l=0;
    label[g]=component;
    push(g);
    pred[g]=-1;
    dis[g]=0;
    while(front<=rear)
    {
        a=pop();
        state[a]=V;
        printf("%d\t%d\t%d\t----->%d\n",a,pred[a],dis[a],label[a]);
        while(l<n)
        {
            if(arr[a][l]==1&&state[l]==I)
            {
                if(state[l]==I)
                {
                    push(l);
                    state[l]=W;
                    pred[l]=a;
                    dis[l]=1+dis[pred[l]];
                    label[l]=component;
                }
            }
            l++;
        }
        l=0;
    }
    puts("");
}
void pushs(int a)
{
    top++;
    stack[top]=a;
}
int pops()
{
    int a=stack[top];
    top--;
    return a;
}
void DFS(int g)
{
    int a,l=n-1;
    pushs(g);
    label[g]=component1;
    pred[g]=-1;
    while(top>-1)
    {
        a=pops();
        if(state[a]==I)
        {
        state[a]=V;
        printf("%d\t%d\t------>%d\n",a,pred[a],label[a]);
        }
        for(l=n-1;l>=0;l--)
        {
            if(arr[a][l]==1&&state[l]==I)
            {
            pushs(l);
            pred[l]=a;
            label[l]=component1;
            }
        }
    }
    puts("");
}
void RDFS(int a)
{
    time++;
        state[a]=V;
        d[a]=time;
        label[a]=component1;
        printf("%d\t%d\t----->%d\n",a,d[a],label[a]);
    for(int k=0;k<n;k++)
    {
        if(arr[a][k]==1&&state[k]==I)
           {
               RDFS(k);
           }
    }
    state[a]=F;
    f[a]=++time;
    printf("\n%d\t<%d>\n",a,f[a]);
}
