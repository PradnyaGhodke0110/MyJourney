#include<stdio.h>

int CountCapitalCharR(char *str)
{
    static int iCnt=0;
    if(*str != '\0')
    {
        if(*str>='A' && *str<='Z')
        {
            iCnt++;
        }
           
    str++;
    CountCapitalCharR(str);
    }
    
    return iCnt;
}
int main()
{
    char Arr[20];
    int iRet=0;
    printf("Enter string:\n");
    scanf("%[^'\n']s",Arr);

    iRet=CountCapitalCharR(Arr);

    printf("Capital Char are:%d\n",iRet);
}