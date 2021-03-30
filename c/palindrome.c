#include <stdio.h>
#include <stdlib.h>

void main()
{
   char alph[21];
   int num=0,total=0,g=0,f=0;
   gets(alph);
   fflush(stdin);
    for(int i=0;alph[i]!='\0';i++)
        ++num;
        total=num;
        num--;
        if(total%2==0)
        {
   for(int j=0;j<=num;j++)
   {
       if(alph[j]==alph[num-j])
        g++;
   }
   if(total==g)
    printf("palindrome");
    else
    {printf("no");
   }
        }
        else
        {
            for(int n=0;n<=num;n++)
            {
                if(alph[n]==alph[num-n])
                f++;
            }
            if(total==f)
    printf("palindrome");
    else
    {printf("no");
    }
        }

}

