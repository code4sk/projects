#include <stdio.h>
#include <stdlib.h>

struct node
{
    char chr;
    struct node *link;
};
int l;
struct node *create();
show(struct node *start);
struct node *choice(struct node *start);
struct node *insert(struct node *start);
struct node *delete(struct node *start);
struct node *reverse(struct node *start);
int main()
{
    char b='y',c;
    struct node *start;
    printf("LINKED LIST BEFORE INSERTION:\n\n ");
    start=create();
    show(start);
    while(b=='y'||(b=='Y'))
    {
    start=choice(start);
    show(start);
    printf("\nDO YOU WANT TO CONTINUE\nENTER y/n\n");
    scanf(" %c",&b);
    }
    puts("HAVE A NICE DAY");
    return 0;
}
struct node *create()
{
    struct node *start='\0';
    struct node *temp;
    struct node *p;
    for(int i=0;i<6;i++)
    {
        temp=(struct node *)malloc(sizeof(int));
        temp->link=NULL;
        switch(i+1)
        {
             case 1: temp->chr='G';
            break;
             case 2: temp->chr='O';
            break;
             case 3: temp->chr='O';
            break;
             case 4: temp->chr='G';
            break;
             case 5: temp->chr='L';
            break;
             case 6: temp->chr='E';
            break;
        }
        l=6;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            p=start;
            while((p->link)!=NULL)
            {
                p=p->link;
            }
            (p->link)=(temp);
        }
    }
    p=start;
    while(p->link!=NULL)
        p=p->link;
    p->link=start;
    return start;
}
show(struct node *start)
{
    l=0;
    struct node *p;
    p=start;
    printf("\t");
    do
    {
        printf("\t%c",p->chr);
        p=p->link;
        l++;
    }while(p!=start);
    printf("\n%d",l);
}
struct node *choice(struct node *start)
{
    int c;
    printf("\nENTER YOUR CHOICE\n1:INSERT\n2:DELETE\n3:REVERSE\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1 : start=insert(start);
                 printf("\nLINKED LIST AFTER INSERTION:\n\n ");
                 return start;
                 break;
        case 2 : start=delete(start);
                 printf("\nLINKED LIST AFTER DELETION:\n\n ");
                 return start;
                 break;
        case 3 : start=reverse(start);
                 printf("\nLINKED LIST AFTER REVERSING:\n\n ");
                 return start;
                 break;
       default : printf("\n\t\t***-------------------------INVALID OPERATION--------------------------***\n");
                 return start;
                 break;
    }

}
struct node *insert(struct node *start)
{
    int n,i=2,j=1;
    struct node *p,*t;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(int));
        temp->link=NULL;
        temp->chr='S';

        printf("\nENTER POSITION WHERE YOU WANT TO ENTER 'S'\t");
        scanf("\t%d",&n);
        p=start;
        t=start;
        while(i<n)
        {
            p=p->link;
            i++;
        }
        while(j<n)
        {
            t=t->link;
            j++;
        }
        if(n!=1)
        {
            p->link=temp;
            temp->link=t;
            return start;
        }
        else
        {
            temp->link=start;
            return temp;
        }


}
struct node *delete(struct node *start)
{
    struct node *p,*t;
    int n,i=2,j=0;
    printf("\nENTER POSITION WHICH YOU WANT TO DELETE\t");
    scanf("\t%d",&n);
    p=start;
    t=start;
        while(i<n)
        {
            p=p->link;
            i++;
        }
        while(j<n)
        {
            t=t->link;
            j++;
        }
        if(n!=1&&n!=l)
        {
            p->link=t;
            return start;
        }
        if(n==1)
        {
            start=t;
            return start;
        }
        if(n==l)
        {
            p->link=start;
            return start;
        }
}
struct node *reverse(struct node *start)
{
   struct node *prev,*ptr,*next;
   prev=NULL;
   ptr=start;
   while(ptr!=NULL)
   {
       next=ptr->link;
       ptr->link=prev;
       prev=ptr;
       ptr=next;
   }
   return prev;
}

