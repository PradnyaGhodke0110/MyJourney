#include<stdio.h>

void Display(int Arr[], int iSize)
{
    static int icnt=0;
    if(icnt<iSize)
    {
        printf("%d\t",Arr[icnt]);
        icnt++;
        Display(Arr,iSize);
    }
}



int main()
{
    int Arr[5]={10,20,30,40,50};

    Display(Arr,5);


    return 0;
}