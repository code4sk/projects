#include <stdio.h>
#include <stdlib.h>

struct node
{
    int marks;
    struct node *link;
};
struct node *root=NULL;
void create();
void radix_sort();
int main()
{
    int arr[10]={4,7,1,5,2,8,3,10,9,6}
    create();
    return 0;
}
void create()
{
    struct node *temp,*p;
    for(int i=0;i<10;i++)
    {
    temp=(struct node *)malloc(sizeof(struct node));
    temp->link=NULL;
    temp->marks=arr[i];
    if(root==NULL)
        root=temp;
    else
    {
        p=root;
        while(p->link)
            p=p->link;
        p->link=temp;
    }
    }
}
void radix_sort()
{
    int i,k,dig,least_sig,most_sig;
    struct node *p,*rear[10],*front[10];
}
