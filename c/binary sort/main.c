#include <stdio.h>
#include <stdlib.h>

struct node *root=NULL;
void create();
int arr[10]={8,3,10,1,4,2,5,7,6,9},temp[10],k=0;
struct node
{
    int marks;
    struct node *left;
    struct node *right;
};
void inorder();
int main()
{
    create();
    inorder(root);
    return 0;
}
void create()
{
    struct node *temp,*p,*parent;
    for(int i=0;i<10;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->left=NULL;
        temp->right=NULL;
        temp->marks=arr[i];
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
}
void inorder(struct node *p)
{
    if(p->left)
        inorder(p->left);
    temp[k++]=p->marks;
    printf("%d\t",temp[k-1]);
    if(p->right)
        inorder(p->right);
}
