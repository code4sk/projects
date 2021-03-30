#include <stdio.h>
#include <stdlib.h>

void show(int , char , char ,char);
void tofh(int n,char s,char t,char d);
int main()
{
    char s='A',t='B',d='C';
    int n;
    printf("Enter the number of disks in source\t");
    scanf("%d",&n);
    //show(n,s,t,d);
    tofh(n,s,t,d);
    return 0;
}
void tofh(int n,char s,char t,char d)
{
    if(n==1)
    {
        printf("move disc 1 from %c-->%c\n",s,d);
        return;
    }
    tofh(n-1,s,d,t);
    printf("move disc %d from %c-->%c\n",n,s,d);
    tofh(n-1,t,s,d);
}
