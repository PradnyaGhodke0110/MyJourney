/*Input:751
output:3

Input:7515
Output:4*/

#include<stdio.h>
int Reverse(int iNo)
{   
  //  int iDigit=0;
    int iRev=0, iDigit=0;
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
int main()
{
    int iValue=0;
    int iRet=0;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    iRet=Reverse(iValue);

   printf("Number of digits are:%d\n",iRet);

    return 0;
}