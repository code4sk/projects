#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t begin=clock();
    int num[11]={29,34,3,5,4,43432,534,54,35,53,909},k,j;
    int counter=0;
    double time = 0.00000000;
    for(int i=1;i<11;i++)
    {
        k=num[i];
        counter++;
        for(j=i-1;j>=0&&k<num[j];j--)
        {
            num[j+1]=num[j];
            counter++;
        }
        num[j+1]=k;
        counter++;
    }
    for(int i=0;i<11;i++)
    {
        printf("%d\t",num[i]);
    }
    clock_t end=clock();
    time += ((double)(end-begin))/CLOCKS_PER_SEC;
    printf("\n%d\n",counter);
    printf("%f\n",time);
    return 0;
}
