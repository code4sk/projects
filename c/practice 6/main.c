#include <stdio.h>
#include <stdlib.h>

struct node
{
    int marks;
    struct node *left;
    struct node *right;
};
struct node *stack[10],*queue[10];
int top=-1,front=0,rear=-1;
void lt();
struct node *pop();
void case_b(struct node *par,struct node *p);
void push(struct node *);
void create();
struct node *root;
void in(struct node *p);
void push1(struct node *);
struct node *pop1();
int height(struct node *);
void delete();
void case_a(struct node *par,struct node *p);
int main()
{
    create();
    in(root);
    puts("");
    printf("Height of tree is\t%d",height(root));
    while(1)
    {
    puts("");
    delete();
    in(root);
    }
    return 0;
}
void create()
{
    struct node *temp,*p,*par;
    int n;
    printf("Enter the number of node\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->left=NULL;
        temp->right=NULL;
        printf("Enter the marks of %d\t",i+1);
        scanf("%d",&temp->marks);
        if(!root)
            root=temp;
        else
        {
            p=root;
            while(p)
            {
                par=p;
                if(p->marks>temp->marks)
                    p=p->left;
                    else
                    p=p->right;
            }
            if(par->marks>temp->marks)
                    par->left=temp;
            else
                    par->right=temp;
        }
    }
}
void in(struct node *p)
{
    if(p->left)
        in(p->left);
    printf("%d\t",p->marks);
    if(p->right)
        in(p->right);
}
void inorder()
{
    struct node *p=root;
    push(p);
    while(top!=-1)
    {
        while(p->left)
        {
            p=p->left;
            push(p);
        }
        p=pop();
        printf("%d\t",p->marks);
        if(p->right)
        {
        p=p->right;
        push(p);
        }
    }
}
struct node *pop()
{
    return stack[top--];
}
void push(struct node *p)
{
    stack[++top]=p;
}
void lt()
{
    struct node *p=root;
    push1(p);
    while(front<=rear)
    {
        p=pop1();
        printf("%d\t",p->marks);
        if(p->left)
            push1(p->left);
        if(p->right)
            push1(p->right);
    }
}
void push1(struct node *p)
{
    queue[++rear]=p;
}
struct node *pop1()
{
    return queue[front++];
}
int height(struct node *p)
{
    int left,right;
    if(p==NULL)
        return 0;
    if(!p->left&&!p->right)
        return 1;
    left=height(p->left)+1;
    right=height(p->right)+1;
    if(left>right)
    return left;
    else
    return right;
}
void delete()
{
    struct node *par=root,*t,*p=root;
    int n;
    printf("Enter the marks of node to be deleted\n");
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
    if((!p->left)&&(!p->right))
        case_a(p,par);
        else if(((!p->left)&&(p->right))||((!p->right)&&(p->left)))
            case_b(p,par);
            else
            {
                t=p;
                while(t->left)
                {
                    par=t;
                    t=t->left;
                }
                p->marks=t->marks;
        if((!t->left)&&(!t->right))
            case_a(t,par);
        else if(((!t->left&&t->right)||(!t->right&&t->left)))
            case_b(t,par);
            }
}
void case_a(struct node *p,struct node *par)
{
    if(p==root)
    {
        root=NULL;
        free(p);
        free(par);
        return;
    }
    else
    {
        if(par->left==p)
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
}
void case_b(struct node *p,struct node *par)
{
    if(p==root)
    {
        if(p->left)
        {
            root=p->left;
            free(p);
            free(par);
            return;
        }
        else if(p->right)
        {
            root=p->right;
            free(p);
            free(par);
            return;
        }
    }
    else
    {
        if(p->left)
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
    }
}
