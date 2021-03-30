#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int v=0,c=0,w=0,d=0;
    char str[36];
    puts("Enter a line");
    gets(str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]==' ')
        {
            w++;
            continue;
        }
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='u'||str[i]=='o'||str[i]=='A'||str[i]=='E'||str[i]=='O'||str[i]=='I'||str[i]=='U')
            v++;
        else if((str[i]>'A'&&str[i]<'Z')||(str[i]>'a'&&str[i]<'z'))
            c++;
        if(str[i]>='0'&&str[i]<='9')
            d++;
    }
    printf("Whitespace\t%d\nVowel\t%d\nConsonent\t%d\nDigit\t%d\n",w,v,c,d);
    return 0;
}
