#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    char chr;
    struct node *right;
};
struct node *create();
 int main()
{
    struct node *root;
    root=create();
    return 0;
}
struct node *create()
{
   struct node *root=NULL,*temp,*p,*parent;
   for(int i=0;i<11;i++)
   {
       temp=(struct node *)malloc(sizeof(struct node));
       temp->left==NULL;
       temp->right==NULL;

   }
}
