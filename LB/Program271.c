//Bitwiese operator

#include<stdio.h>

void DisplayBinary(unsigned int iNo)
{
    int Digit=0;

    while(iNo!=0)
    {
        Digit=iNo%2;
        printf("%d",Digit);
        iNo=iNo/2;
    }
    printf("\n");
}
int main()
{
    unsigned int Value=11;
    DisplayBinary(Value);
    return 0;
}