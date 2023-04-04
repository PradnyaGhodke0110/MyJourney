

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
        void Function()
        {
            
        }

};

int main()
{
    int iValue=0;

    cout<<"Enter Number:\n";
    cin>>iValue;

    Numbers obj(iValue);
    obj.Function();

    return 0;
}
