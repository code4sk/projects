#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
void main()
{
    char alph;
    puts("enter any alphabet");
    alph=getchar();
    fflush(stdin);
    switch(alph)
    {
        case'A':puts("vowel A");
        break;
        case'E':puts("vowel E");
        break;
        case'I':puts("vowel I");
        break;
        case'O':puts("vowel O");
        break;
        case'U':puts("vowel U");
        break;
        case'a':puts("vowel a");
        break;
        case'e':puts("vowel e");
        break;
        case'i':puts("vowel i");
        break;
        case'o':puts("vowel o");
        break;
        case'u':puts("vowel u");
        break;
        default:puts("alphabet is not a vowel");

    }

}
