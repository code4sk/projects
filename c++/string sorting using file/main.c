#include <stdio.h>
#include <stdlib.h>
int main()
{
    char a,str[1000][2000];
    FILE *ptr,*ptr1;
    ptr=fopen("G:/data.txt","r");
    ptr1=fopen("G:/result.txt","w");
    if(ptr==NULL)
        printf("error");
    else
    {
        for(int i=0;i<5;i++)
        {
           int j=0;
        while((a=fgetc(ptr))!='.')
            {
            str[i][j]=a;
            j++;
            }
            fseek(ptr,2,1);
            str[i][j]='.';
        }
       for(int i=0;i<5;i++)
        {
        for(int l=0;str[i][l+1]!='.';l++)
        {
            for(int m=l+1;str[i][m]!='.';m++)
            {
                if(str[i][l]<str[i][m])
                {
                char temp;
                temp=str[i][l];
                str[i][l]=str[i][m];
                str[i][m]=temp;
                }
            }
        }
        }
        for(int i=0;i<5;i++)
        {
        fputs(str[i],ptr1);
        fputc('\n',ptr1);
        }
    }
    return 0;
}
