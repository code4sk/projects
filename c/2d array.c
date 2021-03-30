#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
    char sub[4][300],stu[4][300],subj[40];
    int marks[3][3],subavg[3]={0};
    for(int i=0;i<3;i++)
    {
        printf("enter subject %d\n",i);
        scanf("%s",&sub[i]);
        fflush(stdin);
    }
    for(int j=0;j<3;j++)
    {
        printf("enter student %d\n",j);
        scanf("%s",&stu[j]);
        fflush(stdin);
    }
    for(int e=0;e<3;e++)
    {
        for(int k=0;k<3;k++)
        {
        printf("enter marks of %s in %s:",stu[e],sub[k]);
        scanf("%d",&marks[e][k]);
        fflush(stdin);
        }
    }
    for(int n=0;n<3;++n)
    {
        for(int m=0;m<3;m++)
        {
            subavg[n]=marks[m][n] + subavg[n]  ;
        }

        subavg[n]=subavg[n]/3;

    }
    for(int h=0;h<3;h++)
    printf("average of marks for subject %d are %d\n",h,subavg[h]);
    //printf("%d",subavg[0]);
}

