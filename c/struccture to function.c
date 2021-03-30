#include <stdio.h>
#include <stdlib.h>

struct marks
{
    char name[21];
    int physics;
    int chemestry;
    int math;
}data;
int p_ge;
char grade;
char name[21];
int physics;
int chemestry;
int math;
int main()
{
    gets(data.name);
    fflush(stdin);
    scanf("%d\n%d\n%d",&data.physics,&data.chemestry,&data.math);
    fflush(stdin);
    calc(data);
    return 0;
}
//int calc(name,physics,chemestry,math)
int calc(data)
{
  //printf("%s\n%d\n%d\n%d",name,physics,chemestry,math);
  float z=0,j=0;
  z=(physics+chemestry+math);
  j=z/3;
  printf("percentage of %s is %f",name,j);
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
