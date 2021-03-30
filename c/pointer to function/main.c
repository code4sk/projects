#include <stdio.h>
#include <stdlib.h>

int main()
{
  int a,b,z;
  int (*ptr)(int,int);
  scanf("%d%d",&a,&b);
  add(a,b);
  ptr=&add;
  z=ptr(a,b);
  printf("%d",z);
    return 0;
}
    int add(int x,int y)
    {
        int z;
        z=x+y;
        return z;
    }
