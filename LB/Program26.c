#include<stdio.h>
int Summation(int iValue)
{
    int iSum=0;
    int iCnt=0;
    for(iCnt=1;iCnt<=iValue;iCnt++)
    {
        iSum=iSum + iCnt;
    }
    return iSum;

}

int main()
{
    int iNo;
    int iRet;
    printf("enter the no .of elements to be added \n");
    scanf("%d",&iNo);
    iRet=Summation(iNo);
    printf("Summation is: %d \n",iRet);
    return 0;
    

}