#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1[3][3]={(1,2,3),(4,5,6),(7,8,9)},num2[3][3]={(1,2,3),(4,5,6),(7,8,9)},num3[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            num3[i][j]=(num1[i][j]*num2[j][i]);      }
       for(int k=0;k<3;k++)
    {
       /* for(int l=0;l<3;l++)
        {

            printf("\t%5d",num3[k][l]);

        }
          */

    }


    }
      printf("%d",num3[0][0]);

    return 0;
}
