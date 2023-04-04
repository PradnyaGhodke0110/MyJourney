#include<stdio.h>
int DisplayNonFactors(int iValue)
{
    int iSum=0,iCnt=0;
    for(iCnt=1;iCnt<iValue;iCnt++)
    {
        if((iValue%iCnt)!=0)
        {
            printf("Non factors numbers are %d : \n",iCnt);
        }
    }

}
int main()
{
    int iNo=0;

    printf("enter number: \n");
    scanf("%d \n",&iNo);

    DisplayNonFactors(iNo);
    return 0;
}