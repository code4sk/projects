#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue_arr[5],front=-1,rear=-1;
create(int n);
display(int n);
push();
pop();
int main()
{
    int n,c;
    puts("enter the number of customer in queue");
    scanf("%d",&n);
    if(n>5)
        n=5;
    create(n);
    display(n);
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
            case 3 : display(rear+1);
            break;
            case 4 : puts("have a nice day......");
            break;
            default : puts("-----invalid operation-----");
        }
    }
    return 0;
}
create(int n)
{
    for(int i=0;i<n;i++)
    {
        if(i==0&&n>0)
            front=0;
        queue_arr[i]=i+1;
        rear++;
    }
}
display(int n)
{
    printf("\n_________\n");
    printf("         |\n         |\n         |\n         |\n         |\n         |");
    printf("\n---------\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",i+1);
    }
}
push()
{
    rear++;
   queue_arr[rear]=rear+1;
}
pop()
{
 queue_arr[rear]=NULL;
 rear--;
}
