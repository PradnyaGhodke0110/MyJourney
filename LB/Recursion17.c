#include<stdio.h>

int CountSmallCharR(char *str)
{
    static int iCnt=0;
    if(*str != '\0')
    {
        if(*str>='a' && *str<='z')
        {
            iCnt++;
        }
           
    str++;
    CountSmallCharR(str);
    }
    
    return iCnt;
}
int main()
{
    char Arr[20];
    int iRet=0;
    printf("Enter string:\n");
    scanf("%[^'\n']s",Arr);

    iRet=CountSmallCharR(Arr);

    printf("small Char are:%d\n",iRet);
}