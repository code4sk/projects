#include <stdio.h>
#include <stdlib.h>

struct marks
{
    char name[21];
    int physics;
    int chemestry;
    int math;
};
 float z,k;
struct mark *ptr,*ptr1;
int p_ge;
char grade;
int main()
{
    struct marks data[2];
    for(register int i=0;i<2;i++)
    {
        puts("enter name");
    gets(data[i].name);
    fflush(stdin);
    scanf("%d\n%d\n%d",&data[i].physics,&data[i].chemestry,&data[i].math);
    fflush(stdin);
    }

      //  printf("%d",data.physics);
   calc(&data[0],&data[1]);
    return 0;
}
//int calc(name,physics,chemestry,math)
   calc(struct marks *ptr,struct marks *ptr1)
{
  printf("%s\n%d\n%d\n%d\n",ptr->name,ptr->physics,ptr->chemestry,ptr->math);
  float z=0,j=0,h=0,k=0;
  z=(ptr->physics+ptr->chemestry+ptr->math);
  j=z/3;
  printf("\npercentage of %s is %f",ptr->name,j);
  printf("%s\n%d\n%d\n%d",ptr1->name,ptr1->physics,ptr1->chemestry,ptr1->math);
  h=(ptr1->physics+ptr1->chemestry+ptr1->math);
  k=h/3;
  printf("\npercentage of %s is %f",ptr1->name,k);
  alph(j,k);
}
alph(z,k)
{
    if(z>=90)
    {
        puts("\nA grade");
    }
    if(z<90&&z>=80)
    {
        puts("\nB grade");
    }
    if(z<80&&z>=70)
    {
        puts("\nC grade");
    }
    if(z<70)
    {
        puts("\nD grade");
    }
    if(k>=90)
    {
        puts("\nA grade");
    }
    if(k<90&&k>=80)
    {
        puts("\nB grade");
    }
    if(k<80&&k>=70)
    {
        puts("\nC grade");
    }
    if(k<70)
    {
        puts("\nD grade");
    }

}
