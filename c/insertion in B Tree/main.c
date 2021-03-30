#include <stdio.h>
#include <stdlib.h>

#define MAX 5
struct node
{
    int count;
    int marks[MAX];
    struct node *child[MAX];
};
int v=-1;
struct node *insert(struct node *,int);
int rec_ins(struct node *,int ,int *,struct node **);
int search_node(struct node *,int,int *);
void shift(struct node *,int,int,struct node *);
void split(struct node *,int ,int,struct node *,int *,struct node **);
void show(struct node *p);
int search(struct node *p,int,int *);
struct node *delete(struct node *p,int key);
void rec_del(struct node *p,int key);
void del_shift(struct node *p,int n);
int suc(struct node *,int n);
void restore(struct node *p,int n);
void borrow_left(struct node *p,int n);
void borrow_right(struct node *p,int n);
void combine(struct node *p,int n);
int main()
{
    struct node *root=NULL;
    int n,c,k,m;
    while(1)
    {
        printf("\nEnter your choice:\n1:Insert\n2:Delete\n3:Search\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1 :         v=-1;
                             printf("Enter the marks :\t");
                             scanf("%d",&n);
                             root=insert(root,n);
                             show(root);
                             break;
            case 2 :         printf("Enter the marks :\t");
                             scanf("%d",&n);
                             root=delete(root,n);
                             show(root);
                             break;
            case 3 :         printf("Enter the marks :\t");
                             scanf("%d",&n);
                             k=search(root,n,&m);
                             switch(k)
                             {
                                 case 0 : puts("No");
                                 break;
                                 case 1 : puts("Yes");
                                 break;
                             }
        }
    puts("");
    }
    return 0;
}
struct node *insert(struct node *p,int ikey)
{
    int taller;
    int k;
    struct node *kright;
    taller=rec_ins(p,ikey,&k,&kright);
    if(taller)
    {
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp->count=1;
        temp->child[0]=p;
        temp->child[1]=kright;
        temp->marks[1]=k;
        p=temp;
    }
    return p;
}
int rec_ins(struct node *p,int ikey,int *pk,struct node **pkright)
{
    int n,flag;
    if(p==NULL)
    {
        *pk=ikey;
        *pkright=NULL;
        return 1;
    }
    if(search_node(p,ikey,&n))
    {
        puts("Duplicates marks are found");
        return 0;
    }
    flag=rec_ins(p->child[n],ikey,pk,pkright);
    if(flag)
    {
        if(p->count<MAX-1)
        {
            shift(p,n,*pk,*pkright);
            return 0;
        }
        else
        {
            split(p,n,*pk,*pkright,pk,pkright);
            return 1;
        }
    }
    return 0;
}
int search_node(struct node *p,int ikey,int *pn)
{
    if(p->marks[1]>ikey)
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
void shift(struct node *p,int n,int k,struct node *kright)
{
    int i;
    for(i=p->count;i>n;i--)
    {
        p->marks[i+1]=p->marks[i];
        p->child[i+1]=p->child[i];
    }
    p->marks[i+1]=k;
    p->child[i+1]=kright;
    p->count++;
}
void split(struct node *p,int n,int k,struct node *kright,int *upkey,struct node **newnode)
{
    int lastkey;
    int d=3,i,j;
    struct node *lastchild;
    if(n==MAX-1)
    {
        lastkey=k;
        lastchild=kright;
    }
    else
    {
         lastkey=p->marks[MAX];
         lastchild=p->child[MAX];
         for(i=p->count;i>n;i--)
         {
             p->marks[i+1]=p->marks[i];
             p->child[i+1]=p->child[i];
         }
         p->marks[i+1]=k;
         p->child[i+1]=kright;
    }
    *newnode=(struct node *)malloc(sizeof(struct node));
    *upkey=p->marks[d];
    for(j=d+1,i=1;j<=MAX-1;j++,i++)
    {
        (*newnode)->marks[i]=p->marks[j];
        (*newnode)->child[i]=p->child[j];
    }
    (*newnode)->child[0]=p->child[d];
     p->count=d-1;
    (*newnode)->count=MAX-d;
        (*newnode)->marks[MAX-d]=lastkey;
        (*newnode)->child[MAX-d]=lastchild;
}
void show(struct node *p)
{
    v++;
    if(p==NULL)
        return;
    for(int i=1;i<=p->count;i++)
    {
        printf("%d\t",p->marks[i]);
    }
   //     show(p->child[1]);
}
int search(struct node *p,int key,int *pn)
{
    int found;
    if(p==NULL)
        return 0;
        found=search_node(p,key,pn);
        if(found)
         return found;
    else
        return search(p->child[*pn],key,pn);
}
struct node *delete(struct node *p,int key)
{
    struct node *temp;
    rec_del(p,key);
    if(p!=NULL&&p->count==0)
    {
        temp=p;
        p=p->child[0];
        free(temp);
    }
    return p;
}
void rec_del(struct node *p,int key)
{
    int n,flag,succ;
    if(p==NULL)
        printf("\nValue %d is not found",key);
    else
    {
        flag=search_node(p,key,&n);
        if(flag)
        {
            if(p->child[n]==NULL)
                del_shift(p,n);
            else
            {
                succ=suc(p,n);
                rec_del(p->child[n],succ);
            }
        }
        else
            rec_del(p->child[n],key);
        if(p->child[n]!=NULL)
        {
            if(p->child[n]->count<2)
                restore(p,n);
        }
    }
}
void del_shift(struct node *p,int n)
{
    for(int i=n+1;i<=p->count;i++)
    {
        p->marks[i-1]=p->marks[i];
        p->child[i-1]=p->child[i];
    }
    p->count--;
}
int suc(struct node *p,int n)
{
        int temp;
    struct node *q=p->child[n];
    while(q->child[0]!=NULL)
        q=q->child[0];
    p->marks[n]=q->marks[n];
    return q->marks[n];
}
void restore(struct node *p,int n)
{
    if(n!=0&&p->child[n-1]->count>2)
        borrow_left(p,n);
    else if(n!=0&&p->child[n+1]->count>2)
        borrow_right(p,n);
    else
    {
        if(n==0)
            combine(p,n+1);
        else
            combine(p,n);
    }
}
void borrow_left(struct node *p,int n)
{
    struct node *u,*ul;
    u=p->child[n];
    ul=p->child[n-1];
    u->marks[2]=u->marks[1];
    u->child[2]=u->child[1];
    u->marks[1]=p->marks[n];
    u->child[1]=u->child[0];
    u->child[0]=ul->child[ul->count];
    p->marks[n]=ul->marks[ul->count];
    ul->count--;
    u->count++;
}
void borrow_right(struct node *p,int n)
{
    struct node *u,*ur;
    u=p->child[n];
    ur=p->child[n+1];
    u->marks[2]=p->marks[n];
    u->child[2]=ur->child[0];
    p->marks[n]=ur->marks[1];
    ur->child[0]=ur->child[1];
    for(int i=1;i>ur->count;i++)
    {
        ur->marks[i]=ur->marks[i+1];
        ur->child[i]=ur->child[i+1];
    }
    ur->count--;
    u->count++;
}
void combine(struct node *p,int n)
{
    struct node *t=p->child[n],*q=p->child[n-1];
    q->marks[3]=p->marks[n];
    for(int i=n;i<p->count;i++)
    {
        p->marks[i]=p->marks[i+1];
        p->child[i]=p->child[i+1];
    }
    p->count--;
    q->count++;
    q->marks[4]=t->marks[1];
    q->child[3]=t->child[0];
    q->child[4]=t->child[1];
    q->count++;
}
