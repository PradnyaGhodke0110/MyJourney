#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int * Arr;
        int iSize;

        ArrayX(int i)
        {
            iSize=i;
            Arr=new int(iSize);//allocate memory to the array depend on size of elemnts
        }
        ~ArrayX()
        {
            delete []Arr;//disalloacte the  memory of array
        }
        void Accept()
        {
            cout<<"Enter the elements of Array:"<<"\n";

            for(int i=0;i<iSize;i++)
            {
                cin>>Arr[i];
            }
        }
        void  Display()
        {
            
            cout<<"Enter the elements of Array:"<<"\n";

            for(int i=0;i<iSize;i++)
            {
                cout<<Arr[i]<<"\t";
            }
            cout<<"\n";
        }
};

int main()
{
    ArrayX obj(5);
    obj.Accept();
    obj.Display();
    return 0;
}
