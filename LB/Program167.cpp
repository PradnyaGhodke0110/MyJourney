#include<iostream>
using namespace std;

class Numbers
{      
    public:
        int iNo1;
        Numbers(int i)
        {
            iNo1=i;

        }
        int Factorial()
        {
            int iFact=1;
            int iCnt=0;
            for(iCnt=1;iCnt<=iNo1;iCnt++)
            {
                iFact=iFact*iCnt;
            }
            return iFact;
            
        }

};

int main()
{
    int iValue=0,iRet=0;

    cout<<"Enter Number:\n";
    cin>>iValue;

    Numbers obj(iValue);
    iRet= obj.Factorial();

    cout<<"Factorial is:"<<iRet;

    return 0;
}
