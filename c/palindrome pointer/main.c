#include <stdio.h>
#include <stdlib.h>

int main()
{
char alph[21],sk='y';
scanf("%s",&alph);
fflush(stdin);
char *ptr,*lptr;
for(lptr=alph;*lptr!='\0';lptr++)
{

}

    ptr=alph;
lptr--;
//printf("%c%c/n",*lptr,*ptr);
while(sk=='y')
{
    if(*ptr==*lptr)
    {
        ptr++;
        lptr--;
        if(*ptr=='\0'){
            printf("yes\n");
        break;
        }
    }
    else{
        printf("no\n");
        sk='n';
    }
}
    return 0;
}
