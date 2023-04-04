#include<stdio.h>
int MaxDigit(int iNo)
{  
    int iDigit=0;
    int iMax=0;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    while(iNo!=0)
    {
        iDigit=iNo%10;
        if(iDigit>iMax)
        {
            iMax=iDigit;
        }
        if(iMax==9)
        {
            break;
        }
        iNo/=10;

    }
    return iMax;

}
int main()
{
    int iValue;
    int iRet=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    iRet=MaxDigit(iValue);

    printf("Largest No.is:%d\n",iRet);

    return 0;
}
