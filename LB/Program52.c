/*Input:751
output:3

Input:7515
Output:4*/

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
    for(;iNo!=0;)// we can write for loop like this also------>for(iRev=0,iNo!=0;iNo=iNo/10)
    {
        iDigit=iNo%10;
        iRev=(iRev*10)+iDigit;
        iNo/=10;
    }
    if(iRev==iTemp)
    {
        return true;
    }
    else
    {
        return false;
    }
     
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