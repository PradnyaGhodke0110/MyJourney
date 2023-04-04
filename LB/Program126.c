#include<stdio.h>
int CountChar(char *str,char ch)
{   int iCnt=0;
    while(*str != '\0')
    {
        if(*str==ch)
        {
            iCnt++;
        }
        str++;
    }
    return iCnt;
}

int main()
{    
    char Arr[10];
    int iRet=0;

    printf("enter string:\n");
    scanf("%[^'\n']s",Arr);
    

    iRet=CountChar(Arr,'a');

    printf("Frequency of characters is:%d\n",iRet);
    return 0;
}