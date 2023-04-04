#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class SinglyLL
{
    public:
    struct node<T> * First;

    SinglyLL();
    void InsertFirst(T iNo);
    void Display();
    int Count();

};

template <class T>
SinglyLL<T>::SinglyLL()
{
    First=NULL;
}

template <class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
    struct node<T> * newn=new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        newn->next=First;
        First=newn;

    }
}
    
template <class T>
void SinglyLL<T>:: Display()
{
    struct node<T> * temp=First;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";

}

template <class T>
int SinglyLL<T>::Count()
{
    struct node<T> * temp=First;
    int iCnt=0;

    while(temp!=NULL)
    {
        iCnt++;
        temp=temp->next;
    }
    return iCnt;

}

int main()
{
    int iRet=0;
    
    SinglyLL <char>cobj;
    cobj.InsertFirst('a');
    cobj.InsertFirst('b');
    cobj.InsertFirst('c');
    cobj.InsertFirst('d');
    cobj.Display();
    iRet=cobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";
   
    SinglyLL <float>fobj;
    fobj.InsertFirst(41.1f);
    fobj.InsertFirst(31.2f);
    fobj.InsertFirst(21.4f);
    fobj.InsertFirst(11.5f);
    fobj.Display();
    iRet=fobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";
   
    SinglyLL <double>dobj;
    dobj.InsertFirst(41.10);
    dobj.InsertFirst(31.12);
    dobj.InsertFirst(21.22);
    dobj.InsertFirst(11.2);
    dobj.Display();
    iRet=dobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";
   
    SinglyLL <int>iobj;
    iobj.InsertFirst(41);
    iobj.InsertFirst(31);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);

    iobj.Display();
    iRet=iobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";
   
    
    return 0;
}