#include<stdio.h>

void DisplayReverse(int iNo)
{
   int  iCnt=0;

   /*printf("-------------------------------------\n");
   /* for(iCnt=iNo;iCnt>0;iCnt--)
    {
        printf("%d\t",iCnt);
    }
    printf("\n-----------------------------------\n");
*/
 iCnt=iNo;
 while(iCnt>0)
 {
    printf("%d\t",iCnt);
    iCnt--;
 }
 
}
int main()
{
    int iValue=0;

    printf("enter the number \n");
    scanf("%d" ,&iValue);

    DisplayReverse(iValue);

    return 0;
}