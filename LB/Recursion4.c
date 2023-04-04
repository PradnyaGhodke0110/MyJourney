#include<stdio.h>
void DisplayR( )
{
    int iCnt=1;
    if(iCnt<=4)
    {
        printf("*\t");
        iCnt++;
        DisplayR();//Recursive call
    }

}

int main()
{
   printf("Inside main \n");

    DisplayR();

    printf("End of main\n");
    
    return 0;
}