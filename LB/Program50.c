#include<stdio.h>
#include<stdbool.h>
int ChkPalindrome(int iNo)
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
    return iRev==iTemp;
     
}
int main()
{
    int iValue=0;
    bool bRet=false;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    bRet=ChkPalindrome(iValue);

    if(bRet==true)
        {
            printf(" %d is a palindrome Number \n",iValue);
        }
   else
        {
            printf(" %d is a not palindrome Number \n",iValue);
        }

    return 0;
}