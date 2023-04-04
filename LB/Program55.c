#include<stdio.h>
int MinDigit(int iNo)
{  
    int iDigit=0;
    int iMin=9;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    while(iNo!=0)
    {
        iDigit=iNo%10;
        if(iDigit<iMin)
        {
            iMin=iDigit;
        }
        iNo/=10;

    }
    return iMin;

}
int main()
{
    int iValue;
    int iRet=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    iRet=MinDigit(iValue);

    printf("Largest No.is:%d\n",iRet);

    return 0;
}
