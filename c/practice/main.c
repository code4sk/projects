#include <stdio.h>
#include <stdlib.h>

struct node
{
    int marks;
    struct node *link;
};
int l;
struct node *root;
void create();
void insert();
void delete();
void display();
void reverse();
void reverse_link();
void swap(int *a,int *b);
void ssort();
void ssort_link();
void bsort();
void bsort_link();
int main()
{
    int c;
    create();
    display();
    while(1)
    {
        printf("Enter your choice\n1:Insert\n2:Delete\n3:Reverse\n4:Selection sort\n5:Bubble sort\n");
        scanf("%d",&c);
        switch(c)
    {
        case 1 : insert();
                 display();
                 break;
        case 2 : delete();
                 display();
                 break;
        case 3 : reverse_link();
                 display();
                 break;
        case 4 : ssort_link();
                 display();
                 break;
        case 5 : bsort_link();
                 display();
                 break;
    }
    }
    return 0;
}
void create()
{
    int n;
    struct node *temp,*p;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        temp=(struct node *)calloc(1,sizeof(struct node));
        temp->link=NULL;
        printf("Enter the marks of node\t%d\n",i+1);
        scanf("%d",&temp->marks);
        if(root==NULL)
            root=temp;
        else
        {
            p=root;
            while(p->link)
                p=p->link;
                p->link=temp;
        }
    }
}
void display()
{
    struct node *p=root;
    l=0;
    while(p)
    {
        l++;
        printf("%d\t",p->marks);
        p=p->link;
    }
    puts("");
}
void insert()
{
    struct node *temp,*p;
    int n;
    printf("Enter the marks of the node\n");
    scanf("%d",&n);
    temp=(struct node *)malloc(sizeof(struct node));
    temp->link=NULL;
    temp->marks=n;
    if(root==NULL)
        root=temp;
    else
    {
        p=root;
        while(p->link)
        p=p->link;
        p->link=temp;
    }
}
void delete()
{
    int n;
    struct node *p=root;
    printf("Enter the marks of node to be deleted\n");
    scanf("%d",&n);
    if(p->marks==n)
    {
        root=p->link;
        free(p);
        return;
    }
    while(p->link)
    {
        if((p->link)->marks==n)
        {
            p->link=p->link->link;
            return;
        }
        else
            p=p->link;
    }
}
void reverse()
{
    int i=0,j=l,m=2;
    struct node *p=root,*t;
    while(i<j)
    {
        m=2;
        t=root;
        while(m<=j)
        {
            t=t->link;
            m++;
        }
        swap(&p->marks,&t->marks);
        i++;
        j--;
        p=p->link;
    }
}
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void reverse_link()
{
    struct node *q,*p=root,*r=root;
    q=NULL;
    while(p)
    {
        r=p->link;
        p->link=q;
        q=p;
        p=r;
    }
    root=q;
}
void ssort()
{
    struct node *p,*q;
    for(p=root;p!=NULL;p=p->link)
    {
        for(q=p->link;q!=NULL;q=q->link)
        {
            if(p->marks>q->marks)
                swap(&p->marks,&q->marks);
        }
    }
}
void ssort_link()
{
    struct node *r,*p,*q,*s,*temp;
    for(p=root,r=root;p!=NULL;r=p,p=p->link)
    {
        for(s=q=p->link;q!=NULL;s=q,q=q->link)
        {
            if(p->marks>q->marks)
            {
                temp=p->link;
                p->link=q->link;
                q->link=temp;
                s->link=p;
                if(p!=root)
                r->link=q;
                else
                root=q;
                temp=p;
                p=q;
                q=temp;
            }
        }
    }
}
void bsort()
{
    struct node *p,*q,*end;
    for(end=NULL;end!=root->link;end=q)
    {
        for(p=root;p->link!=end;p=p->link)
        {
            q=p->link;
            if(p->marks>q->marks)
            swap(&p->marks,&q->marks);
        }
    }
}
void bsort_link()
{
    struct node *p,*r,*q,*end,*temp;
    for(end=NULL;end!=root->link;end=q)
    {
        for(r=p=root;p->link!=end;r=p,p=p->link)
        {
            q=p->link;
            if(p->marks>q->marks)
            {
                p->link=q->link;
                q->link=p;
                if(p==root)
                    root=q;
                else
                    r->link=q;
                temp=p;
                p=q;
                q=temp;
            }
        }
    }
}
