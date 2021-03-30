#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left,*right;
    int marks,lthread,rthread;
};
struct node *l;
struct node *create();
struct node *rthread(struct node *);
struct node *lthread(struct node *);
struct node *suc(struct node *,int);
struct node *pred(struct node *,int);
struct node *insert(struct node *);
struct node *delete(struct node *);
struct node *case_a(struct node *,struct node *,struct node *);
struct node *case_b(struct node *,struct node *,struct node *);
struct node *case_c(struct node *,struct node *,struct node *);
int main()
{
    int c=-1,n;
    struct node *root,*k;
    root=create();
    lthread(root);
    rthread(root);
    while(c!=5)
    {
        printf("Enter your choice\n1:Insert\n2:Delete\n3:Successor\n4:Predecessor\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : root=insert(root);
            break;
            case 2 : root=delete(root);
            break;
            case 3 : printf("Enter the marks\n");
                     scanf("%d",&n);
                     k=suc(root,n);
                     if(k!=NULL)
                     printf("Successor of %d is %d\n",n,k->marks);
                     else
                     printf("%d has no successor\n",n);
            break;
            case 4 : printf("Enter the marks\n");
                     scanf("%d",&n);
                     k=pred(root,n);
                     if(k!=NULL)
                     printf("predecessor of %d is %d\n",n,k->marks);
                     else
                     printf("%d has no predecessor\n",n);
            break;
        }
    }
    return 0;
}
struct node *create()
{
    struct node *root=NULL,*par=NULL,*p,*temp;
    int n;
    printf("Enter the number  of node\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->left=NULL;
        temp->right=NULL;
        temp->lthread=0;
        temp->rthread=0;
        printf("Enter the marks of student %d\t",i+1);
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
struct node *rthread(struct node *p)
{
    if(p==NULL)
        return NULL;
    if(p->lthread==1||p->left==NULL&&p->right==NULL||p->rthread==1)
        return p;
    if(p->lthread==0)
    {
        l=rthread(p->left);
        l->right=p;
        l->rthread=1;
    }
    if(p->right==NULL||p->rthread==1)
        return p;
        return rthread(p->right);
}
struct node *lthread(struct node *p)
{
    if(p==NULL)
        return NULL;
    if(p->left==NULL||p->lthread==1&&p->right==NULL||p->rthread==1)
        return p;
    if(p->right)
    {
        l=lthread(p->right);
        l->left=p;
        l->lthread=1;
    }
    if(p->left==NULL||p->lthread==1)
        return p;
    return lthread(p->left);
}
struct node *suc(struct node *p,int n)
{
    while(p)
    {
        if(p->marks==n)
            break;
        else if(p->marks>n)
            p=p->left;
        else if(p->marks<n)
            p=p->right;
    }
    if(p->right==NULL)
    {
        return NULL;
    }
    else if(p->rthread==1)
    {
        p=p->right;
        return p;
    }
    else
    {
        p=p->right;
        while(p->lthread==0)
            p=p->left;
        return p;
    }
}
struct node *pred(struct node *p,int n)
{
    while(p)
    {
        if(p->marks==n)
            break;
        else if(p->marks>n)
            p=p->left;
        else if(p->marks<n)
            p=p->right;
    }
    if(p->left==NULL)
    {
        return NULL;
    }
    else if(p->lthread==1)
    {
        p=p->left;
        return p;
    }
    else
    {
        p=p->left;
        while(p->lthread==0&&p->left!=NULL)
            p=p->left;
        return p;
    }
}
struct node *insert(struct node *p)
{
    struct node *root=p,*temp;
    printf("\nEnter the marks to be inserted\t");
    temp=(struct node *)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->lthread=0;
    temp->rthread=0;
    scanf("%d",&temp->marks);
    if(p==NULL)
    {
        return temp;
    }
    while(p)
    {
        if(p->marks>temp->marks)
            if(p->lthread==0&&p->left!=NULL)
            p=p->left;
            else
                break;
       else if(p->marks<temp->marks)
            if(p->rthread==0&&p->right!=NULL)
            p=p->right;
            else
                break;
    }
    if(p->marks>temp->marks)
    {
        temp->left=p->left;
        p->left=temp;
        p->lthread=0;
        if(temp->left!=NULL)
        temp->lthread=1;
        temp->right=p;
        temp->rthread=1;
        return root;
    }
    else if(p->marks<temp->marks)
    {
        temp->right=p->right;
        p->right=temp;
        p->rthread=0;
        if(temp->right!=NULL)
        temp->rthread=1;
        temp->left=p;
        temp->lthread=1;
        return root;
    }
}
struct node *delete(struct node *p)
{
     struct node *par,*root=p;
     int n;
     printf("Enter the marks you want to delete\n");
     scanf("%d",&n);
     while(p)
     {
         if(p->marks==n)
            break;
            par=p;
         if(p->marks>n)
            p=p->left;
         else if(p->marks<n)
            p=p->right;
     }
     if(p->lthread==1||p->left==NULL&&p->rthread==1||p->right==NULL)
     {
         return case_a(root,par,p);
     }
     else if(p->lthread==1&&p->rthread==0||p->lthread==0&&p->rthread==1&&p->left!=NULL&&p->right!=NULL)
     {
         return case_b(root,par,p);
     }
     if(p->lthread==0&&p->rthread==0&&p->left!=NULL&&p->right!=NULL)
     {
         return case_c(root,par,p);
     }
}
struct node *case_a(struct node *root,struct node *par,struct node *p)
{
    if(root==p)
    {
        free(root);
        return NULL;
    }
    if(par->left==p)
         {
             par->left=p->left;
             if(par->left!=NULL)
             par->lthread=1;
             free(p);
             return root;
         }
         else if(par->right==p)
         {
             par->right=p->right;
             if(par->right!=NULL)
             par->rthread=1;
             free(p);
             return root;
         }
}
struct node *case_b(struct node *root,struct node *par,struct node *p)
{
     if(root==p)
     {
         if(root->lthread==0&&root->left!=NULL)
         {
         if((pred(root,root->marks))->right==root->left)
         {
             return root->left;
         }
            else
            {
                pred(root,root->marks)->right=root->left;
                return root->left;
            }
         }
         else if(root->rthread==0&&root->right!=NULL)
         {
         if((suc(root,root->marks))->left==root->right)
         {
             return root->right;
         }
            else
            {
                suc(root,root->marks)->left=root->right;
                return root->right;
            }
         }
     }
    if(par->right==p)
         {
             if(p->lthread==0)
             {
             par->right=p->left;
             p->left->right=p->right;
             }
             else if(p->rthread==0)
             {
             par->right=p->right;
             p->right->right=p->right;
             }
             free(p);
         }
         else if(par->left==p)
         {
             if(p->lthread==0)
             {
             par->left=p->left;
             p->left->right=p->right;
             }
             else if(p->rthread==0)
             {
             par->left=p->right;
             p->right->right=p->right;
             }
             free(p);
             }
         return root;
}
struct node *case_c(struct node *root,struct node *par,struct node *p)
{
         int n;
         struct node *t,*q,*s;
         t=suc(p,p->marks);
         q=root;
         while(q)
         {
             if(q->marks==t->marks)
                break;
             par=q;
             if(q->marks>t->marks)
            q=q->left;
         else if(q->marks<t->marks)
            q=q->right;
         }
         if(t->lthread==1||t->left==NULL&&t->rthread==1||t->right==NULL)
     {
         s=case_a(root,par,t);
         p->marks=t->marks;
         return s;
     }
     else if(t->lthread==1&&t->rthread==0||t->lthread==0&&t->rthread==1&&t->left!=NULL&&t->right!=NULL)
     {
         s=case_b(root,par,t);
         p->marks=t->marks;
         return s;
     }
}
