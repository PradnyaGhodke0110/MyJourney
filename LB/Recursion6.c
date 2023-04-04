#include<stdio.h>
int Addition(int iNo)
{
    int sum=0;
    int iCnt=1;
    while(iCnt<=iNo)
    {
        sum=sum+iCnt;
        iCnt++;
    }
    return sum;
}
int main()
{
    int iValue,Ret=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    Ret=Addition(iValue);

    printf("Addition is:%d\n",Ret);

    return 0;
}