#include <stdio.h>
#include <stdlib.h>

struct node
{
    int marks;
    struct node *link;
};
struct node *start;
void create();
void display();
struct node *merge(struct node *start_first,struct node *start_second);
struct node *merge_sort(struct node *start);
struct node *divide(struct node *p);
int main()
{
    create();
    display();
    start=merge_sort(start);
    display();
    return 0;
}
void create()
{
    struct node *temp,*p;
    for(int i=0;i<10;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->link=NULL;
        temp->marks=10-i;
        if(start==NULL)
            start=temp;
        else
        {
            p=start;
            while(p->link)
                p=p->link;
            p->link=temp;
        }
    }
}
void display()
{
    struct node *p=start;
    while(p)
    {
        printf("%d\t",p->marks);
        p=p->link;
    }
    puts("");
}
struct node *merge(struct node *p,struct node *q)
{
    struct node *start_merged,*t;
    if(p->marks<=q->marks)
    {
        start_merged=p;
        p=p->link;
    }
    else
    {
        start_merged=q;
        q=q->link;
    }
    t=start_merged;
    while(p!=NULL&&q!=NULL)
    {
        if(p->marks<=q->marks)
        {
            t->link=p;
            t=t->link;
            p=p->link;
        }
        else
        {
            t->link=q;
            t=t->link;
            q=q->link;
        }
    }
    if(p)
    t->link=p;
    else
        t->link=q;
    return start_merged;
}
struct node *merge_sort(struct node *start)
{
    struct node *start_first,*start_second,*start_merged;
    if(start->link!=NULL&&start!=NULL)
    {
        start_first=start;
        start_second=divide(start);
        start_first=merge_sort(start_first);
        start_second=merge_sort(start_second);
        start_merged=merge(start_first,start_second);
        return start_merged;
    }
    else
    return start;
}
struct node *divide(struct node *p)
{
    struct node *q,*start_second;
    q=p->link->link;
    while(q)
    {
        p=p->link;
        q=q->link;
        if(q!=NULL)
        q=q->link;
    }
    start_second=p->link;
    p->link=NULL;
    return start_second;
}
