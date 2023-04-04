//Bitwiese operator

#include<stdio.h>

int CountBits(unsigned int iNo)
{
    int Digit=0;
    int iCnt=0;

    while(iNo!=0)
    {
        Digit=iNo%2;
        if(Digit==1)
        {
            iCnt++;
        }
    iNo=iNo/2;
    }
    return  iCnt;
    
}
int main()
{
    unsigned int Value=0;
    int Ret=0;

    printf("Enter Value");
    scanf("%d",&Value);

    Ret=CountBits(Value);
    printf("Number of Bits which are on :%d\n ",Ret);
     return 0;
    }