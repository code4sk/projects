#include <stdio.h>
#include <stdlib.h>

struct vertex
{
    int info;
    struct vertex* next_vertex;
    struct edge *first_edge;
};
struct edge
{
    struct vertex *des_vertex;
    struct edge *next_edge;
};
void delete(int l,int m);
struct vertex *root;
void insert(int e);
void display();
int main()
{
    int n,c,e,l,m;
    struct vertex *p,*temp;
    printf("Enter number of vertex\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        temp=(struct vertex *)malloc(sizeof(struct vertex));
        temp->next_vertex=NULL;
        temp->first_edge=NULL;
        temp->info=i;
        if(root==NULL)
            root=temp;
        else
        {
            p=root;
            while(p->next_vertex)
            p=p->next_vertex;
            p->next_vertex=temp;
        }
    }
    display();
    while(1)
    {
        printf("Enter your choice\n1:Insert edge\n2:Delete edge\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : printf("Enter the number of edge\n");
                     scanf("%d",&e);
                     insert(e);
                     display();
                     break;
            case 2 : printf("Enter starting vertex and ending vertex((-1 -1) to quit)\n");
                     scanf("%d%d",&l,&m);
                     delete(l,m);
                     display();
                     break;
        }
    }
    return 0;
}
void insert(int n)
{
    int l,m;
    struct edge *temp,*p;
    struct vertex *q,*s;
    for(int i=0;i<n;)
    {
        printf("Enter starting vertex and ending vertex((-1 -1) to quit)\n");
        scanf("%d%d",&l,&m);
        if(l==-1&&m==-1)
            break;
        if(l<0&&m<0)
            puts("Invalid edge");
        else
        {
            q=root;
            s=root;
            while(q->info!=l)
                q=q->next_vertex;
            while(s->info!=m)
                s=s->next_vertex;
            temp=(struct edge *)malloc(sizeof(struct edge));
            temp->next_edge=NULL;
            temp->des_vertex=s;
            if(!q->first_edge)
                q->first_edge=temp;
            else
            {
                p=q->first_edge;
                while(p->next_edge)
                p=p->next_edge;
                p->next_edge=temp;
            }
            i++;
        }
    }
}
void display()
{]
    struct vertex *p=root;
    struct edge *q=p->first_edge;
    while(p)
    {
        printf("%d->",p->info);
        while(q)
        {
            printf("\t%d",q->des_vertex->info);
            q=q->next_edge;
        }
        puts("");
        p=p->next_vertex;
        if(p)
        q=p->first_edge;
    }
}
void delete(int l,int m)
{
    struct vertex *p=root;
    struct edge *q;
    while(p->info!=l)
        p=p->next_vertex;
        q=p->first_edge;
        if(q->des_vertex->info==m)
        {
            p->first_edge=q->next_edge;
            return;
        }
    while(q->next_edge->des_vertex->info!=m)
          q=q->next_edge;
          q->next_edge=q->next_edge->next_edge;
          return;
}
