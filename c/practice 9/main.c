#include <stdio.h>
#include <stdlib.h>

enum c{black,red};
struct node
{
    enum c color;
    int marks;
    struct node *left;
    struct node *right;
    struct node *parent;
};
void case_b(struct node *par,struct node *p);
void delete_node(struct node *p);
void case_c(struct node *par,struct node *p);
int flag=1,help=1;
struct node *temp;
void in(struct node *p);
void recolor(struct node *p);
void L(struct node *p,struct node *par);
struct node *root,*cork;
void delete(struct node *p,int n);
void insert(struct node *p,struct node *temp);
int main()
{
    int n,c;
    cork=(struct node *)malloc(sizeof(struct node));
    cork->color=black;
    cork->left=NULL;
    cork->right=NULL;
    cork->marks=-1;
    root=cork;
    while(1)
    {
        printf("Enter your choice\n1:Insert\n2:Delete\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : printf("Enter the marks of the node to be inserted\n");
                     temp=(struct node *)malloc(sizeof(struct node));
                     temp->left=cork;
                     temp->right=cork;
                     temp->color=red;
                     temp->parent=NULL;
                     flag=1;
                     help=1;
                     scanf("%d",&temp->marks);
                     insert(root,temp);
                     in(root);
                     break;
            case 2 : printf("Enter the marks of the node to be deleted\n");
                     scanf("%d",&n);
                     delete(root,n);
                     if(root!=cork);
                     in(root);
                     printf("\n\n%d\n\n",root->marks);
                     break;
        }
    }
    return 0;
}
void in(struct node *p)
{
    if(p->left!=cork)
        in(p->left);
        printf("%d\t%d\n",p->marks,p->color);
    if(p->right!=cork)
        in(p->right);
}
void insert(struct node *p,struct node *temp)
{
    if(root==cork)
    {
        root=temp;
        temp->color=black;
        return;
    }
    if(p==cork)
        return;
    if(p->marks>temp->marks)
        insert(p->left,temp);
    else
        insert(p->right,temp);
    if(flag)
    {
        if(p->marks>temp->marks)
            p->left=temp;
        else
            p->right=temp;
            temp->parent=p;
        flag=0;
    }
    if(help)
    {
        struct node *grand=p->parent;
        if(p->color==red)
        {
            if(grand->left==p)
            {
                struct node *uncle=grand->right;
                if(uncle->color==red)
                {
                    recolor(uncle);
                    recolor(p);
                    recolor(grand);
                    if(root->color==red)
                        recolor(root);
                    return;
                }
                else
                {
                    if(p->right==temp)
                    {
                        L(p,grand);
                    }
                    if(p->left=temp)
                    {
                        recolor(p);
                        recolor(grand);
                        if(root->color==red)
                        recolor(root);
                        R(grand,grand->parent);
                    }
                }
            }
            else if(grand->right==p)
            {
                struct node *uncle=grand->left;
                if(uncle->color==red)
                {
                    recolor(uncle);
                    recolor(p);
                    recolor(grand);
                    if(root->color==red)
                        recolor(root);
                    return;
                }
                else
                {
                    if(p->left==temp)
                    {
                        R(p,grand);
                    }
                    if(p->right=temp)
                    {
                        recolor(p);
                        recolor(grand);
                        if(root->color==red)
                        recolor(root);
                        L(grand,grand->parent);
                    }
                }
            }
        }
        else return;
    }
}
void recolor(struct node *p)
{
    if(p->color==black)
    p->color=red;
    else
    p->color=black;
}
void L(struct node *p,struct node *par)
{
    struct node *q=p->right;
    p->right=q->left;
    q->left=p;
    if(p==root)
        root=q;
    else
    {
        if(par->left==p)
            par->left=q;
        else
            par->right=q;
    }
    temp=p;
    p=q;
}
void R(struct node *p,struct node *par)
{
    struct node *q=p->left;
    p->left=q->right;
    q->right=p;
    if(p==root)
        root=q;
    else
    {
        if(par->left==p)
            par->left=q;
        else
            par->right=q;
    }
    temp=p;
    p=q;
}
void delete(struct node *p,int n)
{
    while(p!=cork)
    {
        if(p->marks==n)
            break;
    if(p->marks>n)
        p=p->left;
    else if(p->marks<n)
        p=p->right;
    }
    if(p==root&&p->left==cork&&p->right==cork)
    {
        root=cork;
        return;
    }
    if(p->left==cork&&p->right==cork&&p->color==red)
        {
            delete_node(p);
            return;
        }
        else if(p->color==black&&((p->left==cork&&p->right!=cork)||(p->right==cork&&p->left!=cork)))
        {
            if(p->left!=cork)
            recolor(p->left);
            else
            recolor(p->right);
            delete_node(p);
            return;
        }
    if(p->color==black&&p->left==cork&&p->right==cork)
    {
        struct node *par=p->parent,*sib;
        if(par->left==p)
            par->left=cork;
        else if(par->right==p)
            par->right=cork;
        while(p!=root)
        {
            if(par->left==cork)
            {
                sib=par->right;
                if(sib->color==black&&sib->left->color==black&&sib->right->color==black&&par->color==red)
                {
                    recolor(par);
                    recolor(sib);
                    return;
                }
                if(sib->color==black&&((sib->left)->color==red||(sib->right)->color==red))
                {
                    if((sib->left)->color==red)
                    {
                        R(sib,par);
                        recolor(sib);
                        recolor(sib->right);
                    }
                    if((sib->right)->color==red)
                    {
                        L(par,par->parent);
                        //printf("\n\n%d\n\n",par->marks);
                        (par)->color=black;
                        (sib->right)->color=black;
                        //puts("success");
                        return;
                    }
                }
                else if(sib->color==black&&sib->left->color==black&&sib->right->color==black&&par->color==black)
                {
                    sib->color=red;
                    p=par;
                    continue;
                }
                else if(sib->color==red)
                {
                    L(par,par->parent);
                    par->left->color=red;
                    par->color=black;
                    sib=par;
                    par=par->left;
                    continue;
                }
            }
            if(par->right==cork)
            {
                sib=par->left;
                if(sib->color==black&&sib->left->color==black&&sib->right->color==black&&par->color==red)
                {
                    par->right=cork;
                    p=cork;
                    recolor(par);
                    recolor(sib);
                    return;
                }
                if(sib->color==black&&(sib->left->color==red||sib->right->color==red))
                {
                    if(sib->right->color==red)
                    {
                        R(sib,par);
                        recolor(sib);
                        recolor(sib->left);
                    }
                    if(sib->left->color==red)
                    {
                        L(par,par->parent);
                        (par->right)->color=black;
                        (par->left)->color=black;
                        return;
                    }
                }
                else if(sib->color==black&&sib->left->color==black&&sib->right->color==black&&par->color==black)
                {
                    sib->color=red;
                    p=par;
                    continue;
                }
                else if(sib->color==red)
                {
                    L(par,par->parent);
                    par->right->color=red;
                    par->color=black;
                    sib=par;
                    par=par->right;
                    continue;
                }
            }
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
    if(p->left==cork&&p->right==cork)
    {
        case_b(par,p);
        return;
    }
    else if((p->left==cork&&p->right!=cork)||(p->right==cork&&p->left!=cork))
    {
        case_c(par,p);
        return;
    }
    else  if(p->left!=cork&&p->right!=cork)
    {
        struct node *j=p,*q=p->right;
        while(q!=cork)
        {
            if(q->left!=cork)
            {
                j=q;
                q=q->left;
            }
            else
                break;
        }
        p->marks=q->marks;
    if(q->left==cork&&q->right==cork)
    {
        case_b(j,q);
        return;
    }
    else if((q->left==cork&&q->right!=cork)||(q->right==cork&&q->left!=cork))
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
        root=cork;
        free(p);
        return;
    }
    else if(par->left==p)
        {
            par->left=cork;
            free(p);
            return;
        }
        else if(par->right==p)
        {
            par->right=cork;
            free(p);
            return;
        }
}
void case_c(struct node *par,struct node *p)
{
        if(p==root)
        {
            if(p->left!=cork)
            {
                root=p->left;
                free(p);
                return;
            }
            else if(p->right!=cork)
            {
                root=p->right;
                free(p);
                return;
            }
        }
            if(p->right!=cork)
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
        else if(p->left!=cork)
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
