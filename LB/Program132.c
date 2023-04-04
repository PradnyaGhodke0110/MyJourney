#include<stdio.h>
char ToLower(char ch)
{
    if(ch>='A' && ch<='Z')
    {
        return ch+32;
    }
    else
    {
        return ch;
    }
}
int main()
{
  char cValue='\0';
  char cRet='\0';

  printf("enter the character\n");
  scanf("%c",&cValue);

  cRet=ToLower(cValue);

  printf("Character in the upper case is:%c\n",cRet);

  return 0;


}