#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum stat{e,o,d};
struct student
{
   int marks;
   char name[11];
};
struct record
{
    struct student info;
    enum stat status;
};
struct record rec[17];
void insert(char name[],int marks);
void display(int n);
void del(int n);
int main()
{
    int c,n,l=0;
    char name[11];
    for(int i=0;i<17;i++)
        rec[i].status=e;
    while(1)
    {
    puts("Enter your choice\n1:Insert\n2:Delete\n3:Display\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1 : puts("Enter the name of student:");
                 scanf("%s",name);
                 puts("Enter the marks of student:");
                 scanf("%d",&n);
                 insert(name,n);
                 break;
        case 2 : puts("Enter the marks of student which you want to delete");
                 scanf("%d",&n);
                 del(n);
                 break;
        case 3 : puts("Enter the marks of student:");
                 scanf("%d",&n);
                 display(n);
                 break;
    }
    }
    return 0;
}
void insert(char name[],int marks)
{
    int k;
    k=marks%17;
    if(rec[k].status==e)
    {
        rec[k].info.marks=marks;
        for(int i=0;i<strlen(name);i++)
        rec[k].info.name[i]=name[i];
        rec[k].status=o;
        return;
    }
    else if(rec[k].status==o)
    {
        while(1)
        {
            k++;
            if(k>16)
                k=0;
            if(rec[k].status==e)
            {
                rec[k].info.marks=marks;
                for(int i=0;i<strlen(name);i++)
                rec[k].info.name[i]=name[i];
                rec[k].status=o;
                break;
            }
        }
    }
}
void display(int n)
{
    int k,i;
    k=n%17;
    while(1)
    {
    if(rec[k].status==e)
    {
        puts("Marks not found");
        break;
    }
    if(rec[k].info.marks==n)
    {
     printf("%s------>%d\n",rec[k].info.name,rec[k].info.marks);
     break;
    }
    k++;
    if(k>16)
        k=0;
    }
}
void del(int n)
{
    int k;
    k=n%17;
    while(1)
    {
        if(rec[k].status==o&&rec[k].info.marks==n)
        {
            rec[k].info.marks=0;
            rec[k].status=d;
            for(int i=0;rec[k].info.name[i]!='\0';i++)
            rec[k].info.name[i]='\0';
            break;
        }
        if(rec[k].status==e)
        {
            puts("\n--------Marks not found--------\n");
            break;
        }
        k++;
        if(k>16)
            k=0;
    }
}
