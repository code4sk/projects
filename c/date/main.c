#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *str;
    int a,b,c;
    printf("Enter day\t");
    scanf("%d",&a);
    printf("Enter month\t");
    scanf("%d",&b);
    printf("Enter year\t");
    scanf("%d",&c);
    switch(b)
    {
        case 01 : str="JANUARY";
        break;
        case 02 : str="FEBRUARY";
        break;
        case 03 : str="MARCH";
        break;
        case 04 : str="APRIL";
        break;
        case 05 : str="MAY";
        break;
        case 06 : str="JUNE";
        break;
        case 07 : str="JULY";
        break;
        case 8 : str="AUGAST";
        break;
        case 9 : str="SEPTEMBER";
        break;
        case 10 : str="OCTOBER";
        break;
        case 11 : str="NOVEMBER";
        break;
        case 12 : str="DECEMBER";
        break;
        default : puts("INVALID MONTH");
    }
    printf("%s %d,%d",str,a,c);
    return 0;
}
