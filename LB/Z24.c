#include<stdio.h>

int Addition(int no)
{
    static int icnt=1;
    static int sum=0;

    if(icnt<no)
    {
        sum=sum+icnt;
        icnt++;
        Addition(no);
    }
    return sum;
}

int main()
{
    int iValue,iret=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    int iRet=Addition(iValue);

    printf("%d\n",iRet);

    return 0;
}