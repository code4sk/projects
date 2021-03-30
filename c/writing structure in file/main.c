#include <stdio.h>
#include <stdlib.h>
struct emp
{
    int transno;
    int salesno;
    int prdno;
    int unit;
};
int main()
{
    FILE *ptr;
    int g,flag=1,num=0;
    char alph;
    ptr=fopen("d:/yoo.txt","r+");
    if(ptr!='\0')
    {
        struct emp data,str;
        do
        {
            puts("enter 'y' to continue");
        alph=getchar();
        fflush(stdin);
        if(alph=='y')
        {
            puts("enter transection number");
        scanf("\n%d",&data.transno);
        puts("enter salesman number");
        scanf("\n%d",&data.salesno);
        fflush(stdin);
        puts("enter product number");
        scanf("\n%d",&data.prdno);
        fflush(stdin);
        puts("enter number of unit sold");
        scanf("\n%d",&data.unit);
        fflush(stdin);
        fwrite(&data,sizeof(struct emp),1,ptr);
        fputs("\n",ptr);
        num++;
        }
        else
            {
                flag=0;
            }
        }while(flag);
    }
    else
    {
        puts("error in opening file");
    }
    printf("number of entry you entered :%d",num);
    return 0;
}
