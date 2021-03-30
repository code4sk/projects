#include <iostream>
#include <stack>
using namespace std;
int pre(char a,stack <char> s);
int main()
{
    stack <char> s;
    char a;
    a=getchar();
    while(a!='\n')
    {
        if(a=='(')
        {
            s.push(a);
        }
        else if(a==')')
        {
            char c=s.top();
            s.pop();
            while(c!='(')
            {
                printf("%c",c);
                c=s.top();
                s.pop();
            }
        }
        else if(a>='a'&&a<='z')
        {
            printf("%c",a);
        }
        else if(a=='+'||a=='-'||a=='*'||a=='/')
        {
            if(pre(a,s))
               {
                   s.push(a);
               }
            else
                {
                    while(1)
                    {
                        char c;
                        c = s.top();
                        s.pop();
                        printf("%c",c);
                        if(pre(c,s))
                        {
                            s.push(a);
                            break;
                        }
                        else
                            continue;
                    }
                }
        }
        a=getchar();
    }
    while(s.size()!=0)
    {
        printf("%c",s.top());
        s.pop();
    }
    return 0;
}
int pre(char a,stack <char> s)
{
    if(s.size()==0)
        return 1;
    char c=s.top();
    if(c=='+'||c=='-')
    {
        if(a=='*'||a=='/')
            return 1;
            else
                return 0;
    }
    if(c=='*'||c=='/')
    {
        if(a=='*'||a=='/')
            return 0;
    }
    return 1;
}
