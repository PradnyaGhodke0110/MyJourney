#include<stdio.h>
int FactorSR(int iNo)
{
    //static int sum=1;
    static int iCnt=1;
    if(iCnt<=(iNo/2))
    {
        if(iNo%iCnt==0)
        {
            printf("%d ",iCnt);
            
        }
        iCnt++;
        FactorSR(iNo);
    }
    
}
int main()
{
    int iValue=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    FactorSR(iValue);

    return 0;
}