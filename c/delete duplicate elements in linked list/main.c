#include <stdio.h>
#include <stdlib.h>

struct node
{
    int marks;
    struct node *link;
};
struct node *create();
show(struct node *start);
struct node *ssort(struct node *start);
struct node *dlt(struct node *start);
struct node *delete(struct node *start);
int main()
{
    struct node *start;
    start=create();
    //start=ssort(start);
    start=delete(start);
    show(start);
    return 0;
}
struct node *create()
{
 struct node *temp;
 struct node *p;
 struct node *start=NULL;
 printf("\nENTER THE MARKS OF STUDENTS\n");
 for(int i=0;i<5;i++)
 {
  temp=(struct node *)malloc(sizeof(struct node));
        temp->link=NULL;
        scanf("%d",&temp->marks);
        if(start==NULL)
            {
                start=temp;
            }
            else
            {
                p=start;
                while(p->link!=NULL)
                {
                    p=p->link;
                }
                p->link=temp;
            }
 }
 return start;
 }
show(struct node *start)
{
    int i=1;
    struct node *p=start;
    while(p!=NULL)
    {
        printf("\n%d",p->marks);
        p=p->link;
        i++;
    }
}
struct node *ssort(struct node *start)
{
 struct node *p,*q,*temp;
 for(p=start;p!=NULL;p=p->link)
 {
     for(q=p->link;q!=NULL;q=q->link)
     {
         if(p->marks<q->marks)
         {
             temp=p->marks;
             p->marks=q->marks;
             q->marks=temp;
         }
     }
 }
 return start;
}
struct node *dlt(struct node *start)
{
 struct node *r,*p;
 int a;
 p=start;
 while(p!=NULL)
 {
     a=p->marks;
     r=p;
     p=p->link;
     for(;p!=NULL;p=r->link)
     if(a==p->marks)
     {
        r->link=p->link;
        p->link=NULL;
     }
     else
    break;
 }
 return start;
}
struct node *delete(struct node *start)
{
 struct node *r,*p,*t;
 int a;
 p=start;
 while(p!=NULL)
{
 a=p->marks;
t=p;
r=p;
t=t->link;
 while(t!=NULL)
{
    if(a==t->marks)
     {
        r->link=t->link;
        t=r->link;
     }
     else
     {
    r=t;
    t=t->link;
     }
}
 p=p->link;
}
return start;
}
