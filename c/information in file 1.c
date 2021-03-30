#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
FILE *ptr,*ptr1,*ptr2;
int roll;
char a,b,c,d,e,f,g,h;
char str[21],alph[21],name[51],class[41],schl[41];
ptr=fopen("d:/new.txt","r");
if(ptr!='\0')
{
while((a=fgetc(ptr))!=':')
{
    printf("%c",a);
}
printf("\t");
scanf("\t%s",&str);
fflush(stdin);
puts("");
while((b=fgetc(ptr))!=':')
{
    printf("%c",b);
}
printf("\t");
scanf("\t%s",&alph);
fflush(stdin);
puts("");
while((c=fgetc(ptr))!=':')
{
    printf("%c",c);
}
printf("\t");
scanf("\t%d",&roll);
fflush(stdin);
puts("");
while((d=fgetc(ptr))!=':')
{
    printf("%c",d);
}
printf("\t");
scanf("\t%s",&schl);
fflush(stdin);
fseek(ptr,0,0);
ptr1=fopen("d:/yoo.txt","w");
while((e=fgetc(ptr))!='\n')
{
    fprintf(ptr1,"%c",e);
}
fprintf(ptr1,"\t");
fprintf(ptr1,"%s\n",str);
fputs("",ptr1);
while((f=getc(ptr))!='\n')
{
    fprintf(ptr1,"%c",f);
}
fprintf(ptr1,"\t");
fprintf(ptr1,"%s\n",alph);
fputs("",ptr1);
while((g=getc(ptr))!='\n')
{
    fprintf(ptr1,"%c",g);
}
fprintf(ptr1,"\t");
fprintf(ptr1,"%d\n",roll);
fputs("",ptr1);
while((h=getc(ptr))!='\n')
{
    fprintf(ptr1,"%c",h);
}
fprintf(ptr1,"\t");
fprintf(ptr1,"%s\n",schl);
fputs("",ptr1);
puts("success");
}
else
{
    puts("error");
}
    return 0;
}
