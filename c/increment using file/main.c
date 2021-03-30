#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ptr,*ptr1;
    int p,e,c,m,ph;
    int f,g,h,i,k,l;
    float t,j=0;
    ptr=fopen("d:/data.txt","r+");
    if(ptr!='\0')
    {
    while((f=getc(ptr))!='\n')
    {
        printf("%c",f);
    }
    while((p=getc(ptr))!=':')
    {

    }

    fscanf(ptr,"%d",&p);
    fflush(stdin);
    printf("\n%d",p);
   while((c=getc(ptr))!=':')
   {

   }

    fscanf(ptr,"%d",&c);
    fflush(stdin);
    printf("\n%d",c);
    while((m=getc(ptr))!=':')
    {

    }

    fscanf(ptr,"%d",&m);
    fflush(stdin);
    printf("\n%d",m);
    while((e=getc(ptr))!=':')
    {

    }

    fscanf(ptr,"%d",&e);
    fflush(stdin);
    printf("\n%d",e);
    while((ph=getc(ptr))!=':')
    {

    }

    fscanf(ptr,"%d",&ph);
    fflush(stdin);
    printf("\n%d\n",ph);
    float max(p,c,m,e,ph);
    t=max(p,c,m,e,ph);
    while((g=getc(ptr))!='%')
    {

    }
    fseek(ptr,1,1);
    //fscanf(ptr,"%d",&l);
    fprintf(ptr,"yes");
    fseek(ptr,0,1);
    while((h=getc(ptr))!='=')
    {

    }
    fseek(ptr,0,1);
    fprintf(ptr,"%5.2f",t);
    puts("\nsuccess");
    }
    else
    {
        puts("error");
    }
    return 0;
}
float max(int a,int b,int c,int d,int e)
{
    int num[5];
    float t,j;
    num[0]=a;
    num[1]=b;
    num[2]=c;
    num[3]=d;
    num[4]=e;
    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<5;j++)
        {
            if(num[i]>num[j])
            {
                int temp;
                temp=num[i];
                num[i]=num[j];
                num[j]=temp;
            }
        }
    }
    num[0]=num[0]+5;
    num[1]=num[1]+5;
    t=(num[0]+num[1]+num[2]+num[3]+num[4]);
    j=t/5;
    printf("\n%f",j);
    return j;
}
