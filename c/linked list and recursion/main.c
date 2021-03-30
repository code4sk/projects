#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char chr;
    struct node *link;
};
int n=1;
struct node *create();
void len(struct node *start);
int search(struct node *start,char a);
int main()
{
    char c;
    struct node *start;
    start=create();
    len(start);
    printf("%d",n);
    printf("\nenter the character you want to search\n");
    scanf(" %c",&c);
    printf("%d",search(start,c));
    return 0;
}
struct node *create()
{
    char strr[21],*str;
    str=strr;
    printf("Enter your name\n");
    scanf("%s",strr);
    struct node *start=NULL,*temp,*p;
    for(int i=0;i<strlen(strr);i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp->link=NULL;
        temp->chr=*str;
        str++;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            p=start;
            while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
        }
    }
    return start;
}
void len(struct node *start)
{
    if(start->link==NULL)
    {
        return;
    }
    else
    {
        n++;
        len(start->link);
    }
    return;
}
int search(struct node *start,char a)
{
    int k=0;
    if(a==start->chr)
    {
        return 1;
    }
    else
    {
        if(start->link!=NULL)
        k=search(start->link,a);
    }
    return k;
}
