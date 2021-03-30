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
struct node *bsort(struct node *start);
struct node *sssort(struct node *start);
occur(struct node *start);
int main()
{
    struct node *start;
    start=create();
    //show(start);
    start=sssort(start);
    occur(start);
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
    struct node *p,*q;
    int a,b=0;
    p=start;
    for(p=start;p!=NULL;p=p->link)
    {
        for(q=p->link;q!=NULL;q=q->link)
        {
            int temp;
            if(p->marks<q->marks)
            {
                temp=q->marks;
                q->marks=p->marks;
                p->marks=temp;
            }
        }
    }
    puts("\nsorting is done");
    return start;
}
struct node *bsort(struct node *start)
{
 int temp;
 struct node *end;
 struct node *p;
 struct node *q;
 p=start;
 for(end=NULL;end!=start->link;end=q)
 {
     for(p=start;p->link!=end;p=p->link)
     {
         q=p->link;
         if(p->marks>q->marks)
         {
            temp=p->marks;
            p->marks=q->marks;
            q->marks=temp;
         }
     }
 }
 return start;
}
struct node *sssort(struct node *start)
{
    int temp;
 struct node *p,*r,*q,*s,*temp1,*temp2;
 for(r=p=start;p->link!=NULL;r=p,p=p->link)
 {
     for(s=q=p->link;q!=NULL;s=q,q=q->link)
     {
            if(p->marks<q->marks)
            {
                temp=q->link;
                q->link=p->link;
                p->link=temp;
                s->link=p;
                if(p!=start)
                    r->link=q;
                    if(p==start)
                     start=q;
                     temp=p;
                     p=q;
                     q=temp;
            }
     }
}
 return start;
}
occur(struct node *start)
{
    int a,b=1,l=1;
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        b=1;
    a=p->marks;
    p=p->link;
    for(;p!=NULL;b++,p=p->link)
    {
        if(a==p->marks)
            continue;
        else
        {
            break;
        }
    }
    printf("\n%d\t%d",a,b);
    }
}
