#include<iostream>
using namespace std;
//call by reference
template <class T>
void Swap(T &x,T &y)

{
    T temp;

    temp=x;
    x=y;
    y=temp;

}

int main()
{
    int a=11,b=10;

    cout<<"Value of a"<<a<<"\n";
    cout<<"Value of b"<<b<<"\n";

    Swap(a,b);

    cout<<"Value of a"<<a<<"\n";
    cout<<"Value of b"<<b<<"\n";

    double x=11.9,y=10.1;

    cout<<"Value of x"<<x<<"\n";
    cout<<"Value of y"<<y<<"\n";

    Swap(x,y);

    cout<<"Value of x"<<x<<"\n";
    cout<<"Value of y"<<y<<"\n";


    return 0;
}