#include<stdio.h>
#include<stdbool.h>

bool IsPerfectR(int iNo)
{
    static int sum=0;
    static int iCnt=1;
    if(iCnt<=(iNo/2))
    {
        if(iNo%iCnt==0)
        {
            
            sum=sum+iCnt;
            
        }
        iCnt++;
        IsPerfectR(iNo);
    }
    if(sum==iNo)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int iValue=0;
    bool bRet=false;

    printf("Enter Number:\n");
    scanf("%d",&iValue);

    bRet=IsPerfectR(iValue);

    if(bRet==true)
    {
        printf("No.is Perfect\n");
    }
    else
    {
        printf("No.is not perfect\n");

    }
    return 0;
}