#include <stdio.h>
#include <stdlib.h>

int main()
{
    char alph;
    int num=0;
    while(num<=4)
    {
        alph=getchar();
        fflush(stdin);
        ++num;
        if(alph>='A')
        {
            if(alph<='Z')
            {
                puts("input is uppercase character");
            }
            else
            {
                if(alph<='z')
                {
                    puts("input is lowercase alphabet");
                }
            }

        }
        else
        {
            if(alph<='9')
            {
                if(alph>='0')
                {
                    puts("input is digit");
                }
            }
        }
    }
    return 0;
}
