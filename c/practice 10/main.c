#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int arr[MAX];
int size;
void insert(int n);
void restore_up();
void display();
void restore_down(int n);
void delete(int n);
int main()
{
    int c,n;
    arr[0]=1000;
    while(1)
    {
        printf("Enter your choice\n1:Insert\n2:Delete\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1 :   printf("Enter the marks\n");
                       scanf("%d",&n);
                       insert(n);
                       display();
                       break;
            case 2 :   printf("Enter the marks\n");
                       scanf("%d",&n);
                       delete(n);
                       display();
                       break;
        }
    }
    return 0;
}
void insert(int n)
{
    arr[++size]=n;
    restore_up();
}
void restore_up()
{
    int i=size,temp;
    while(arr[i]>arr[i/2])
    {
        temp=arr[i];
        arr[i]=arr[i/2];
        arr[i/2]=temp;
        i=i/2;
    }
}
void display()
{
    for(int i=1;i<=size;i++)
    {
        printf("%d\t",arr[i]);
    }
    puts("");
}
void delete(int n)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==n)
            break;
    }
    arr[i]=arr[size--];
    restore_down(i);
}
void restore_down(int i)
{
    int temp;
    while((arr[i]<arr[2*i]||arr[i]<arr[2*i+1])&&(2*i<=size||2*i+1<=size))
    {
        if(arr[i]<arr[2*i])
        {
            temp=arr[i];
            arr[i]=arr[2*i];
            arr[2*i]=temp;
            i=2*i;
            continue;
        }
        if(arr[i]<arr[2*i+1])
        {
            temp=arr[i];
            arr[i]=arr[2*i+1];
            arr[2*i+1]=temp;
            i=2*i+1;
            continue;
        }
        if(arr[i]<arr[2*i]&&arr[i]<arr[2*i+1])
        {
            if(arr[2*i]>arr[2*i+1])
            {
                temp=arr[i];
                arr[i]=arr[2*i];
                arr[2*i]=temp;
                i=2*i;
                continue;
            }
            else
            {
                temp=arr[i];
                arr[i]=arr[2*i+1];
                arr[2*i+1]=temp;
                i=2*i+1;
                continue;
            }
        }
    }
}
