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
    char iValue='\0';

    printf("enter string:\n");
    scanf("%[^'\n']s",Arr);

    printf("enter the character you want check:\n");
    scanf("%c",&iValue);
    

    iRet=CountChar(Arr,iValue);

    printf("Frequency of characters is:%d\n",iRet);
    return 0;
}