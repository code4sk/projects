#include <stdio.h>
#include <stdlib.h>
int priority(char );
int main()
{
    int top=-1,top1=-1,p,t,n;
    char inf[26],stack[26],pos[26];
    printf("enter the infix\n");
    scanf("%s",inf);
    for(int i=0;i<strlen(inf);i++)
    {
        if(inf[i]!='+'&&inf[i]!='-'&&inf[i]!='*'&&inf[i]!='/'&&inf[i]!='^'&&inf[i]!='('&&inf[i]!=')')
        {
            top1++;
            pos[top1]=inf[i];
            pos[top1+1]=NULL;
        }
        if(inf[i]=='+'||inf[i]=='-'||inf[i]=='*'||inf[i]=='/'||inf[i]=='^')
        {
            p=priority(inf[i]);
            for(int j=0;j<=top;j++)
            {
               t=priority(stack[j]);
               if(t>=p)
               {
                   top1++;
                   pos[top1]=stack[j];
                   for(int k=j;k<=top;k++)
                   {
                       stack[k]=stack[k+1];
                   }
                   top--;
               }
            }
            top++;
            stack[top]=inf[i];
            stack[top+1]=NULL;
        }
    }
    n=top;
    while(n>=0)
    {
        top1++;
        pos[top1]=stack[n];
        pos[top1+1]=NULL;
        n--;
    }
printf("%s",pos);
    return 0;
}
int priority(char o)
{
    switch(o)
    {
        case '(' :  return 0;
        break;
        case '^' :  return 1;
        break;
        case '*' :  return 2;
        break;
        case '/' :  return 2;
        break;
        case '+' :  return 3;
        break;
        case '-' :  return 3;
        break;
    }
}
