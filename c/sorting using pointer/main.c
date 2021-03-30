#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[21],*ptr1,*ptr2;
    gets(str);
    ptr1=str;
    ptr2=str;
    ptr2++;


  for(;*ptr1!='\0';ptr1++)
    {
        for(ptr2=ptr1+1;*ptr2!='\0';ptr2++)
        {
            if(*ptr1>*ptr2)
            {
                char temp;
                temp=*ptr1;
                *ptr1=*ptr2;
                *ptr2=temp;
            }
        }
    }

    printf("%s",str);
    return 0;
}
