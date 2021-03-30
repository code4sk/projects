#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#define MAX1 50
struct node
{
    struct node *left;
    int marks;
    struct node *right;
};
struct node * pop();
int i=-1,first=0,last=-1;
struct node *stack[MAX],*queue[MAX1];
struct node *create();
void in(struct node *);
void sin(struct node *);
void level(struct node *);
int height(struct node *);
int main()
{
    struct node *root;
    root=create();
    printf("%d",height(root));
    return 0;
}
struct node *create()
{
    struct node *root=NULL,*temp,*p,*parent;
    for(int i=0;i<5;i++)
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
           {
               p=p->left;
           }
            else
           {
               p=p->right;
           }
           }
           if(parent->marks>temp->marks)
           {
               parent->left=temp;
           }
            else
           {
               parent->right=temp;
           }
        }
    }
    return root;
}
void in(struct node *p)
{
    if(p->left)
    {
        in(p->left);
    }
    printf("%d\t",p->marks);
    if(p->right)
    {
        in(p->right);
    }
    return;
}
void sin(struct node *p)
{
    int i=-1;
          i++;
            stack[i]=p;
    while(1)
    {
        while(p->left)
        {
            p=p->left;
            i++;
            stack[i]=p;
        }
        if(p->left==NULL)
        {
            if(i!=-1)
            {
        p=stack[i];
        stack[i]=NULL;
        i--;
            }
            else
            break;
        printf("%d\t",p->marks);
        if(p->right==NULL)
        {
            if(i!=-1)
            {
        p=stack[i];
        stack[i]=NULL;
        i--;
            }
            else
            break;
        printf("%d\t",p->marks);
        }
        p=p->right;
        i++;
        stack[i]=p;
        continue;
        }
    }
}
void level(struct node *p)
{
    last++;
    queue[last]=p;
    while(1)
    {
            p=queue[first];
            queue[first]=NULL;
            first++;
            printf("%d\t",p->marks);
        if(p->left!=NULL)
        {
        last++;
        queue[last]=p->left;
        }
        if(p->right!=NULL)
        {
        last++;
        queue[last]=p->right;
        }
        if(first>last)
            return;
    }
}
void push(struct node *p)
{
    i++;
    stack[i]=p;
}
struct node * pop()
{
    struct node *p;
        p=stack[i];
        stack[i]=NULL;
        i--;
}
int height(struct node *p)
{
    int left,right;
     if(p==NULL)
         return 0;
         left=height(p->left);
         right=height(p->right);
         if(right<left)
            return 1+left;
         else
            return 1+right;
}
