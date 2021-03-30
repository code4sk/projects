#include <stdio.h>
#include <stdlib.h>

struct node
{
    int num;
    struct node *link;
};
int l;
struct node *create(int n);
display(struct node *top);
struct node *push(struct node *);
struct node *pop(struct node *);
struct node *reverse(struct node *);
int main()
{
    struct node *top;
    int n,c;
    printf("enter the number of stack that you want to create\t");
    scanf("%d",&n);
    l=n;
    top=create(n);
    display(top);
    while(c!=4)
    {
        printf("\nenter your choice\n1:push\n2:pop\n3:reverse\n4:quite\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : top=push(top);
                     display(top);
            break;
            case 2 : top=pop(top);
                     display(top);
            break;
            case 3 : top=reverse(top);
                     display(top);
            break;
            case 4 : puts("have a nice day......");
            break;
            default : puts("-----invalid operation-----");
        }
    }
    return 0;
}
struct node *create(int n)
{
 struct node *top=NULL,*temp,*p;
 for(int i=0;i<n;i++)
 {
     temp=(struct node *)malloc(sizeof(struct node));
     temp->link=top;
     top=temp;
     temp->num=i+1;
 }
 return top;
}
display(struct node *top)
{
    struct node *p;
    p=top;
    while(p!=NULL)
    {
        printf("\n|__%d__|",p->num);
        p=p->link;
    }
}
struct node *push(struct node *top)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->link=top;
    top=temp;
    l++;
    temp->num=l;
    return top;
}
struct node *pop(struct node *top)
{
    if(l!=0)
    l--;
    if(top==NULL)
        return NULL;
    top=top->link;
    return top;
}
struct node *reverse(struct node *top)
{
    struct node *p,*q;
    int i=0,j=l-1,m=0,n=0,b=0,temp;
    p=top;
    while(i<j)
    {
        q=top;
        while(m<l-1)
        {
            q=q->link;
            m++;
        }
        temp=p->num;
        p->num=q->num;
        q->num=temp;
        p=p->link;
        n++;
        m=n;
        i++;
        j--;
    }
    return top;
}
