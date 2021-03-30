#include <stdio.h>
#include <stdlib.h>

struct node
{
    int sal;
    int num;
    struct node *link;
};
int l;
struct node *front=NULL,*rear;
create();
bsort();
display();
int main()
{
int n,c;
    printf("enter the number of customer in the queue\t");
    scanf("%d",&n);
    l=n;
    create();
    bsort();
    display();
    while(c!=3)
    {
        printf("\nenter your choice\n1:push\n2:pop\n3:quite\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : push();
                     bsort();
                     display();
            break;
            case 2 : pop();
                     display();
            break;
            case 3 : puts("have a nice day......");
            break;
            default : puts("-----invalid operation-----");
        }
    }
    return 0;
}
create()
{
    struct node *temp;
  for(int i=0;i<l;i++)
 {
     temp=(struct node *)malloc(sizeof(struct node));
     if(i==0)
    {
     front=temp;
     rear=temp;
    }
    else
    {
     rear->link=temp;
     rear=temp;
    }
     temp->num=i+1;
     printf("\nENTER THE SALARY OF CUSTOMER %d\n$ ",i+1);
     scanf("%d",&temp->sal);
 }
 rear->link=NULL;
}
display()
{
    printf("\n_________\n");
    printf("         |\n         |\n taylor  |\n swift   |\n         |\n_________|");
    struct node *p=front;
    for(int i=0;i<l;i++)
    {
        printf("%d ",p->num);
        p=p->link;
    }
}
push()
{
     struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
     if(front==NULL)
    {
     front=temp;
     front->link=NULL;
     rear=temp;
     rear->link=NULL;
     l++;
     temp->num=l;
     printf("\nENTER THE SALARY OF CUSTOMER %d\n$ ",l);
     scanf("%d",&temp->sal);
    }
    else
    {
     rear->link=temp;
     rear=temp;
     rear->link=NULL;
     l++;
     rear->num=l;
     printf("\nENTER THE SALARY OF CUSTOMER %d\n$ ",l);
     scanf("%d",&temp->sal);
    }
}
pop()
{
     if(front!=NULL)
    {
     front=front->link;
     l--;
    }
}
bsort()
{
    int temp1,temp2;
    struct node *end,*q,*p;
    p=front;
    for(end=NULL;end!=front->link;end=q)
    {
        for(p=front;p->link!=end;p=p->link)
        {
            q=p->link;
            if((p->sal)<(q->sal))
            {
                temp1=p->sal;
                p->sal=q->sal;
                q->sal=temp1;
                temp2=p->num;
                p->num=q->num;
                q->num=temp2;
            }
        }
    }
}
