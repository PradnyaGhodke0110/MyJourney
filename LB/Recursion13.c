#include<stdio.h>
int SumDigitR(int iNo)
{
    static int iSum=0;
    //static int iCnt=0;
    int iDigit;
    if(iNo!=0)
    {
        iDigit=iNo%10;
        iSum=iSum+iDigit;
        iNo=iNo/10;
        SumDigitR(iNo);
    }
    return iSum;
    
}
int main()
{
    int iValue=0,iRet=0;;
    

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    iRet=SumDigitR(iValue);

    printf("Sum of Digits are:%d\n",iRet);

    return 0;
}