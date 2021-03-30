#include <stdio.h>
#include <stdlib.h>

#define MAX 5
struct node
{
    int marks[MAX];
    int count;
    struct node *child[MAX];
};
int search_node(struct node *p,int ikey,int *pn);
struct node *insert(struct node *p,int ikey);
int rec_ins(struct node *p,int ikey,int *,struct node **);
void shift(struct node *p,int n,int k,struct node *krchild);
void split(struct node *,int n,int k,struct node *krchild,int *upkey,struct node **newnode);
int main()
{

    return 0;
}
int search_node(struct node *p,int ikey,int *pn)
{
    if(ikey<p->marks[1])
    {
        *pn=0;
        return 0;
    }
    *pn=p->count;
    while(p->marks[*pn]>ikey&&*pn>1)
        (*pn)--;
    if(p->marks[*pn]==ikey)
        return 1;
    else return 0;
}
int rec_ins(struct node *p,int ikey,int *k,struct node **krchild)
{
    int n,flag;
    if(p==NULL)
    {
        *k=ikey;
        *krchild=NULL;
        return 1;
    }
    if(search_node(p,ikey,&n))
    {
        printf("\nDuplicate keys\n");
        return 0;
    }
    flag=rec_ins(p->child[n],ikey,k,krchild);
    if(flag)
    {
        if(p->count<MAX)
        {
            shift(p,n,*k,*krchild);
            return 0;
        }
        else
        {
            split(p,n,*k,*krchild,k,krchild);
            return 1;
        }
    }
    return 0;
}
void shift(struct node *p,int n,int k,struct node *krchild)
{
    int i=p->count;
    for(i;i>n;i--)
    {
        p->marks[i+1]=p->marks[i];
        p->child[i+1]=p->child[i];
    }
    p->marks[i]=k;
    p->child[i]=krchild;
    p->count++;
}
struct node *insert(struct node *p,int ikey)
{
    int k,taller;
    struct node *krchild,*temp;
    taller=rec_ins(p,ikey,&k,&krchild);
    if(taller)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->count=1;
        temp->marks[1]=k;
        temp->child[0]=p;
        temp->child[1]=krchild;
        p=temp;
    }
    return p;
}
void split(struct node *p,int n,int k,struct node *krchild,int *upkey,struct node **newnode)
{
    int i,j;
    int lastkey;
    struct node *lastchild;
    int d=3;
    if(n==MAX)
    {
        lastkey=k;
        lastchild=krchild;
    }
    else
    {
        lastkey=p->marks[MAX];
        lastchild=p->child[MAX];
        for(i=p->count-1;i>n;i--)
        {
            p->key[i+1]=p->key[i];
            p->child[i+1]=p->child[i];
        }
        p->key[i+1]=k;
        p->child[i+1]=krchild;
    }
    newnode=(struct node *)malloc(sizeof(struct node));
    upkey=p->key[d];
    for(i=1,j=d+1;j<=MAX;i++,j++)
    {
        (*newnode)->key[i]=p->key[j];
        (*newnode)->child[i]=p->child[j];
    }
    (*newnode)->child[0]=p->child[d];
    p->count=d-1;
    (*newnode)->count=MAX-d;
    (*newnode)->key[MAX-d]=lastkey;
    (*newnode)->child[MAX-d]=lastchild;
}
