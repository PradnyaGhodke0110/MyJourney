/*Input:751
output:3

Input:7515
Output:4*/

#include<stdio.h>
int CountEvenDigits(int iNo)
{   
  //  int iDigit=0;
    int iSum=0;
    int iDigit=0;
    int iCnt=0;
     

    if(iNo==0)
    {
        return 1;
    }
    // without updater we can use negative number//

    if(iNo<0)//updater
    {
        iNo=-iNo;
    }

    while(iNo!=0)
    {
        iDigit=iNo%10;
        if((iDigit%2)==0)
        {
            iCnt++;
        }
        iNo/=10;
    }
    return iCnt;
   
}
int main()
{
    int iValue=0;
    int iRet=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    iRet=CountEvenDigits(iValue);

    printf("Number of digits are:%d\n",iRet);

    return 0;
}