#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *link;
};
int l;
struct node *front=NULL,*rear;
create();
display();
int main()
{
int n,c;
    printf("enter the number of fan in the queue\t");
    scanf("%d",&n);
    l=n;
    create();
    display();
    while(c!=4)
    {
        printf("\nenter your choice\n1:push\n2:pop\n3:display\n4:quite\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1 : push();
            break;
            case 2 : pop();
            break;
            case 3 : display();
            break;
            case 4 : puts("have a nice day......");
            break;
            default : puts("-----invalid operation-----");
        }
    }
    return 0;
}
create()
{
    struct node *temp;
  for(int i=0;i<l;i++)
 {
     temp=(struct node *)malloc(sizeof(struct node));
     if(i==0)
    {
     front=temp;
     rear=temp;
    }
    else
    {
     rear->link=temp;
     rear=temp;
    }
     temp->num=i+1;
 }
}
display()
{
    printf("\n_________\n");
    printf("         |\n         |\n taylor  |\n swift   |\n         |\n_________|");
    for(int i=0;i<l;i++)
    {
        printf("%d ",i+1);
    }
}
push()
{
     struct node *temp;
     temp=(struct node *)malloc(sizeof(struct node));
     rear->link=temp;
     rear=temp;
     l++;
}
pop()
{
     front=front->link;
     l--;
}
