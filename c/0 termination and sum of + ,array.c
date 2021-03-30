#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
char str[16];
gets(str);
for(int i=0;str[i]!='\0';++i)
{
    if(str[i]<97)

    {
       str[i]=str[i]+32;
    }

}
printf("%s",str);
}

