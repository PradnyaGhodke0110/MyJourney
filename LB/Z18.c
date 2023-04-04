#include<stdio.h>

void Display()
{
     static int icnt=1;

    if(icnt<4)
    {
        printf("*\t");
        icnt++;
        Display();
    }

}

int main()
{
    Display();
    return 0;
}