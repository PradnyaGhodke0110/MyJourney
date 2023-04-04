#include<stdio.h>

void strcpyCapX(char *src,char *dest)
{
    while(*src !='\0')
    {
        if(*src>='a' && *src<='z')
        {
            *dest=*src-32;
        }
        else
        {
            *dest=*src;
        }
         src++;
        dest++;
    
    }
    *dest='\0';
    

}
int main()
{
    char Arr[20];
    char Brr[20];
    
    printf("please enter string\n");
    scanf("%[^'\n']s",Arr);
    
    strcpyCapX(Arr,Brr);

    printf("copied string is:%s\n",Brr);
    printf("original string is:%s\n",Arr);
    
    
    return 0;
}