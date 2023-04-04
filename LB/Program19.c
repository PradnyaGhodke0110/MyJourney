#include<stdio.h>
void Display(int iValue)

{
    for(int iCnt=1;iCnt<=iValue;iCnt++)
    {
        printf("number:%d\n",iCnt);
        
    }
}
int main()
{
    int iNo=0;
    printf("enter number:\n");
    scanf("%d",&iNo);
    Display(iNo);
    return 0;

}
