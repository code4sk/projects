#include <stdio.h>
#include <stdlib.h>

struct marks
{
    char name[21];
    int physics;
    int chemestry;
    int math;
};

int p_ge;
char grade;
char name[21];
int physics;
int chemestry;
int math;
int main()
{

 struct marks data;
    gets(data.name);
    fflush(stdin);
    scanf("%d\n%d\n%d",&data.physics,&data.chemestry,&data.math);
    fflush(stdin);

      //  printf("%d",data.physics);
   calc(data);
    return 0;
}
//int calc(name,physics,chemestry,math)
int calc(*num)
//struct marks data;
{
    struct marks *num;


     printf("%d\n",num->physics);
    //extern struct marks data;
//    printf("%d",data.physics);
  //printf("%s\n%d\n%d\n%d",name,physics,chemestry,math);
  float z=0,j=0;
  z=(data.physics+data.chemestry+data.math);
  j=z/3;
  printf("\npercentage of %s is %f",data.name,j);
  alph(j);
  return 0;
}
alph(z)
float z;
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

}
