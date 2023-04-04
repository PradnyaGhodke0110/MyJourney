#include<stdio.h>

void Display(int n)
{
    int icnt=1;
    int isum=0;
    if(icnt<n)
    {
        icnt=icnt+isum;
        printf("%d\n",isum);
        icnt++;
        Display(n);
        
    }

}
int main()
{
    int num;
    printf("enter the number:\n");
    scanf("%d",&num);

    Display(num);
    return 0;
}