#include<stdio.h>
void Display(int Brr[],int iSize)
{
    int iCnt=0;

    while(iCnt!=iSize)
    {
        printf("%d\n",Brr[iCnt]);
        iCnt++;
    }
}
int main()
{
    int Arr[5]={10,20,30,40,50};

    Display(Arr,5);
    return 0;
}