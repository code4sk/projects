#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()
{
char name[21],*ptr;
gets(name);
fflush(stdin);
ptr=name;
for(;*ptr!='\0';ptr++)
{
    *ptr=*ptr+20000;
}
printf("encripted name :%s\n",name);
ptr=ptr-strlen(name);
for(;*ptr!='\0';ptr++)
{
    *ptr=*ptr-20000;
}
printf("decripted name :%s\n",name);
}
