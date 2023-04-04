#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
class Stack
{
    public:

    struct node<T> *First;
    int iCount;

    Stack();
    bool IsStackEmpty();
    void Push(T no);
    T Pop();
    void Display();
};
template <class T>

Stack<T>::Stack()
{
    First=NULL;
    iCount=0;
}
template <class T>

bool Stack<T>::IsStackEmpty()
{
    if(iCount==0)
    {
        return true;
    }
    else
    {
        return false;
    }

}
template <class T>

void Stack<T>::Push(T no)//InsertFirst
{
    struct node<T> *newn=new node<T>;

    newn->data=no;
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
    iCount++;

    cout<<no<<"gets pushed in the stack successfully"<<"\n";

}
template <class T>

T Stack<T>::Pop()//DeleteFirst
{
    if(First==NULL)
    {
        cout<<"Unable to pop the element as stack empty."<<"\n";
        return -1;
    }
    else
    {
        T value=First->data;

        struct node<T> *temp=First;

        First=First->next;
        delete temp;

        iCount--;
        return value;
    }
}

template <class T>
void Stack<T>::Display()
{
    if(First==NULL)
    {
        cout<<"Stack is empty."<<"\n";
    }
    else
    {
        cout<<"Elements of stack are:"<<"\n";

        struct node<T> *temp=First;
        while(temp != NULL)
        {
            cout<<"|"<<temp->data<<"|";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }

}

int main()
{
    Stack <int>iobj;

    iobj.Push(11);
    iobj.Push(21);
    iobj.Push(51);
    iobj.Push(101);

    iobj.Display();

    int iret=iobj.Pop();
    cout<<"Poped elements is:"<<iret<<"\n";

    iret=iobj.Pop();
    cout<<"Poped elements is:"<<iret<<"\n";
    iobj.Display();

    return 0;

}