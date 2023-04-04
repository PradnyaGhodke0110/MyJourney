/*Input:751
output:3

Input:7515
Output:4*/

#include<stdio.h>
int CountDigits(int iNo)
{   
    int iDigit=0;
    int iCnt=0;

    if(iNo==0)//Filter
    {
        return 1;
    }

    if(iNo<0) //updater
    {
        iNo=-iNo;
    }

    while(iNo!=0)
    {
        iDigit=iNo%10;
        iNo=iNo/10;
        iCnt++;
        

    }
    return iCnt;
   // return 0;
}
int main()
{
    int iValue=0;
    int iRet=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    iRet=CountDigits(iValue);

    printf("Number of digits are:%d\n",iRet);

    return 0;
}