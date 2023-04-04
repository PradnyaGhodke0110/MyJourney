#include<stdio.h>
int SumFactorSR(int iNo)
{
    static int sum=0;
    static int iCnt=1;
    if(iCnt<=(iNo/2))
    {
        if(iNo%iCnt==0)
        {
            printf("%d\n",iCnt);
            sum=sum+iCnt;
            
        }
        iCnt++;
        SumFactorSR(iNo);
    }
    return sum;
    
}
int main()
{
    int iValue=0,iRet=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    iRet=SumFactorSR(iValue);

    printf("Sum of Factors:%d\n",iRet);

    return 0;
}