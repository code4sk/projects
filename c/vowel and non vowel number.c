#include <stdio.h>
#include <stdlib.h>

void main()
{
    char alph;
    int v=0,nv=0;

        while(alph!='!')
        {   alph=getchar();
            fflush(stdin);
            switch(alph)
            {
             case 'a': ++v;
            break;
            case 'e': ++v;
            break;
            case 'i': ++v;
            break;
            case 'o': ++v;
            break;
            case 'u': ++v;
            break;
            default : ++nv;
            }
            while(alph!='!')
            {
            alph=getchar();
            fflush(stdin);
            if(alph!='!')
            {
            switch(alph)
            {
            case 'a': ++v;
            break;
            case 'e': ++v;
            break;
            case 'i': ++v;
            break;
            case 'o': ++v;
            break;
            case 'u': ++v;
            break;
            default : ++nv;
            }
            }
            }
        }
        //printf("total number of vowel is %d\n",v);
        //printf("total number of consonent is %d\n",nv);
        if(nv>=v)
        {   if(nv>v)
        {
            puts("number of consonent is more than number of vowel");
        }
            else
            {
                puts("number of consonent and vowel are equal");
            }
        }
        else
        {
            puts("number of vowels are more than number of consonent");
        }
}


