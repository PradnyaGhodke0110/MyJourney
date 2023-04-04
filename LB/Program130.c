#include<stdio.h>
#include<stdbool.h>
bool Check(char *str,char ch)
{   
    while(*str != '\0')
    {
        if(*str==ch)
        {
            
            break;
        }
        str++;
    }
    if(*str=='\0')
    {
        return false;
    }
    else
    {
        return true;
    }
    
    
}

int main()
{    
    char Arr[10];
    bool bRet=false;
    char iValue='\0';

    printf("enter string:\n");
    scanf("%[^'\n']s",Arr);

    printf("enter the character you want check:\n");
    scanf(" %c",&iValue);
    

    bRet=Check(Arr,iValue);

    if(bRet==true)
    {

    printf("Character is present\n");
    }
    else
    {
       printf("Character is not present\n");
    }
    return 0;
}