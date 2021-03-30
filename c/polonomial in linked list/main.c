#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    int coff;
    int pow;
    struct node *link;
};
struct node *create();
int show(struct node *start);
struct node *ssort(struct node *start);
struct node *create1();
struct node *merge(struct node *start,struct node *start1);
struct node *create3(int a,int b);
int add(struct node *temp,struct node *start);
struct node *multiply(struct node *start,struct node *start1,int a,int b);
int main()
{
    int a,b,c;
    struct node *start;
    struct node *start1;
    struct node *start2;
    struct node *start3;
    start=create();
    start=ssort(start);
    a=show(start);
    start1=create1();
    start1=ssort(start1);
    b=show(start1);
    start3=multiply(start,start1,a,b);
   // start2=merge(start,start1);
   start3=ssort(start3);
    c=show(start3);
    //start2=ssort(start2);
    //show(start2);
    return 0;
}
struct node *create()
{
    struct node *start=NULL;
    struct node *p;
    struct node *temp;
    for(int i=0;i<4;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->link=NULL;
                switch(i+1)
                {
                case 4 : temp->coff=4;
                         temp->pow=3;
                         break;
                case 2 : temp->coff=5;
                         temp->pow=2;
                         break;
                case 1 : temp->coff=-3;
                         temp->pow=1;
                         break;
                case 3 : temp->coff=0;
                         temp->pow=0;
                }
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
int show(struct node *start)
{
    int len=0;
    struct node *p;
    p=start;
    puts("");
    while(p!=NULL)
    {
        if(p->pow==1)
        printf("(%d)X",(p->coff));
        if(p->pow!=1&&p->pow!=0)
        printf("(%d)X%d",(p->coff),(p->pow));
        if(p->pow==0)
        printf("(%d)",p->coff);
        if(p->link!=NULL)
        printf("+");
        p=p->link;
        len++;
    }
    return len;
}
struct node *ssort(struct node *start)
{
    struct node *p,*q;
    int temp;
    for(p=start;p->link!=NULL;p=p->link)
    {
        for(q=p->link;q!=NULL;q=q->link)
        {
            if(p->pow<q->pow)
            {
                temp=p->pow;
                p->pow=q->pow;
                q->pow=temp;
                temp=p->coff;
                p->coff=q->coff;
                q->coff=temp;
            }
        }
    }
    return start;
}
struct node *create1()
{
    struct node *start1=NULL;
    struct node *p;
    struct node *temp;

    for(int i=0;i<4;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->link=NULL;
                switch(i+1)
                {
                case 4 : temp->coff=2;
                         temp->pow=5;
                         break;
                case 2 : temp->coff=6;
                         temp->pow=4;
                         break;
                case 3 : temp->coff=1;
                         temp->pow=2;
                         break;
                case 1 : temp->coff=8;
                         temp->pow=0;
                }
            if(start1==NULL)
            {
                start1=temp;
            }
            else
            {
                p=start1;
                while(p->link!=NULL)
                {
                    p=p->link;
                }
                p->link=temp;
            }
    }
    return start1;
}
struct node *merge(struct node *start,struct node *start1)
{
    int a,n=0;
 struct node *start2=NULL;
 struct node *p,*t;
 p=start;
 while(p->link!=NULL)
 {
     p=p->link;
 }
 p->link=start1;
 start2=ssort(start);
 for(p=start2,t=p->link;t!=NULL;p=p->link,t=p->link)
 {
     if(p->pow==t->pow)
     {
         p->coff=p->coff+t->coff;
         p->link=t->link;
         t->link=NULL;
     }
 }
 return start2;
}
struct node *create3(int a,int b)
{
    struct node *start3=NULL;
    struct node *p;
    struct node *temp;
    for(int i=0;i<(a*b);i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->link=NULL;

            if(start3==NULL)
            {
                start3=temp;
            }
            else
            {
                p=start3;
                while(p->link!=NULL)
                {
                    p=p->link;
                }
                p->link=temp;
            }
    }
    return start3;
}
int add(struct node *temp,struct node *start)
{
    int val=0;
    struct node *p;
    p=start;
    while(p!=NULL)
    {
        if(p->pow==temp->pow)
    {
    val=val+p->coff;
    }
    p=p->link;
    }
    return val;
}
struct node *multiply(struct node *start,struct node *start1,int a,int b)
{
 struct node *s,*t,*p,*r,*q,*start3=NULL;
 start3=create3(a,b);
 r=start3;
 for(p=start;p!=NULL;p=p->link)
 {
     for(q=start1;q!=NULL;q=q->link,r=r->link)
     {
         r->pow=p->pow+q->pow;
         r->coff=p->coff*q->coff;
     }
 }
 start3=ssort(start3);
 for(s=start3,t=s->link;t!=NULL;s=s->link,t=s->link)
 {
     if(s->pow==t->pow)
     {
         s->coff=s->coff+t->coff;
         s->link=t->link;
         t->link=NULL;
     }
 }
 return start3;
}


