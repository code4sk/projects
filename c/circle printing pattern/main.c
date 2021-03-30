#include <stdio.h>
#include <stdlib.h>

main()
{
    int a;
    puts("enter radius of circle");
    scanf("%d",&a);
    fflush(stdin);
    a++;
    puts("");
    for(int i=0;i<(a+1);i++)
    {
        printf(" ");
    }
    printf("%d",a-1);
   puts("");
   printf(" %d",a-1);
   for(int t=0;t<(2*a-1);t++)
   {
   printf(" ");
   }
   printf("%d",a-1);
    for(int k=0;k<(a-2);k++)
    {
        puts("");
    }
    printf("%d",a-1);
    for(int m=0;m<a;m++)
    {
        printf(" ");
    }
    printf("%d",a-1);
     for(int q=0;q<a;q++)
    {
        printf(" ");
    }
    printf("%d",a-1);
    for(int j=0;j<(a-2);j++)
    {
    puts("");
    }
    printf(" %d",a-1);
     for(int q=0;q<(2*a-1);q++)
   {
   printf(" ");
   }
   printf("%d",a-1);
    puts("");
     for(int n=0;n<(a+1);n++)
    {
        printf(" ");
    }
    printf("%d",a-1);
    getch();
}
