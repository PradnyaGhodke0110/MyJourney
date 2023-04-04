//accept no from user and check wheather it is perfect or not example 6 28 496\\

#include<stdio.h>
#include<stdbool.h>

bool CheckPerfect(int iNo)
{
    int iCnt = 0, iSum = 0;

   for(iCnt=1;iCnt<=iNo/2;iCnt++)
    {
        if((iNo % iCnt)==0)
        {
            
            iSum = iSum + iCnt;
            
        }
    }
    if(iSum==iNo)
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
    bool bRet;

    printf("Enter number: \n");
    scanf("%d",&iValue);

   bRet=CheckPerfect(iValue);

   if(bRet==true)
   {
        printf("%d is perfect number \n",iValue);
   }
   else
   {
        printf("%d is not a perfect number \n",iValue);
    }

      return 0;
}