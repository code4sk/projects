#include <stdio.h>
#include <stdlib.h>

#define MAX 5
struct node
{
    int marks[MAX];
    struct node *child[MAX];
    int count;
};
struct node *insert(struct node *,int);
int rec_ins(struct node *,int,int *,struct node **);
int search_node(struct node *,int,int *);
void shift(struct node *p,int ikey,int *k,struct node **kright);
int main()
{

    return 0;
}
struct node *insert(struct node *p,int ikey)
{
    int taller;
    int k;
    struct node *kright;
    taller=
}
int rec_ins(struct node *p,int ikey,int *k,struct node **kright)
{
    int found,n;
    if(p==NULL)
    {
        *k=ikey;
        *kright=NULL;
        return 1;
    }
    if(search_node(p,ikey,&n))
    {
        puts("Duplicate marks are found");
        return 0;
    }
    found=rec_ins(p->child[n],ikey,k,*kright);
    if(found)
    {
        if(p->count<MAX)
        {
            shift(p,n,k,*kright)
        }
    }
}
int search_node(struct node *p,int ikey,int *pn)
{
    if(p->marks[1]<ikey)
    {
        *pn=0;
        return 0;
    }
    pn=p->count;
    while(p->marks[*pn]>ikey&&*pn>1)
        *pn--;
    if(p->marks[*pn]==ikey)
        return 1;
    else return 0;
}
void shift(struct node *p,int n,int *k,struct node *kright)
{
    int i=p->count;
    for(i;i>n;i--)
    {
        p->marks[i+1]=p->marks[i];
        p->marks[i]=k;
        p->child[i]=*kright;
    }
    p->count++;
}
