#include<stdio.h>
void DisplayR(int Brr[],int iSize)
{
   static int iCnt=0;

    if(iCnt!=iSize)
    {
        printf("%d\n",Brr[iCnt]);
        iCnt++;
        DisplayR(Brr,iSize);
    }
}
int main()
{
    int Arr[5]={10,20,30,40,50};

    DisplayR(Arr,5);
    return 0;
}