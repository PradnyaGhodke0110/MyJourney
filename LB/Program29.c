#include<stdio.h>

void DisplayFactors(int iNo)
{
    int iCnt=0;
   // int iFact=0;

// reduce the complexity of program.... because any no have the factors upto itss middle no..... example if no is 20 then factrs will upto 10 numbers  //

    printf("Factors are: \n");

    for(iCnt=1;iCnt<=iNo/2;iCnt++)
    {
        if((iNo % iCnt)==0)
        {
            printf("%d \n",iCnt);
        }
    }

}

int main()
{
    int iValue=0;

    printf("Enter number: \n");
    scanf("%d",&iValue);

    DisplayFactors(iValue);

    return 0;
}