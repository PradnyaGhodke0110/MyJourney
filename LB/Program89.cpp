/*
row=4
col=4

1 2 3 4
1 2 3 4 
1 2 3 4 
1 2 3 4

*/
#include<iostream>
using namespace std;
void Display(int iRows,int iCols)
{
    int i=0,j=0;

    for(i=1;i<=iRows;i++)
    {
        for(j=1;j<=iCols;j++)
        {
            cout<<j<<" ";
            
        }
        cout<<endl;
    }
}
int main()
{
    int iValue1=0,iValue2=0;
    

    cout<<"Enter the no.of Rows:\n";
    cin>>iValue1;
    cout<<"Enter the no.of columns:\n";
    cin>>iValue2;
    
    Display(iValue1,iValue2);

    return 0;
}