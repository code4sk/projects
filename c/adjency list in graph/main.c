#include <stdio.h>
#include <stdlib.h>

struct vertex
{
    int marks;
    struct vertex *nextvertex;
    struct edge *firstedge;
};
struct edge
{
    struct vertex *des;
    struct edge *nextedge;
};
struct vertex *start;
void insert_vertex(int);
void insert_edge(int,int);
struct vertex *search(int);
void delete_edge(int ,int);
void display();
void delete_vertex(int);
void delete_inedge(int);
int main()
{
    int c,n,org,des;
    while(1)
    {
    printf("Enter your choice\n1:Insert vertex\n2:Insert edge\n3:Delete edge\n4:Delete vertex\n5:Display\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1 :  printf("Enter the marks on vertex\n");
                  scanf("%d",&n);
                  insert_vertex(n);
                  break;
        case 2 :  printf("Enter the origin and destination\n");
                  scanf("%d %d",&org,&des);
                  insert_edge(org,des);
                  break;
        case 5 :  display();
                  break;
        case 3 :  printf("Enter the origin and destination\n");
                  scanf("%d %d",&org,&des);
                  delete_edge(org,des);
                  break;
        case 4 :  printf("Enter the marks on vertex\n");
                  scanf("%d",&n);
                  delete_inedge(n);
                  delete_vertex(n);
    }
    }
    return 0;
}
void insert_vertex(int n)
{
    struct vertex *temp,*p;
    temp=(struct vertex *)malloc(sizeof(struct vertex));
    temp->marks=n;
    temp->nextvertex=NULL;
    temp->firstedge=NULL;
    if(start==NULL)
    {
        start=temp;
        return;
    }
    p=start;
    while(p->nextvertex!=NULL)
        p=p->nextvertex;
    p->nextvertex=temp;
}
void insert_edge(int org,int des)
{
    struct vertex*loco,*locd;
    struct edge *temp,*p;
    temp=(struct edge *)malloc(sizeof(struct edge));
    loco=search(org);
    locd=search(des);
    temp->des=locd;
    temp->nextedge=NULL;
    if(!(loco->firstedge))
    {
        loco->firstedge=temp;
        return;
    }
    else
    {
        p=loco->firstedge;
    while(p->nextedge)
        p=p->nextedge;
    p->nextedge=temp;
    }
}
struct vertex *search(int n)
{
    struct vertex *p=start;
    while(p)
    {
        if(p->marks==n)
            break;
        else
            p=p->nextvertex;
    }
    return p;
}
void display()
{
    struct vertex *p;
    struct edge *q;
    p=start;
    while(p)
    {
        printf("%d->",p->marks);
        q=p->firstedge;
        while(q)
        {
            printf(" %d",q->des->marks);
            q=q->nextedge;
        }
        puts("");
        p=p->nextvertex;
    }
}
void delete_edge(int org,int des)
{
    struct vertex *p;
    struct edge *q,*par;
    p=start;
    while(p)
    {
        if(p->marks==org)
            break;
        else
            p=p->nextvertex;
    }
    q=p->firstedge;
    par=p;
    while(q)
    {
        if(q->des->marks==des)
            {
                if(par==p)
                {
                    p->firstedge=q->nextedge;
                    free(q);
                    return;
                }
                else
                {
                    par->nextedge=q->nextedge;
                    free(q);
                    return;
                }
            }
            par=q;
            q=q->nextedge;
    }
}
void delete_vertex(int n)
{
    struct vertex *p=start,*par;
    while(p)
    {
        if(p->marks==n)
        {
            if(p==start)
            {
                start=p->nextvertex;
                free(p);
                return;
            }
            else
            {
                par->nextvertex=p->nextvertex;
                free(p);
                return;
            }
        }
        par=p;
        p=p->nextvertex;
    }
}
void delete_inedge(int n)
{
    struct vertex *p=start;
    struct edge *q,*par;
    while(p)
    {
        if(p->firstedge)
        {
            q=p->firstedge;
            if(q->des->marks==n)
            {
                p->firstedge=q->nextedge;
                p=p->nextvertex;
                free(q);
                continue;
            }
            else
            {
                par=q;
                q=q->nextedge;
                while(q)
                {
                    if(q->des->marks==n)
                    {
                        par->nextedge=q->nextedge;
                        break;
                    }
                    par=q;
                    q=q->nextedge;
                }
            }
        }
        p=p->nextvertex;
    }
}
