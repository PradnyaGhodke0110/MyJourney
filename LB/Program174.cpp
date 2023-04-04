#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int * Arr;
        int iSize;

        ArrayX(int i)
        {
            cout<<"Allocating the memory to resources..."<<"\n";
            
            iSize=i;
            Arr=new int(iSize);//allocate memory to the array depend on size of elemnts
        }
        ~ArrayX()
        {
            cout<<"Deallocating the memory of resources..."<<"\n";
        
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
        int Minimum()
        {
            int iMin=Arr[0];

            for(int iCnt=0;iCnt<iSize;iCnt++)
            {
                if(Arr[iCnt]<iMin)
                {
                    iMin=Arr[iCnt];
                }
            }
            return iMin;
        }
};

int main()
{
    int iLength=0,iRet=0;

    cout<<"enter the size of array:"<<"\n";
    cin>>iLength;

    ArrayX  * obj=new ArrayX(iLength);// dynamic allocation of array
    
    obj->Accept();
    obj->Display();
    iRet=obj->Minimum();

    cout<<"Smallest elements is:"<<iRet<<"\n";

    delete(obj);
    
    return 0;
}
