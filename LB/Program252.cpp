#include<iostream>
using namespace std;
template <class T>
T Maximum(T Arr[],int iSize)
{
    int iCnt=0;
    T Max=Arr[0];

    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        if(Arr[iCnt]>Max)
        {
            Max=Arr[iCnt];
        }
        
    }
    return Max; 
}
int main()
{
    int Data[]={10,5,30,40};
    int iRet=Maximum(Data,4);
    cout<<iRet;


    cout<<"\n";
    
    float Dataf[]={10.1f,11.1f,5.5f,13.3f};
    float fRet=Maximum(Dataf,4);
    cout<<fRet;
    
    return 0;
}