#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define MAX1 25
struct node
{
    struct node *left;
    int marks;
    struct node *right;
};
int top=-1;
struct node *stack[MAX];
struct node *queue[MAX1];
int first=-1,last=-1;
struct node*create();
void display(struct node *);
void pre(struct node *);
void post(struct node *);
void in(struct node *);
struct node *pop();
void push(struct node *);
void lt(struct node *);
struct node *pop1();
void push1(struct node *);
int main()
{
    struct node *root;
    root=create();
    display(root);
    puts("");
    pre(root);
    puts("");
    post(root);
    puts("");
    in(root);
    puts("");
    lt(root);
    return 0;
}
struct node *create()
{
    struct node *temp,*root=NULL,*parent,*p;
    int n;
    printf("Enter the number of nodes in tree\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->right=NULL;
        temp->left=NULL;
        printf("Enter marks of student %d\t",i+1);
        scanf("%d",&temp->marks);
        if(root==NULL)
            root=temp;
        else
        {
                p=root;
                while(p)
                {
                    parent=p;
                if(temp->marks>p->marks)
                {
                    p=p->right;
                }
                else
                {
                    p=p->left;
                }
                }
                if(temp->marks>parent->marks)
                {
                   parent->right=temp;
                }
                else
                {
                    parent->left=temp;
                }
        }
    }
    return root;
}
void display(struct node *root)
{
    struct node *p=root;
    if(p->left)
        display(p->left);
    printf("%d\t",p->marks);
    if(p->right)
        display(p->right);
}
void pre(struct node *p)
{
    printf("%d\t",p->marks);
    if(p->left)
        pre(p->left);
    if(p->right)
        pre(p->right);
}
void post(struct node *p)
{
    if(p->left)
        post(p->left);
    if(p->right)
        post(p->right);
        printf("%d\t",p->marks);
}
void in(struct node *p)
{
    while(1)
    {
    while(p->left)
    {
        push(p);
        p=p->left;
    }
    while(p->right==NULL)
    {
        printf("%d\t",p->marks);
        if(top==-1)
        return;
        p=pop();
    }
    printf("%d\t",p->marks);
    p=p->right;
    }
}
struct node *pop()
{
    struct node *t;
    t=stack[top];
 stack[top]=NULL;
 top=top-1;
 return t;
}
void push(struct node *p)
{
    top++;
    stack[top]=p;
}
void lt(struct node *p)
{
    push1(p);
    while(1)
    {
    p=pop1();
    printf("%d\t",p->marks);
    if(p->left!=NULL)
    push1(p->left);
    if(p->right!=NULL)
    push1(p->right);
    if(first>last)
        return;
    }
}
struct node *pop1()
{
    struct node *t;
    t=queue[first];
    first++;
    return t;
}
void push1(struct node *p)
{
    if(first==-1)
        first=0;
    last++;
    queue[last]=p;
}
