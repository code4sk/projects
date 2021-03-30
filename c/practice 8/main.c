#include <stdio.h>
#include <stdlib.h>

struct node
{
    int marks;
    int balance;
    struct node *left;
    struct node *right;
};
void delete(struct node *p,int n);
int flag=1,help=1;
struct node *root;
int height(struct node *p);
int balance(struct node *p);
void check(struct node *p);
void insert(struct node *p,struct node *temp);
void RR(struct node *p,struct node *par);
void in(struct node *p);
int main()
{
    struct node *temp;
    int c,n;
    while(1)
    {
    printf("Enter your choice\n1:Insert\n2:Delete\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1 : printf("Enter the marks of inserted node\n");
                 flag=1;
                 help=1;
                 temp=(struct node *)malloc(sizeof(struct node));
                 temp->left=NULL;
                 temp->right=NULL;
                 temp->balance=0;
                 scanf("%d",&temp->marks);
                 insert(root,temp);
                 in(root);
                 break;
        case 2 : printf("Enter the marks of deleted node\n");
                 scanf("%d",&n);
                 flag=1;
                 help=1;
                 delete(root,n);
                 in(root);
                 break;

    }
    }
    return 0;
}
void case_b(struct node *par,struct node *p);
void delete_node(struct node *p);
void case_c(struct node *par,struct node *p);
int height(struct node *p)
{
    if(p==NULL)
        return 0;
    if(p->left==NULL&&p->right==NULL)
        return 1;
    int left,right;
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
void insert(struct node *p,struct node *temp)
{
    int i,j;
    if(root==NULL)
    {
        root=temp;
        return;
    }
    if(p==NULL)
        return;
    if(p->marks>temp->marks)
        insert(p->left,temp);
    else if(p->marks<temp->marks)
        insert(p->right,temp);
        i=p->balance;
    if(flag)
    {
        if(p->marks>temp->marks)
            p->left=temp;
        else
            p->right=temp;
            flag=0;
    }
    j=balance(p);
    if(help)
    {
    if((i==-1||i==+1)&&j==0)
    {
        p->balance=j;
        help=0;
        return;
    }
    else if(i==0&&(j==-1||j==+1))
    {
        p->balance=j;
        return;
    }
    else if((i==-1||i==+1)&&(j==-2||j==+2))
            {
                check(p);
                return;
            }
    }
}
void check(struct node *p)
{
    int j;
    struct node *t=root,*par=root;
    while(t)
    {
        if(t->marks==p->marks)
            break;
        par=t;
        if(t->marks>p->marks)
            t=t->left;
        else
            t=t->right;
    }
    j=balance(p);
    if(j<-1)
    {
        if(balance(p->right)<=0)
        {
            RR(p,par);
            return;
        }
        else
        {
            RL(p,par);
            return;
        }
    }
    else
    {
        if(balance(p->left)>=0)
        {
            LL(p,par);
            return;
        }
        else
        {
            LR(p,par);
            return;
        }
    }
}
void RR(struct node *p,struct node *par)
{
    struct node *q=p->right;
    p->right=q->left;
    q->left=p;
    if(p==root)
        root=q;
    else
    {
    if(par->right==p)
    par->right=q;
    else
    par->left=q;
    }
    p->balance=balance(p);
    q->balance=balance(q);
    p=q;
}
void LL(struct node *p,struct node *par)
{
    struct node *q=p->left;
    p->left=q->right;
    q->right=p;
    if(p==root)
        root=q;
    else
    {
    if(par->right==p)
    par->right=q;
    else
    par->left=q;
    }
    p->balance=balance(p);
    q->balance=balance(q);
    p=q;
}
void RL(struct node *p,struct node *par)
{
    LL(p->right,p);
    RR(p,par);
}
void LR(struct node *p,struct node *par)
{
    RR(p->left,p);
    LL(p,par);
}
void in(struct node *p)
{
    if(p->left)
        in(p->left);
    printf("%d\t%d\n",p->marks,p->balance);
    if(p->right)
        in(p->right);
}
void delete(struct node *p,int n)
{
    int i,j;
    if(p->marks>n)
    delete(p->left,n);
    else if(p->marks<n)
    delete(p->right,n);
    i=p->balance;
    if(flag)
    {
        delete_node(p);
        flag=0;
    }
    j=balance(p);
    if(help)
    {
        if((i==-1||i==+1)&&j==0)
        {
            p->balance=j;
            return;
        }
        else if(i==0&&(j==-1||j==+1))
        {
            p->balance=j;
            help=0;
            return;
        }
        else if((i==-1||i==+1)&&(j==-2||j==+2))
        {
            check(p);
            return;
        }
    }
}
void delete_node(struct node *p)
{
    struct node *par,*k=root;
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
        case_b(par,p);
        return;
    }
    else if((p->left==NULL&&p->right!=NULL)||(p->right==NULL&&p->left!=NULL))
    {
        case_c(par,p);
        return;
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
        case_b(j,q);
        return;
    }
    else if((q->left==NULL&&q->right!=NULL)||(q->right==NULL&&q->left!=NULL))
    {
        case_c(j,q);
        return;
    }
    }
}
void case_b(struct node *par,struct node *p)
{
    if(p==root)
    {
        root=NULL;
        free(p);
        return;
    }
    else if(par->left==p)
        {
            par->left=NULL;
            free(p);
            return;
        }
        else if(par->right==p)
        {
            par->right=NULL;
            free(p);
            return;
        }
}
void case_c(struct node *par,struct node *p)
{
        if(p==root)
        {
            if(p->left)
            {
                root=p->left;
                free(p);
                return;
            }
            else if(p->right)
            {
                root=p->right;
                free(p);
                return;
            }
        }
            if(p->right)
        {
            if(par->right==p)
            {
                par->right=p->right;
                free(p);
                return;
            }
            else if(par->left==p)
            {
                par->left=p->right;
                free(p);
                return;
            }
        }
        else if(p->left)
        {
            if(par->right==p)
            {
                par->right=p->left;
                free(p);
                return;
            }
            else if(par->left==p)
            {
                par->left=p->left;
                free(p);
                return;
            }
        }
}
