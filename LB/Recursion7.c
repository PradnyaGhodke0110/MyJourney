#include<stdio.h>
int AdditionR(int iNo)
{
    static int sum=0;
    static int iCnt=1;
    if(iCnt<=iNo)
    {
        sum=sum+iCnt;
        iCnt++;
        AdditionR(iNo);
    }
    return sum;
}
int main()
{
    int iValue,Ret=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    Ret=AdditionR(iValue);

    printf("Addition is:%d\n",Ret);

    return 0;
}