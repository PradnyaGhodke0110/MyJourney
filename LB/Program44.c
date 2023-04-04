/*Input:751
output:3

Input:7515
Output:4*/

#include<stdio.h>
int SumEvenDigits(int iNo)
{   
  //  int iDigit=0;
    int iSum=0;
    int iDigit=0;

    if(iNo<0)
    {
        iNo=-iNo;
    }

    while(iNo!=0)
    {
        iDigit=iNo%10;
        iNo/=10;
        if((iDigit%2)==0)
        {
            iSum=iSum+iDigit;
        }
    }
    return iSum;
   
}
int main()
{
    int iValue=0;
    int iRet=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    iRet=SumEvenDigits(iValue);

    printf("Number of digits are:%d\n",iRet);

    return 0;
}