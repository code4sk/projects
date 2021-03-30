#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int marks;
    struct node *right;
};
int arr[10];
struct node*create(int);
struct node *search(struct node *root,int m);
struct node *rsearch(struct node *root,int m);
struct node *rmin(struct node *root);
struct node *rmax(struct node *root);
void insert(struct node *p,struct node *);
struct node *delete(struct node *p,int l);
void in(struct node *root);
struct node *case_a(struct node *,struct node *,struct node *);
struct node *case_b(struct node *,struct node *,struct node *);
struct node *case_c(struct node *,struct node *,struct node *,int );
int main()
{
    struct node *root,*temp,*k;
    int n,m,l,c=1;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    root=create(n);
    in(root);
    while(c!=6)
    {
        in(root);
        printf("\nEnter your choice\n1:Search\n2:Minimum value\n3:Maximum value\n4:Insert\n5:Delete\n6:Quit\n");
    scanf("%d",&c);
        switch(c)
        {
        case 1 :     printf("Enter the marks you want to search in tree\n");
                     scanf("%d",&m);
                     k=rsearch(root,m);
                     if(k!=NULL)
                     printf("%d\n",k->marks);
                     else
                        printf("Not found\n");
                     break;
        case 2 :     printf("Min value is\t%d\n",(rmin(root))->marks);
                     break;
        case 3 :     printf("Max value is\t%d\n",(rmax(root))->marks);
                     break;
        case 4 :     printf("Enter the marks you want to insert\n");
                     temp=(struct node *)malloc(sizeof(struct node));
                     temp->left=NULL;
                     temp->right=NULL;
                     scanf("%d",&temp->marks);
                     insert(root,temp);
                     break;
        case 5 :     printf("Enter the marks you want to delete\n");
                     scanf("%d",&l);
                     root=delete(root,l);
        }
    }
    return 0;
}
struct node *create(int n)
{
    struct node *root=NULL,*p,*parent,*temp;
    for(int i=0;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->left=NULL;
        temp->right=NULL;
        printf("Enter the marks of student %d\t",i+1);
        scanf("%d",&temp->marks);
        if(root==NULL)
            root=temp;
        else
        {
            p=root;
            while(p)
            {
                parent=p;
                if(p->marks>temp->marks)
                    p=p->left;
                else
                    p=p->right;
            }
            if(parent->marks>temp->marks)
                    parent->left=temp;
                else
                    parent->right=temp;
        }
    }
    return root;
}
struct node *search(struct node *root,int m)
{
    struct node *p;
    p=root;
    while(p)
    {
        if(p->marks>m)
         p=p->left;
        else
        {
        if(p->marks<m)
         p=p->right;
        else
        return p;
        }
    }
    return NULL;
}
struct node *rsearch(struct node *root,int m)
{
    if(root==NULL)
    return root;
    if(root->marks>m)
        return rsearch(root->left,m);
   else if(root->marks<m)
        return rsearch(root->right,m);
        else
            return root;
}
struct node *rmin(struct node *p)
{
    if(p->left==NULL)
        return p;
    return rmin(p->left);
}
struct node *rmax(struct node *p)
{
    if(p->right==NULL)
        return p;
    return rmax(p->right);
}
void insert(struct node *p,struct node *temp)
{
    if(p==NULL)
    {
        p=temp;
    }
    else if(p->marks==temp->marks)
        printf("Already exist\n");
    else if(p->marks>temp->marks)
        if(p->left!=NULL)
        insert(p->left,temp);
        else
            p->left=temp;
    else if(p->marks<temp->marks)
        if(p->right!=NULL)
        insert(p->right,temp);
        else
            p->right=temp;
}
struct node *delete(struct node *root,int l)
{
        struct node *p,*r;
        r=p=root;
    while(p!=NULL)
    {
        if(p->marks==l)
            break;
        r=p;
        if(p->marks>l)
            p=p->left;
        else if(p->marks<l)
            p=p->right;
    }
    if(p->left==NULL&&p->right==NULL)
    {
        root=case_a(root,p,r);
        return root;
    }
    else if(p->left==NULL||p->right==NULL)
    {
        root=case_b(root,p,r);
        return root;
    }
    else if(p->left!=NULL&&p->right!=NULL)
    {
            root=case_c(root,p,r,l);
            return root;
    }
}
void in(struct node *root)
{
    static int i=0;
    if(root->left!=NULL)
        in(root->left);
    arr[i]=root->marks;
    i++;
    printf("%d\t",root->marks);
    if(root->right!=NULL)
        in(root->right);
}
struct node *case_a(struct node *root,struct node *p,struct node *r)
{
    if(p==root)
        free(root);
    else if(r->left==p)
    {
        r->left=NULL;
        free(p);
    }
    else if(r->right==p)
    {
        r->right=NULL;
        free(p);
    }
    return root;
}
struct node *case_b(struct node *root,struct node *p,struct node *r)
{
    if(p==root)
    {
        if(root->left!=NULL)
        root=root->left;
        else if(root->left==NULL)
        root=root->right;
    }
    if(p->left==NULL)
    {
        if(r->left==p)
        {
        r->left=p->right;
        free(p);
        }
        if(r->right==p)
        {
        r->right=p->right;
        free(p);
        }
    }
    if(p->right==NULL)
    {
        if(r->left==p)
        {
        r->left=p->left;
        free(p);
        }
        if(r->right==p)
        {
        r->right=p->left;
        free(p);
        }
    }
    return root;
}
struct node *case_c(struct node *root,struct node *p,struct node *r,int l)
{
    int j;
     for(j=0;arr[j]!=l;j++)
        {}
        struct node *q,*k;
        q=root;
        while(q!=NULL)
    {
        if(q->marks==arr[j+1])
            break;
            k=q;
        if(q->marks>arr[j+1])
            q=q->left;
        else if(q->marks<arr[j+1])
            q=q->right;
    }
    p->marks=q->marks;
    if(q->left==NULL&&q->right==NULL)
        root=case_a(root,q,k);
    else if(q->left==NULL||q->right==NULL)
        root=case_b(root,q,k);
   return root;
}
