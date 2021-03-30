#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    int marks;
    struct node *link;
};
struct node *create(int a);
int show(struct node *start);
struct node *reverse(struct node *start);
struct node* add(struct node *,struct node *,int,int);
struct node *correction(struct node *start3);
int addition(struct node *,struct node *,int,int);
int main()
{
    struct node *start=NULL,*start1=NULL,*start3=NULL;
    int a,b,c,d,e;
    printf("\nenter first number\n");
    scanf("%d",&a);
    start=create(a);
    start=reverse(start);
    d=show(start);
    printf("\nenter second number\n");
    scanf("%d",&b);
    start1=create(b);
    start1=reverse(start1);
    e=show(start1);
   /* start3=add(start,start1,d,e);
    start3=reverse(start3);
    start3=correction(start3);
    show(start3);*/
    c=addition(start,start1,d,e);
    printf("\n%d\n",c);
    return 0;
}
struct node *create(int a)
{
 struct node *start=NULL,*p,*temp;
 int n;
 while(a>=1)
 {
        n=a%10;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->link=NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            p=start;
            while(p->link!=NULL)
                p=p->link;
            p->link=temp;
        }
        temp->marks=n;
        a=a/10;
 }
 return start;
}
int show(struct node *start)
{
    int i=0;
    struct node *p=start;
    while(p!=NULL)
    {
        printf("%d",p->marks);
        p=p->link;
        i++;
    }
    return i;
}
struct node *reverse(struct node *start)
{
 struct node *t,*p,*q;
 p=start;
 q=start;
 t=start;
 int k=0,i=0,j,temp,m=0,n=0;
 while(t!=NULL)
  {
                t=t->link;
                k++;
  }
  j=k-1;
    while(i<j)
    {
         while(m<k-1)
        {
          q=q->link;
          m++;
        }
        temp=q->marks;
        q->marks=p->marks;
     p->marks=temp;
     n++;
     m=n;
     i++;
     j--;
     p=p->link;
     q=start;
    }
    return start;
}
struct node *add(struct node *start,struct node *start1,int d,int e)
{
    int m=0,n=0,k=0,i=0,j=0,o=0;
    struct node *p,*q,*temp,*t,*start3=NULL;
    p=start;
    q=start1;
       while(o<d||o<e)
    {
        while(m<d-1)
        {
            p=p->link;
            m++;
        }
        while(k<e-1)
        {
            q=q->link;
            k++;
        }
        temp=(struct node *)malloc(sizeof(struct node *));
        temp->link=NULL;
        if(start3==NULL)
        {
            start3=temp;
        }
        else
        {
            t=start3;
            while(t->link!=NULL)
            {
                t=t->link;
            }
            t->link=temp;
        }
        if(q==start1||p==start&&j==0)
        {
          j=1;
        temp->marks=(p->marks)+(q->marks);
        }
        if(j==1&&p==start&&q!=start1)
            temp->marks=q->marks;
        if(j==1&&q==start1&&p!=start)
            temp->marks=p->marks;
        if(q!=start1&&p!=start)
            temp->marks=(p->marks)+(q->marks);
            p=start;
            q=start1;
            o++;
            n++;
            i++;
            m=n;
            k=i;
    }
    puts("");
    return start3;
}
struct node *correction(struct node *start3)
{
 struct node *p,*t;
 p=start3;
 p=p->link;
 while(p!=NULL)
 {
    if(p->marks>9)
        {
            p->marks=p->marks-10;
            t=start3;
            while(t->link!=p)
                t=t->link;
                t->marks=t->marks+1;
        }
        p=p->link;
 }
 return start3;
}
int addition(struct node *start,struct node *start1,int d,int e)
{
    struct node *p=start,*q=start1;
    int i=d-1,j=e-1,n=0;
    while(p!=NULL&&i!=-1)
    {
        n=n+p->marks*pow(10,i);
        p=p->link;
        i--;
    }
    while(q!=NULL&&j!=-1)
    {
        n=n+q->marks*pow(10,j);
        q=q->link;
        j--;
    }
    puts("");
    printf("\naddition of two number is\n");
    return n;
}
