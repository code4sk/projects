#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str1[21],str2[21],*ptr1,*ptr2;
    int flag=1;
    scanf("%s",&str1);
    fflush(stdin);
    scanf("%s",&str2);
    fflush(stdin);
    ptr1=str1;
    ptr2=str2;
    while(flag)
    {
        if(*ptr1==*ptr2)
        {
              if(*ptr1=='\0')
            {
                printf("yes");
                flag=0;
                break;
            }
            ptr1++;
            ptr2++;
            flag=1;
        }
        else
        {
            flag=0;
            printf("no");
        }


    }

    return 0;
}
