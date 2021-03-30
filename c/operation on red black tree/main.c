#include <stdio.h>
#include <stdlib.h>

struct node *root=NULL;
struct node
{
    enum{black,red}color;
    struct node *right,*left;
    int marks;
    struct node *parent;
};
void insert(struct node *);
void delete(struct node *);
void recolor(struct node *);
struct node *LL(struct node *,struct node *,struct node *);
struct node *RR(struct node *,struct node *,struct node *);
void in(struct node *);
struct node *leaf;

int main()
{
    int c=10,n;
    struct node *temp,*p;
    leaf=(struct node *)malloc(sizeof(struct node));
    leaf->marks=-1;
    leaf->color=black;
    while(c!=3)
    {
    printf("Enter the choice\n1:Insert\n2:Delete\n3:Quit\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1 :   printf("\nEnter the marks of node\t");
                   temp=(struct node *)malloc(sizeof(struct node));
                   temp->left=leaf;
                   temp->right=leaf;
                   temp->parent=NULL;
                   temp->color=red;
                   scanf("%d",&temp->marks);
                   insert(temp);
                   in(root);
                   break;
        case 2 :   printf("\nEnter the marks of node\t");
                   scanf("%d",&n);
                   p=root;
                   while(p)
                   {
                       if(p->marks==n)
                        break;
                       if(p->marks>n)
                        p=p->left;
                       else if(p->marks<n)
                        p=p->right;
                   }
                   delete(p);
                   in(root);
                   break;
        case 3 :   printf("\nHave a nice day......");
    }
    printf("\n\n\n\n\n%d\n\n\n\n\n",root->marks);
    }
    return 0;
}
void recolor(struct node *p)
{
    if(p->color==red)
    {
        p->color=black;
        return;
    }
   else if(p->color==black)
    {
        p->color=red;
        return;
    }
}
struct node *LL(struct node *q,struct node *p,struct node *par)
{
    q=p->right;
    p->right=q->left;
    q->left=p;
    if(p==root)
    {
        root=q;
        p->parent=q;
        q->parent=NULL;
        return root;
    }
    else
    {
    if(par->left==p)
        par->left=q;
    else if(par->right==p)
        par->right=q;
        p->parent=q;
        q->parent=par;
        if(p->right!=leaf)
            p->right->parent=p;
        return root;
    }
}
struct node *RR(struct node *q,struct node *p,struct node *par)
{
    p->left=q->right;
    q->right=p;
    if(p==root)
    {
        root=q;
        p->parent=q;
        q->parent=NULL;
        return root;
    }
    else
    {
    if(par->right==p)
        par->right=q;
    else if(par->left==p)
        par->left=q;
        p->parent=q;
        q->parent=par;
        if(p->right!=leaf)
        p->right->parent=p;
        return root;
    }
}
void in(struct node *p)
{
    if(p==NULL)
        return;
    if(p->left!=leaf)
        in(p->left);
        printf("%d\t%d\n",p->marks,p->color);
    if(p->right!=leaf)
        in(p->right);
}
void insert(struct node *temp)
{
    struct node *t;
    if(root==NULL)
    {
        root=temp;
        recolor(temp);
        return;
    }
    struct node *p=root;
    while(p)
    {
        if(p->marks>temp->marks)
    {
        if(p->left!=leaf)
            p=p->left;
        else
            break;
    }
        else if(p->marks<temp->marks)
        {
            if(p->right!=leaf)
                p=p->right;
            else
                break;
        }
    }
    if(p->marks>temp->marks)
        p->left=temp;
    else if(p->marks<temp->marks)
        p->right=temp;
        temp->parent=p;
        struct node *grand,*uncle;
        while(p)
        {
            if(p->color==black)
                return;
                grand=p->parent;
            if(p->color==red&&temp->color==red)
    {
        if(p==root)
        {
            recolor(p);
            return;
        }
        if(grand->left==p)
        {
            uncle=grand->right;
        }
        else if(grand->right==p)
        {
            uncle=grand->left;
        }
        if(uncle->color==red)
        {
            recolor(grand);
            recolor(p);
            recolor(uncle);
        }
        else if(uncle->color==black)
        {
            if(grand->right==p)
            {
                if(p->right==temp)
                {
                    root=LL(p,grand,grand->parent);
                    recolor(grand);
                    recolor(p);
                    t=p;
                    p=grand;
                    grand=t;
                }
               else if(p->left==temp)
                {
                    root=RR(temp,p,grand);
                    t=temp;
                    temp=p;
                    p=t;
                    root=LL(p,grand,grand->parent);
                    recolor(grand);
                    recolor(p);
                    t=p;
                    p=grand;
                    grand=t;
                }
            }
            else if(grand->left==p)
            {
                if(p->left==temp)
                {
                    RR(p,grand,grand->parent);
                    recolor(grand);
                    recolor(p);
                    t=p;
                    p=grand;
                    grand=t;
                }
                else if(p->right==temp)
                {
                    root=LL(temp,p,grand);
                    t=temp;
                    temp=p;
                    p=t;
                    RR(p,grand,grand->parent);
                    recolor(grand);
                    recolor(p);
                    t=p;
                    p=grand;
                    grand=t;
                }
            }
        }
    }
        if(grand==root&&grand->color==red)
        {
            recolor(grand);
            return;
        }
        p=grand->parent;
        temp=grand;
        }
        return;
}
void delete(struct node *temp)
{
     if(temp==root&&(temp->left==leaf||temp->right==leaf))
     {
         if(root->left==leaf&&root->right==leaf)
         {
         temp=NULL;
         root=NULL;
        return;
         }
         if(root->left!=leaf)
         {
             root=root->left;
             return;
         }
         else if(root->right!=leaf)
         {
             root=root->right;
             return;
         }
     }
     if(temp->left!=leaf&&temp->right!=leaf)
     {
         struct node *t=temp;
         temp=temp->right;
         while(temp->left!=leaf)
         {
             temp=temp->left;
         }
         t->marks=temp->marks;
     }
    while(temp)
    {
         if(temp==root)
         {
        return;
         }
    struct node *par=temp->parent,*sib;
    if(par->right==temp)
        sib=par->left;
    else if(par->left==temp)
        sib=par->right;
    if(temp->color==red)
    {
        if(par->right==temp)
            par->right=leaf;
        else if(par->left==temp)
            par->left=leaf;
        return;
    }
    else if((temp->color==black)&&(((temp->right!=leaf)&&(temp->left==leaf))||((temp->left!=leaf)&&(temp->right==leaf))))
    {
        if(temp->right!=leaf)
        {
            if(par->right==temp)
            {
                par->right=temp->right;
                temp->right->color=black;
                temp->right->parent=par;
                free(temp);
                return;
            }
           else if(par->left==temp)
            {
                par->left=temp->right;
                temp->right->color=black;
                temp->right->parent=par;
                free(temp);
                return;
            }
        }
        else if(temp->left!=leaf)
        {
            if(par->right==temp)
            {
                par->right=temp->left;
                temp->left->color=black;
                temp->left->parent=par;
                return;
            }
           else if(par->left==temp)
            {
                par->left=temp->left;
                temp->left->color=black;
                temp->left->parent=par;
                return;
            }
        }
    }
   else if(temp->color==black&&temp->left==leaf&&temp->right==leaf)
    {
        if(par->right==temp)
        {
            temp=leaf;
            par->right=temp;
        }
        else if(par->left==temp)
        {
            temp=leaf;
            par->left=temp;
        }
        if(sib->color==black&&sib->left->color==black&&sib->right->color==black&&par->color==red)
        {
            recolor(par);
            recolor(sib);
            return;
        }
        else if(sib->color==black&&(sib->left->color==red||sib->right->color==red))
        {
            if(par->right==sib&&sib->right->color!=red)
            {
                RR(sib->left,sib,par);
                sib=sib->parent;
                recolor(sib);
                recolor(sib->right);
            }
            if(par->right==sib&&sib->right->color==red)
            {
                LL(sib,par,par->parent);
                par->color=black;
                sib->right->color=black;
                return;
            }
             if(par->left==sib&&sib->left->color!=red)
            {
                LL(sib->right,sib,par);
                sib=sib->parent;
                recolor(sib);
                recolor(sib->left);
            }
            if(par->left==sib&&sib->left->color==red)
            {
                RR(sib,par,par->parent);
                par->color=red;
                sib->left->color=black;
                return;
            }
        }
    }
    else if(sib->color==red)
    {
        if(par->left==temp)
        {
            LL(sib,par,par->parent);
            recolor(sib);
            recolor(par);
            sib=par->right;
            continue;
        }
        else if(par->right==temp)
        {
            RR(sib,par,par->parent);
            recolor(sib);
            recolor(par);
            sib=par->left;
            continue;
        }
    }
    if(par->color==black&&sib->color==black&&sib->right->color==black&&sib->left->color==black)
    {
        puts("success");
        recolor(sib);
        temp=par;
        continue;
    }
    }
}
