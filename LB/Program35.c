#include<stdio.h>

void DisplayTable(int iValue)
{
    int iCnt=0;
    printf("_____________________________\n");
    printf("Table of %d is:\n",iValue);
    printf("_____________________________\n");

    for(iCnt=1;iCnt<=10;iCnt++)
    {
        printf("%d \n",iValue*iCnt);
    }
}
int main()
{
    int iNo=0;
    int iRet=0;

    printf("enter number: \n");
    scanf("%d \n",&iNo);

    DisplayTable(iNo);

    return 0;
}