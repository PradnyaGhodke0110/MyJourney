#include<stdio.h>
#include<stdbool.h>
int Reverse(int iNo)
{   
  //  int iDigit=0;
    int iRev=0, iDigit=0;
    int iTemp=iNo;

    if(iNo<0)
    {
        iNo=-iNo;
    }
    while(iNo!=0)
    {
        iDigit=iNo%10;
        iRev=(iRev*10)+iDigit;
        iNo=iNo/10;
    }
    return iRev;
}

    int ChkPalindrome(int iData)
    {
        int iReverse;
        iReverse=Reverse(iData);
        return iReverse;
    }

     
int main()
{
    int iValue=0;
    int bRet=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    bRet=ChkPalindrome(iValue);

    if(bRet==iValue)
        {
            printf(" %d is a palindrome Number \n",iValue);
        }
   else
        {
            printf(" %d is a not palindrome Number \n",iValue);
        }

    return 0;
}