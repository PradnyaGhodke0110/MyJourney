//Bitwiese operator

#include<stdio.h>
typedef unsigned int UNIT;

int CountBits(UNIT iNo)
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
    UNIT Value=0;
    int Ret=0;

    printf("Enter Value");
    scanf("%d",&Value);

    Ret=CountBits(Value);
    printf("Number of Bits which are on :%d\n ",Ret);
    return 0;
}