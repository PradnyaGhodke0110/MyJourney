#include<stdio.h>

int CountR(int iNo)
{
    static int iCount=0;

    if(iNo!=0)
    {
    
    iCount++;
    iNo=iNo/10;
    CountR(iNo);

    }
    return iCount;

}
int main()
{

    int iNo,iRet;

    printf("enter number");
    scanf("%d\n",&iNo);

    iRet=CountR(iNo);

    printf("count of digit is:%d\n",iRet);

    return 0;


}