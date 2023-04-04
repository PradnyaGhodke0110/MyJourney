#include<stdio.h>

void Display(int n)
{
    static int iCnt=1;
    if(iCnt<n)
    {
        printf("*\t");
        iCnt++;
        Display(n);
    }

}
int main()
{
    int iValue;
    printf("Enter number\n");
    scanf("%d",&iValue);

    Display(iValue);
    return 0;
}