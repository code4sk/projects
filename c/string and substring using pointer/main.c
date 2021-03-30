#include <stdio.h>
#include <stdlib.h>

int main()
{
    int no=0,pos=0;
    char str[21],alph[21],*ptr1,*ptr2,*ptr3,*ptr4;
    int num=0,flag=1,total=0,z=0;
    scanf("%s",&str);
    fflush(stdin);
    scanf("%s",&alph);
    fflush(stdin);
    ptr1=str;
    ptr2=alph;
    ptr3=str;
    ptr4=alph;
    for(int i=0;str[i]!='\0';i++)
    {
        num++;
    }
    for(int k=0;alph[k]!='\0';k++)
    {
        no++;
    }
    for(int j=0;j<num;j++)
    {
        if(*ptr2==*ptr1)
        {
            for(;*ptr2!='\0';ptr2++,ptr1++)
            {
                if(*ptr2==*ptr1)
                total++;
            }
            if(total==no)
            {
                puts("yes");
                break;
            }
            else
            {
                puts("no");
                break;
            }

        }
        ptr1++;

    }
    if(total==no)
    {

for(;*ptr3!='\0';ptr3++)
{
    if(*ptr3!=*ptr4)
    {
        pos++;
    }
    else
        break;
}

    }
    pos++;

 if(total==no)
 {
    printf("opening position: %d\n",pos);
    z=pos+no-1;
     printf("closing position: %d\n",z);
 }
    return 0;
}
