#include<iostream>
using namespace std;
//call by reference
void Swapi(int &x,int &y)

{
    int temp;

    temp=x;
    x=y;
    y=temp;

}
void Swapd(double &x,double &y)

{
    double temp;

    temp=x;
    x=y;
    y=temp;

}


int main()
{
    int a=11,b=10;

    cout<<"Value of a"<<a<<"\n";
    cout<<"Value of b"<<b<<"\n";

    Swapi(a,b);

    cout<<"Value of a"<<a<<"\n";
    cout<<"Value of b"<<b<<"\n";

    double x=11.9,y=10.1;

    cout<<"Value of x"<<x<<"\n";
    cout<<"Value of y"<<y<<"\n";

    Swapd(x,y);

    cout<<"Value of x"<<x<<"\n";
    cout<<"Value of y"<<y<<"\n";


    return 0;
}