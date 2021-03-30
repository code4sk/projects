#include <stdio.h>
#include <stdlib.h>

struct node
{
    int marks,rthread,lthread;
    struct node *left,*right;
};
void insert(int);
void delete(int);
void in(struct node *);
void case_a(struct node *,struct node *);
void case_b(struct node *,struct node *);
struct node *root,*cork;
int main()
{
    int c,n;
    while(1)
    {
        printf("Enter your choice\n1:Insert\n2:Delete\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : printf("Enter the marks of node\n");
                     scanf("%d",&n);
                     insert(n);
                     in(root);
                     puts("");
                     break;
            case 2 : printf("Enter the marks of node\n");
                     scanf("%d",&n);
                     delete(n);
                     in(root);
                     puts("");
                     break;
        }
    }
    return 0;
}
void insert(int n)
{
    struct node *temp,*p;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->left=NULL;
    temp->right=NULL;
    temp->lthread=0;
    temp->rthread=0;
    temp->marks=n;
    if(root==NULL)
        root=temp;
    else
    {
        p=root;
        while(p)
        {
            if(p->marks>n)
            {
                if(p->left!=NULL&&p->lthread==0)
                p=p->left;
                else
                    break;
            }
            else if(p->marks<n)
            {
                if(p->right!=NULL&&p->rthread==0)
                p=p->right;
                else
                    break;
            }
        }
            if((p->lthread==1||p->left==NULL)&&(p->rthread==1||p->right==NULL))
            {
                if(p->marks<temp->marks)
                {
                    if(p->right!=NULL)
                    {
                    temp->rthread=1;
                    temp->right=p->right;
                    }
                    p->right=temp;
                    p->rthread=0;
                    temp->left=p;
                    temp->lthread=1;
                    return;
                }
                if(p->marks>temp->marks)
                {
                    if(p->left!=NULL)
                    {
                    temp->left=p->left;
                    temp->lthread=1;
                    }
                    p->lthread=0;
                    p->left=temp;
                    temp->rthread=1;
                    temp->right=p;
                    return;
                }
            }
            else if(((p->lthread==1||p->left==NULL)&&p->rthread==0)||((p->rthread==1||p->right==NULL)&&p->lthread==0))
            {
                if(p->lthread==1||p->left==NULL)
                {
                    if(p->left!=NULL)
                    {
                    temp->left=p->left;
                    temp->lthread=1;
                    }
                    p->left=temp;
                    temp->right=p;
                    temp->rthread=1;
                    return;
                }
                if(p->rthread==1||p->right==NULL)
                {
                    if(p->right!=NULL)
                    {
                    temp->right=p->right;
                    temp->rthread=1;
                    }
                    p->right=temp;
                    temp->left=p;
                    temp->lthread=1;
                    return;
                }
            }
    }
}
void in(struct node *p)
{
    if(p->left!=NULL&&p->lthread==0)
        in(p->left);
    printf("%d\t",p->marks);
    if(p->right!=NULL&&p->rthread==0)
        in(p->right);
}
void delete(int n)
{
    struct node *p=root,*par=root,*t;
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
    if((p->lthread==1||p->left==NULL)&&(p->rthread==1||p->right==NULL))
    {
        case_a(par,p);
        return;
    }
    else if(((p->lthread==1||p->left==NULL)&&p->rthread==0)||((p->rthread==1||p->right==NULL)&&p->lthread==0))
    {
        case_b(par,p);
        return;
    }
    else if(p->lthread==0&&p->rthread==0)
    {
        t=p->right;
        par=p;
        while(t->left)
        {
            par=t;
            t=t->left;
        }
        p->marks=t->marks;
        p=t;
    if((p->lthread==1||p->left==NULL)&&(p->rthread==1||p->right==NULL))
    {
        case_a(par,p);
        return;
    }
    else if(((p->lthread==1||p->left==NULL)&&p->rthread==0)||((p->rthread==1||p->right==NULL)&&p->lthread==0))
    {
        case_b(par,p);
        return;
    }
    }
}
void case_a(struct node *par,struct node *p)
{
    if(p==root)
    {
        root=NULL;
        free(p);
        return;
    }
    else
    {
        if(par->left==p)
        {
            if(p->left!=NULL)
            {
                par->lthread=1;
            }
            par->left=p->left;
            free(p);
            return;
        }
        else if(par->right==p)
        {
            if(p->right!=NULL)
            {
                par->rthread=1;
            }
            par->right=p->right;
            free(p);
            return;
        }
    }
}
void case_b(struct node *par,struct node *p)
{
    struct node *t;
    if(p==root)
    {
        if(p->lthread==1||p->left==NULL)
        {
            root=p->right;
            t=p->right;
            while(t->left)
            t=t->left;
            t->left=NULL;
            t->lthread=0;
            return;
        }
        else if(p->rthread==1||p->right==NULL)
        {
            root=p->left;
            t=p->left;
            while(t->right)
            t=t->right;
            t->right=NULL;
            t->rthread=0;
            return;
        }
    }
    else
    {
        if(par->left==p)
        {
            if(p->lthread==1||p->left==NULL)
            {
                par->left=p->right;
                (p->right)->left=p->left;
                if(p->left==NULL)
                    (p->right)->lthread=0;
                    free(p);
                    return;
            }
            else if(p->rthread==1||p->right==NULL)
            {
                par->left=p->left;
                (p->left)->right=p->right;
                if(p->right==NULL)
                    (p->left)->rthread=0;
                    free(p);
                    return;
            }
        }
        else if(par->right==p)
        {
            if(p->lthread==1||p->left==NULL)
            {
                par->right=p->right;
                p->right->left=p->left;
                if(p->left==NULL)
                    p->right->left->lthread=0;
                    free(p);
                    return;
            }
            else if(p->rthread==1||p->right==NULL)
            {
                par->right=p->left;
                p->left->left=p->right;
                if(p->right==NULL)
                    p->left->right->rthread=0;
                    free(p);
                    return;
            }
        }
    }
}
