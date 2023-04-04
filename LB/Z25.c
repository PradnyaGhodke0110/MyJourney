#include<stdio.h>

int Factorial(int no)
{
     static int fact=1;
    static int icnt=1;

    if(icnt<=no)
    {
        fact=fact*icnt;
        icnt++;
        Factorial(no);
    }
    return fact;

}

int main()
{
    int ivalue=0,iRet=0;

    printf("enter value\n");
    scanf("%d\n",&ivalue);

    iRet=Factorial(ivalue);

    printf("%d\n",iRet);

    return 0;

}