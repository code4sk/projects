#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    char chr;
    struct node *next;
};
int l;
struct node *create();
show(struct node *start);
struct node *choice(struct node *start);
struct node *insert(struct node *start);
struct node *delete(struct node *start);
struct node *reverse(struct node *start);
struct node *sreverse(struct node *start);

int main()
{
    int b=1;
    struct node *start;
    start=create();
    show(start);
    while(b==1)
    {
    start=choice(start);
    show(start);
    puts("\nENTER THE CHOICE\n1 : CONTINUE\n2 : QUIT\n");
    scanf("%d",&b);
    }
    puts("\nHAVE A NICE DAY......\n");
    return 0;
}
struct node *create()
{
 struct node *start=NULL;
 struct node *p;
 struct node *temp;
 for(int i=0;i<6;i++)
 {
 temp=(struct node *)malloc(sizeof(struct node));
 switch(i+1)
 {
     case 1 : (temp->chr)='G';
     break;
     case 2 : (temp->chr)='O';
     break;
     case 3 : (temp->chr)='O';
     break;
     case 4 : (temp->chr)='G';
     break;
     case 5 : (temp->chr)='L';
     break;
     case 6 : (temp->chr)='E';
 }
         l=6;
         (temp->prev)=NULL;
         (temp->next)=NULL;
         if(start==NULL)
         {
             start=temp;
         }
         else
         {
             p=start;
             while((p->next)!=NULL)
             {
                 p=(p->next);
             }
             (p->next)=(temp);
             (temp->prev)=p;

         }
 }
 return start;
}
show(struct node *start)
{
    l=0;
 struct node *p;
 p=start;
 while(p!=NULL)
 {
     printf("\t");
     printf("%c",(p->chr));
     p=(p->next);
     l++;
 }
}
struct node *choice(struct node *start)
{
 int c;
 printf("\nENTER YOUR CHOICE\n1:INSERT\n2:DELETE\n3:REVERSE\n");
 scanf("%d",&c);
    switch(c)
    {
        case 1 : start=insert(start);
                 printf("\nLINKED LIST AFTER INSERTION\n");
                 return start;
                 break;
        case 2 : start=delete(start);
                 printf("\nLINKED LIST AFTER DELETION\n");
                 return start;
                 break;
        case 3 : start=sreverse(start);
                 printf("\nLINKED LIST AFTER REVERSING\n");
                 return start;
                 break;
        default : puts("***-------------------------INVALID OPERATION-------------------------***");
    }
}
struct node *insert(struct node *start)
{
    int n,i=2,j=1;
    char c;
 struct node *p,*t;
 struct node *temp;
 temp=(struct node *)malloc(sizeof(struct node));
 (temp->prev)=NULL;
 (temp->next)=NULL;
 printf("ENTER THE CHARACTER THAT YOU WANT TO INSERT\n");
  scanf("\n%c",&c);
   if(c>97&&c<123)
  {
      c=c-32;
  }
  printf("\nENTER THE POSITION WHERE YOU WANT TO INSERT '%c'\n",c);
  scanf("%d",&n);
  (temp->chr)=c;
  p=start;
  t=start;
  while(i<n)
  {
      p=(p->next);
      i++;
  }
  while(j<n)
  {
      t=(t->next);
      j++;
  }
  if(n!=1&&n!=(l+1))
  {
  (p->next)=(temp);
  (temp->prev)=p;
  (temp->next)=t;
  (t->prev)=temp;
   return start;
  }
  if(n==1)
  {
      (temp->next)=(p);
      (p->prev)=temp;
      return temp;
  }
  if(n==(l+1))
  {
      (p->next)=(temp);
      (temp->prev)=p;
      (temp->next)=NULL;
      return start;
  }

}
struct node *delete(struct node *start)
{
    int n,i=2,j=0;
    struct node *p,*t;
    printf("\nENTER THE POSITION WHICH YOU WANT TO DELETE\n");
    scanf("%d",&n);
    p=start;
    t=start;
    while(i<n)
    {
        p=p->next;
        i++;
    }
    while(j<n)
    {
        t=t->next;
        j++;
    }
    if(n!=1&&n!=l)
    {
    p->next=t;
    t->prev=p;
    }
    if(n==1)
    {
     p->next=NULL;
     start=t;
    }
    if(n==l)
    {
     p->next=NULL;
    }
    return start;
}
struct node *reverse(struct node *start)
{
 struct node *p1,*p2;
 p1=start;
 p2=p1->next;
 p1->next=NULL;
 p1->prev=p2;
 while(p2!=NULL)
 {
    p2->prev=p2->next;
    p2->next=p1;
    p1=p2;
    p2=p2->prev;
 }
 start=p1;
 return p1;
}
struct node *sreverse(struct node *start)
{
 char temp;
 struct node *p,*q;
 int i=0,j=(l-1);
 p=start;
 q=start;
 while(q->next!=NULL)
    q=q->next;
 while(i<j)
 {
     temp=p->chr;
     p->chr=q->chr;
     q->chr=temp;
     p=p->next;
     q=q->prev;
 i++;
 j--;
 }
 puts("success");
 return start;
}
