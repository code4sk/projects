#include <stdio.h>
#include <stdlib.h>

struct node
{
    int marks;
    struct node *link;
};
struct node *create();
show(struct node *start);
struct node *intersect(struct node *,struct node *);
int main()
{
   struct node *start,*start1,*start2;
   start=create();
   start1=create();
   start2=intersect(start,start1);
   show(start2);
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
struct node *intersect(struct node *start,struct node *start1)
{
    int a,b;
    struct node *p,*temp,*r,*s,*start2=NULL;
    r=start;
    s=start1;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->link=NULL;
        start2=temp;
    a=r->marks;
    b=s->marks;
    for(;r!=NULL;b=s->marks)
    {
    if(a==b)
    {
        temp->marks=a;
        r=r->link;
          if(r==NULL)
        break;
        a=r->marks;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->marks=007;
        temp->link=NULL;
        p=start2;
        while(p->link!=NULL)
            p=p->link;
        p->link=temp;
        s=start1;
        continue;
    }
    s=s->link;
    if(s==NULL)
    {
        s=start1;
          if(r->link==NULL)
        break;
        r=r->link;
        a=r->marks;
    }
    if(temp->marks==007)
    {
        p=start2;
    while(p->link==temp)
        p=p->link;
    p->link=NULL;
    }
    }
    return start2;
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
