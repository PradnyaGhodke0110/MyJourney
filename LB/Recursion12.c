#include<stdio.h>
int CountDigitR(int iNo)
{
    
    static int iCnt=0;
    if(iNo!=0)
    {
        iCnt++;
        iNo=iNo/10;
        CountDigitR(iNo);
    }
    return iCnt;
    
}
int main()
{
    int iValue=0,iRet=0;;
    

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    iRet=CountDigitR(iValue);

    printf("No of Digits are:%d\n",iRet);

    return 0;
}