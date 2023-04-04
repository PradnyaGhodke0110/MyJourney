#include<stdio.h>

void DisplayReverse(int iNo)
{
   int  iCnt=0;

   printf("-------------------------------------\n");
    for(iCnt=iNo;iCnt>0;iCnt--)
    {
        printf("%d\t",iCnt);
    }
    printf("\n-----------------------------------\n");

}
int main()
{
    int iValue=0;

    printf("enter the number \n");
    scanf("%d" ,&iValue);

    DisplayReverse(iValue);

    return 0;
}