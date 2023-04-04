#include<iostream>
using namespace std;
template <class T>
void Display(T Arr[],int iSize)
{
    int iCnt=0;

    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        cout<<Arr[iCnt]<<" ";
    }
}
int main()
{
    int Data[]={10,20,30,40};

    Display(Data,4);

    cout<<"\n";

    char Datac[]={'a','b','c','d'};

    Display(Datac,4);
    
    
    return 0;
}