#include<stdio.h>

int WhiteSpaceCount(char *str)
{ 
    int iCnt=0;

    while(*str!='\0')
    {
        if(*str==' ')
        {
            iCnt++;
        }
        str++;
    }
    return iCnt;

}
int main()
{
    char Arr[20];
    int iRet=0;
    

    printf("please enter string\n");
    scanf("%[^'\n']s",Arr);
    
    iRet=WhiteSpaceCount(Arr);

    printf("string after conversion is:%d\n",iRet);


    return 0;
}