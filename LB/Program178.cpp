#include<iostream>
using namespace std;

class DigitX
{
    public:
        int iNo;
        DigitX()
        {
            iNo=0;
        }
        DigitX(int i)
        {
            iNo=i;
        }
        int SumDigit()
        {
            int iDigit=0,iSum=0;
            int itemp=iNo;

            while(itemp!=0)
            {
                iDigit=itemp%10;
                if(iDigit%2==0)
                {
                    iSum=iSum+iDigit;
                }
                itemp=itemp/10;
            }
            return iSum;

        }

};
int main()
{
    int iValue=0,iRet=0;

    cout<<"Enter the Number:"<<"\n";
    cin>>iValue;

    DigitX obj(iValue);

    iRet=obj.SumDigit();

    cout<<"sum of digits is:"<<iRet<<"\n";

    cout<<obj.iNo;

    return 0;
}