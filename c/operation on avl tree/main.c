#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node *t;
struct node
{
    struct node *left;
    int marks;
    struct node *right;
    int balance;
};
struct node *t;
int flag=1,gate=1,help=1,save=1;
struct node *create();
void in(struct node *);
struct node *avl(struct node *);
struct node *LL(struct node *);
struct node *RR(struct node *);
struct node *LR(struct node *);
struct node *RL(struct node *);
int height(struct node *);
int balance(struct node *);
struct node *insert(struct node *,struct node *);
struct node *case_a(struct node *);
struct node *delete(struct node *,int);
struct node *dnode(struct node *);
struct node *case_b(struct node *,struct node *);
struct node *case_c(struct node *,struct node *);
int main()
{
    int c=10,n;
    struct node *root,*temp;
    root=create();
    t=root;
    in(root);
    puts("");
    root=avl(root);
    in(root);
    while(c!=3)
    {
        printf("Enter your choice\n1:Insert\n2:Delete\n3:Quit\n");
        scanf("%d",&c);
        switch(c)
    {
        case 1 : temp=(struct node *)malloc(sizeof(struct node));
                 temp->left=NULL;
                 temp->right=NULL;
                 printf("\nEnter the marks of node\n");
                 scanf("%d",&temp->marks);
                 gate=1;
                 flag=1;
                 root=insert(root,temp);
                 in(root);
                 break;
        case 2 : printf("\nEnter the marks of node\n");
                 scanf("%d",&n);
                 help=1;
                 save=1;
                 root=delete(root,n);
                 in(root);
                 break;
        default : puts("Have a nice day.......");
                 break;
    }
    }
    return 0;
}
struct node *create()
{
    int n;
    struct node *root=NULL,*temp,*p,*par;
    printf("Enter the number of nodes\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->left=NULL;
        temp->right=NULL;
        printf("Enter the marks in node %d\t",i+1);
        scanf("%d",&temp->marks);
        if(root==NULL)
            root=temp;
        else
        {
            p=root;
        while(p)
        {
            par=p;
            if(p->marks>temp->marks)
                p=p->left;
            else if(p->marks<temp->marks)
                p=p->right;
        }
         if(par->marks>temp->marks)
                par->left=temp;
            else if(par->marks<temp->marks)
                par->right=temp;
        }
    }
    return root;
}
void in(struct node *p)
{
    if(p==NULL)
        return;
    if(p->left)
        in(p->left);
    printf("%d\t",p->marks);
    p->balance=balance(p);
    printf("%d\n",p->balance);
    if(p->right)
        in(p->right);
}
struct node *RR(struct node *p)
{
    struct node *q,*par,*k=t;
    while(k)
    {
        if(p->marks==k->marks)
            break;
        par=k;
        if(k->marks>p->marks)
            k=k->left;
        else if(k->marks<p->marks)
            k=k->right;
    }
    q=p->left;
    p->left=q->right;
    q->right=p;
    if(p->marks!=t->marks)
    {
     if(par->right==p)
    par->right=q;
    else
    par->left=q;
    }
    p->balance=balance(p);
    q->balance=balance(q);
    if(p->marks==t->marks)
        t=q;
    return q;
}
struct node *LL(struct node *p)
{
    struct node *q,*par,*k=t;
     while(k)
    {
        if(p->marks==k->marks)
            break;
        par=k;
        if(k->marks>p->marks)
            k=k->left;
        else if(k->marks<p->marks)
            k=k->right;
    }
    q=p->right;
    p->right=q->left;
    q->left=p;
    if(p->marks!=t->marks)
    {
     if(par->right==p)
    par->right=q;
    else
    par->left=q;
    }
    p->balance=balance(p);
    q->balance=balance(q);
    if(p->marks==t->marks)
        t=q;
    return q;
}
struct node *LR(struct node *p)
{
    struct node *q;
    q=p->left;
    q=LL(q);
    return RR(p);
}
struct node *RL(struct node *p)
{
    struct node *q;
    q=p->right;
    q=RR(q);
    return LL(p);
}
int height(struct node *p)
{
    int left,right;
    if(!p)
        return 0;
    left=height(p->left);
    right=height(p->right);
    if(left>right)
    return 1+left;
    else
    return 1+right;
}
int balance(struct node *p)
{
    return height(p->left)-height(p->right);
}
struct node *avl(struct node *p)
{
    if(p==NULL)
        return NULL;
    while(p->balance>1||p->balance<-1)
    {
    if(balance(p)>1)
    {
        if(balance(p->left)>=0)
            p=RR(p);
        else if(balance(p->left)<0)
            p=LR(p);
    }
    else if(balance(p)<-1)
    {
        if(balance(p->right)>0)
            p=RL(p);
        else if(balance(p->right)<=0)
            p=LL(p);
    }
    }
    if(p->left)
    avl(p->left);
    if(p->right)
    avl(p->right);
    return t;
}
struct node *insert(struct node *p,struct node *temp)
{
    if(p==NULL)
    {
        t=temp;
        return t;
    }
    int b;
        if(p->marks>temp->marks)
            {
                if(p->left)
                {
                insert(p->left,temp);
                }
            }
        else if(p->marks<temp->marks)
            {
                if(p->right)
                {
                insert(p->right,temp);
                }
            }
    if(flag)
    {
    if(p->marks>temp->marks)
        p->left=temp;
    else if(p->marks<temp->marks)
        p->right=temp;
        flag=0;
    }
    b=balance(p);
    if(gate)
    {
    if(b==0)
    {
        p->balance=b;
        gate=0;
        return t;
    }
    else
    {
            return case_a(p);
    }
    }
    return t;
}
struct node *case_a(struct node *p)
{
    while(balance(p)>1||balance(p)<-1)
    {
    if(balance(p)>1)
    {
        if(balance(p->left)>=0)
            p=RR(p);
        else if(balance(p->left)<0)
            p=LR(p);
    }
    else if(balance(p)<-1)
    {
        if(balance(p->right)>0)
            p=RL(p);
        else if(balance(p->right)<=0)
            p=LL(p);
    }
    }
    p->balance=balance(p);
    return t;
}
struct node *delete(struct node *p,int n)
{
    int a,b;
    if(p==NULL)
        return NULL;
    if(p->marks>n)
    {
        a=balance(p);
        delete(p->left,n);
    }
    else if(p->marks<n)
    {
        a=balance(p);
        delete(p->right,n);
    }
    if(help)
    {
        p=dnode(p);
        help=0;
    }
    if(p!=NULL)
    b=balance(p);
    else
        return t;
    if(save)
    {
    if((b==-1||b==+1)&&(a==0))
    {
        p->balance=b;
        save=0;
        return t;
    }
    else
    {
        return case_a(p);
    }
    }
    return t;
}
struct node*dnode(struct node *p)
{
    struct node *par,*k=t;
    while(k)
    {
        if(k->marks==p->marks)
            break;
            par=k;
        if(k->marks>p->marks)
            k=k->left;
        else if(k->marks<p->marks)
            k=k->right;
    }
    if(p->left==NULL&&p->right==NULL)
    {
        return case_b(par,p);
    }
    else if((p->left==NULL&&p->right!=NULL)||(p->right==NULL&&p->left!=NULL))
    {
        return case_c(par,p);
    }
    else  if(p->left!=NULL&&p->right!=NULL)
    {
        struct node *j=p,*q=p->right;
        while(q)
        {
            if(q->left)
            {
                j=q;
                q=q->left;
            }
            else
                break;
        }
        p->marks=q->marks;
    if(q->left==NULL&&q->right==NULL)
    {
        return case_b(j,q);
    }
    else if((q->left==NULL&&q->right!=NULL)||(q->right==NULL&&q->left!=NULL))
    {
        return case_c(j,q);
    }
    }
}
struct node *case_b(struct node *par,struct node *p)
{
    if(p==t)
    {
        t=NULL;
        free(p);
        return t;
    }
    else if(par->left==p)
        {
            par->left=NULL;
            free(p);
            return par;
        }
        else if(par->right==p)
        {
            par->right=NULL;
            free(p);
            return par;
        }
}
struct node *case_c(struct node *par,struct node *p)
{
        if(p==t)
        {
            if(p->left)
            {
                t=p->left;
                free(p);
                return t;
            }
            else if(p->right)
            {
                t=p->right;
                free(p);
                return t;
            }
        }
            if(p->right)
        {
            if(par->right==p)
            {
                par->right=p->right;
                free(p);
                return par;
            }
            else if(par->left==p)
            {
                par->left=p->right;
                free(p);
                return par;
            }
        }
        else if(p->left)
        {
            if(par->right==p)
            {
                par->right=p->left;
                free(p);
                return par;
            }
            else if(par->left==p)
            {
                par->left=p->left;
                free(p);
                return par;
            }
        }
}
