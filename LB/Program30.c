#include<stdio.h>

int DisplayFactorsSum(int iNo)
{
    int iCnt = 0;
    int iSum = 0;

// reduce the complexity of program.... because any no have the factors upto itss middle no..... example if no is 20 then factrs will upto 10 numbers  //

   // printf("Factors are: \n");

    for(iCnt=1;iCnt<=iNo/2;iCnt++)
    {
        if((iNo % iCnt)==0)
        {
            iSum = iSum + iCnt;
            //printf("%d \n",iSum);
        }
    }
    return iSum;

}

int main()
{
    int iValue=0;
    int iRet=0;

    printf("Enter number: \n");
    scanf("%d",&iValue);

   iRet= DisplayFactorsSum(iValue);

   printf(" sum of factors is:%d \n",iRet);

    return 0;
}