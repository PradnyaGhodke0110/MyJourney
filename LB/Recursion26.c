#include<stdio.h>
int DisplaySumR(int Brr[],int iSize)
{
   static int iCnt=0;
   static int iSum=0;


    if(iCnt!=iSize)
    {
        iSum=iSum+Brr[iCnt];
        iCnt++;
        DisplaySumR(Brr,iSize);
    }
    return iSum;
}
int main()
{
    int Arr[5]={10,20,30,40,50};
    int iRet=0;

    iRet=DisplaySumR(Arr,5);

    printf("Addition of array elemnts is:%d\n",iRet);
    return 0;
}