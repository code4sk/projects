#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void print(char *chr);
int main()
{
    int l=0;
    char str[96],substr[36],*chr;
    puts("Enter the string");
    gets(str);
    puts("Enter the substring");
    gets(substr);
    for(int i=0;i<=strlen(str);i++)
    {
        if(str[i]==substr[0])
        {
            for(int j=i+1,k=1;k<strlen(substr);k++,j++)
            {
                if(substr[k]==str[j])
                {
                    l++;
                    continue;
                }
                else
                {
                    l=0;
                    break;
                }
            }
             if(l==strlen(substr)-1)
        {
            l=0;
            chr=&str[i];
            print(chr);
            puts("");
            continue;
        }
        }
    }
    return 0;
}
void print(char *chr)
{
        printf("%s",chr);
}
