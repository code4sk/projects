
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};


int main()
{
    struct node *start=NULL;
  struct node *temp=NULL;
   struct node *p=NULL;
    int j=0;
    int n;
printf("enter the number of nodes :\t");
scanf("%d",&n);
for(int i=0;i<n;i++)
{
    temp=(struct node *)malloc(sizeof(int));
        printf("enter element for node %d:\t",i+1);
        scanf("%d",&(temp->info));
         temp->link=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
     p=start;
      while((p->link)!= NULL)
      {
          p=p->link;
      }
          (p->link)=(temp);

    }
}

p=start;
     while(p!=NULL)
   {
    printf("element of node %d is:\t%d\n",j+1,p->info);
    p=p->link;
    j++;
   }

return 0;
}

