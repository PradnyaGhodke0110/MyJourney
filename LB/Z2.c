#include<stdio.h>

void Display(char *str)

{
    while(*str != '\0')
    {
        str++;
        Display(str);
        printf("%c\n",*str);
        
    }

}
int main()
{
    char arr[100];

    printf("enter string:\n");
    scanf("%[^'\n']s",arr);

    Display(arr);
}