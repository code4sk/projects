#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    struct node *left;
    char chr;
    struct node *right;
};
int k=-1;
struct node *create(char pre[],char in[],int);
void rin(struct node *);
int main()
{
    struct node *root;
    char pre[31],in[31];
    printf("Enter preorder traversal\t");
    scanf("%s",pre);
    printf("Enter inorder traversal\t");
    scanf("%s",in);
    root=create(pre,in,strlen(pre));
    rin(root);
    return 0;
}
struct node *create(char pre[],char in[],int n)
{
    k++;
    struct node *temp,*root,*p,*parent;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->left=NULL;
        temp->right=NULL;
        temp->chr=pre[k];
    if(n==0)
        return NULL;
    if(n==1)
        return temp;
    int i=0,j;
        while(pre[k]!=in[i])
        i++;
        temp->left=create(pre,in,i);
        temp->right=create(pre,in,n-1-i);
        return temp;
}
void rin(struct node *p)
{
    if(p->left)
        rin(p->left);
    printf("%c\t",p->chr);
    if(p->right)
        rin(p->right);
}
