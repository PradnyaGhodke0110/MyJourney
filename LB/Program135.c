#include<stdio.h>

void strupprX(char *str)
{
    while(*str!='\0')
    {
        if((*str>='a')&&(*str<='z'))
        {
            *str=*str-32;
        }
        str++;
    }

}
int main()
{
    char Arr[20];
    

    printf("please enter string\n");
    scanf("%[^'\n']s",Arr);
    
    strupprX(Arr);

    printf("string after conversion is:%s\n",Arr);


    return 0;
}