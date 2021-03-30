#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0,l=1;
    char alph,alph1;
     char chr;

    while(alph!='0')
    {
        alph1=getchar();
        fflush(stdin);
        chr=alph1;
        if(alph1=='0')
        {
            break;
        }
        for(int j=0;;j++)
        {
        alph=getchar();
        if(alph!=alph1)
        {
        printf("\r\t\t\tnumber of times character entered: %d\n",l);
        fflush(stdout);
        break;
        }
        fflush(stdin);
        if(alph==alph1)
        {
            l++;
            continue;
        }


        }

        l=1;
    }
    return 0;
}
