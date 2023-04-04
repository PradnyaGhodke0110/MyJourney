#include<iostream>
using namespace std;
template <class T>
T Display(T Arr[],int iSize)
{
    int iCnt=0;
    T Sum;

    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        Sum=Sum+Arr[iCnt];
        
    }
    return Sum; 
}
int main()
{
    int Data[]={10,20,30,40};
    int iRet=Display(Data,4);
    cout<<iRet;


    cout<<"\n";
    
    float Dataf[]={10.1f,11.1f,12.2f,13.3f};
    float fRet=Display(Dataf,4);
    cout<<fRet;
    
    return 0;
}