#include<stdio.h>
 void Display(int iValue)
{
    //int iCnt=0;
    for(int iCnt=0;iCnt<=iValue;iCnt++)
    {
        printf("Jay Ganesh...\n");
    }
}
int main()
{
    int iNo=0;
    printf("enter iterations\n");
    scanf("%d",&iNo);
   Display(iNo);
    return 0;
}
