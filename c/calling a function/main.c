#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    char opr;
    scanf("%d %d %c",&a,&b,&opr);
    fflush(stdin);

    fflush(stdin);
    calc(a,b,opr);
    return 0;
}
calc(a,b,opr)
{


    switch(opr)
    {
        case '+':printf("%d",a+b);break;
        case '-':printf("%d",a-b);break;
        case '*':printf("%d",a*b);break;
        case '/':printf("%d",a/b);break;
        default :printf("invalid operator");
    }
}


