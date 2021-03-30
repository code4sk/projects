#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr[MAX][MAX];
int max_edge;
int main()
{
    int c,n,l,m;
    printf("Enter the type of graph\n1:Undirected\n2:Directed\n");
    scanf("%d",&c);
    printf("Enter the number of vertex\n");
    scanf("%d",&n);
    if(c==2)
        max_edge=n*(n-1);
   else if(c==1)
        max_edge=n*(n-1)/2;
    for(int i=0;i<max_edge;)
    {
        printf("Enter the starting and ending vertex(-1,-1 to quit)\n");
        scanf("%d%d",&l,&m);
        if(l==-1&&m==-1)
            break;
        if(l<0||m<0)
            puts("Invalid edge");
        else
        {
            arr[l][m]=1;
            if(c==1)
            arr[m][l]=1;
            i++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        puts("");
    }
    return 0;
}
