#include<stdio.h>
 void Display(int iValue)
{
    int iCnt=0;
    
    iCnt=1;
    while(iCnt<=iValue)
        {
            printf("Jay Ganesh..\n");
            iCnt++;

        }
}
int main()
{
    int iNo;
    printf("enter iterations\n");
    scanf("%d",&iNo);

    Display(iNo);
    return 0;
}
