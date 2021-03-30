#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack_arr[MAX];
int top=-1;
void push(int item);
void display();
void pop();
int main()
{
    int c,item;
    while(1)
    {
    puts("\nenter the choice\n");
    printf("\n1:push\n2:display\n3:pop\n");
    scanf("%d",&c);
    switch(c)
{
    case 1 : puts("enter the item");
               scanf("%d",&item);
           push(item);
           break;
    case 2 :   display();
           break;
    case 3 : pop();
           break;
}
    }
    return 0;
}
void push(int item)
{
    if(top==MAX-1)
    {
        puts("space is not available");
        return;
    }
    else
    {
        top=top+1;
        stack_arr[top]=item;
    return;
    }
}
void display()
{
    if(top==-1)
    {
        puts("list is empty");
        return;
    }
    for(int i=0;i<=top;i++)
    {
    printf("\n%d",stack_arr[(top-i)]);
    }
    return;
}
void pop()
{
    if(top==-1)
    {
        puts("list is empty");
        return;
    }
    else
    {
        stack_arr[top]=NULL;
        top-=1;
        return;
    }
}
