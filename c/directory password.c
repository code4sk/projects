#include <stdio.h>
#include <stdlib.h>

int main()
{
int chc,sk=1;
char pass;
puts("MENU");
puts("1 : SELECT A DIRECTORY");
puts("2 :DELEATE A DIRECTORY");
puts("3 :SHOW A DIRECTORY");
puts("EXIT");
puts("PLEASE ENTER PASSWORD");
pass=getchar();
fflush(stdin);
if(pass=='7')
{
    puts("ENTER YOUR CHOICE:");

while(sk==1)
{scanf("%d",&chc);
    switch(chc)
    {

    case 1:puts("YOU CHOSE TO SELECT A DIRECTORY");
     break;
    case 2:puts("YOU CHOSE TO DELEATE A DIRECTORY");
     break;
    case 3:puts("YOU CHOSE TO SHOW A DIRECTORY");
     break;
    case 4:puts("YOU CHOSE TO EXIT");
     break;
    default :sk==2;
    }
}
}
else
{
    puts("TRY AGAIN ... YOU HAVE ENTERED WRONG PASSWORD");
}
return 0;
}
