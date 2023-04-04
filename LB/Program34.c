#include<stdio.h>

int DisplayNonFactors(int iValue)
{
    int iSum=0,iCnt=0;

    for(iCnt=1;iCnt<iValue;iCnt++)
    {
        if((iValue%iCnt)!=0)
        {
            iSum=iSum+iCnt;
        }
    }

    return iSum;

}
int main()
{
    int iNo=0;
    int iRet=0;

    printf("enter number: \n");
    scanf("%d \n",&iNo);

    iRet=DisplayNonFactors(iNo);

    printf("sum of non factors  is : %d \n ",iRet);
    
    return 0;
}