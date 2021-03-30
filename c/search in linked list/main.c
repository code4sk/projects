#include <stdio.h>
#include <stdlib.h>

struct bio
{
    char name[21];
    int cnt;
}inf;
struct node
{
    struct bio inf;
    struct node *link;
};
struct node *d;
struct node *create(struct node *start,int n);
struct node *search(struct node *start,int n,int a);
int main()
{
    int n,a,c;
    struct node *temp;
    struct node *start;
    start=NULL;
    struct node *p;
    printf("ENTER NO. OF CRICKETER:\t ");
    scanf("%d",&n);
    fflush(stdin);
    start=create(start,n);
    puts("\nENTER YOUR CHOICE\n");
    puts("1 : SEARCH\n2 : QUIT\n");
    scanf("%d",&c);
    fflush(stdin);
    if(c==1)
    {
    printf("ENTER THE NUMBER OF CENTURIES OF CRICKTER :\t ");
    scanf("%d",&a);
    p=search(start,n,a);
    if(p!=NULL)
    {
    printf("NAME OF CRICKTER IS :\t %s",p->inf.name);
    }
    else
    {
    puts("NO MATCH FOUND");
    }
    }
    else
    {
        puts("HAVE A NICE DAY....");
    }
    return 0;
}
struct node *create(struct node *start,int n)
{
    start=NULL;
    struct node *p;
    struct node *temp;
 for(int i=0;i<n;i++)
 {
     temp=(struct node*)malloc(sizeof(struct bio));
     printf("NAME OF CRICKTER %d \t ",i+1);
     gets(temp->inf.name);
     fflush(stdin);
     printf("NO. OF CENTURIES BY CRICKETER %d ARE: \t ",i+1);
     scanf("%d",&temp->inf.cnt);
     fflush(stdin);
     temp->link=NULL;
     if(start==NULL)
     {
         start=temp;
     }
     else
     {
         p=start;
         while((p->link)!=NULL)
         {
            p=p->link;
         }
         (p->link)=(temp);

     }
 }
 return start;
}
struct node *search(struct node *start,int n,int a)
{
    int flag=0;
    struct node *p;
    p=start;
        while(p!=NULL)
        {

        if(a==(p->inf.cnt))
        {
            flag=1;
            break;
        }
        p=p->link;
        }
    switch(flag)
    {
        case 0: return NULL;
        break;
        case 1: return p;
    }

}
