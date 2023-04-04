#include<stdio.h>
#include<stdlib.h>
int Summation(int Arr[],int iSize)
{
    int iCnt=0,iSum=0;
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        iSum=iSum+Arr[iCnt];
    }
    return iSum;

}
int main()
{
    int Arr[5];
    int iCnt=0 ,iRet=0, iLength=0;
    int *ptr=NULL;

    printf("Enter the Elements you want to store:\n");
    scanf("%d",&iLength);
    
    ptr=(int *)malloc(iLength*sizeof(int));

    for(iCnt=0;iCnt<iLength;iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    iRet=Summation(Arr,iLength);
    printf("summation of all elements is:%d\n",iRet);
    free(ptr);
    
    return 0;

}