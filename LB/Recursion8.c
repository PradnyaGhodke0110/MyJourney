#include<stdio.h>
int FactorialR(int iNo)
{
    static int sum=1;
    static int iCnt=1;
    if(iCnt<=iNo)
    {
        sum=sum*iCnt;
        iCnt++;
        FactorialR(iNo);
    }
    return sum;
}
int main()
{
    int iValue=0,Ret=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    Ret=FactorialR(iValue);

    printf("Factorial is:%d\n",Ret);

    return 0;
}