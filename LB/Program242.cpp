#include<iostream>
using namespace std;

template <class T>
T Addition(T i,T j)
{
    T Ans;
    Ans=i+j;

    return Ans;
}
int main()
{
    double a=11.9,b=10.1,ret=0.0;

    ret=Addition(a,b);

    cout<<"Addition is:"<<ret<<"\n";

    return 0;
}