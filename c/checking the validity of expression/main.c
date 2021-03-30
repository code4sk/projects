#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int top=-1;
    char exp[21],stack[21];
    scanf("%s",exp);
        for(int j=0;j<strlen(exp);j++)
        {
            if(exp[j]=='('||exp[j]=='['||exp[j]=='{')
                {
                    top++;
                    stack[top]=exp[j];
                    stack[top+1]=NULL;
                }
            if(exp[j]==')'||exp[j]==']'||exp[j]=='}')
                {
                    if(exp[j]==')')
                    {
                       if((stack[top]+1)==exp[j])
                    {
                        stack[top]=NULL;
                        if(top!=0)
                        top--;
                    }
                    }
                    else
                    {
                    if((stack[top]+2)==exp[j])
                    {
                        stack[top]=NULL;
                        if(top!=0)
                        top--;
                    }
                    }
                }
        }
        //printf("%s",stack);
      /*for(int k=0;k<strlen(exp);k++)
        {
            switch(exp[k])
{
     case ')' :    if(stack[top]=='(')
                        {
                            stack[top]==NULL;
                            if(top!=0)
                            top-=1;
                        }
                         else
                    {
                        puts("invalid expression");
                        exit(0);
                    }
                    break;
     case ']' :    if(stack[top]=='[')
                        {
                            stack[top]==NULL;
                            if(top!=0)
                            top-=1;
                        }
                        else
                    {
                        puts("invalid expression");
                        exit(0);
                    }
                    break;
     case '}' :    if(stack[top]=='{')
                        {
                            stack[top]==NULL;
                            if(top!=0)
                            top-=1;
                        }
                        else
                    {
                        puts("invalid expression");
                        exit(0);
                    }
                    break;
}
        }*/
        if(stack[top]==NULL)
        puts("valid expression");
        else
        puts("invalid expression");
    return 0;
}
