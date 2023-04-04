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
    void InsertLast(T iNo);
    void InsertAtPos(T iNo,int iPos);
    void Display();
    int Count();
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);


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
void SinglyLL<T>::InsertLast(T iNo)
{
    struct node<T> * newn=new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;
    struct node <T> * temp=First;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
       while(temp->next!=NULL)
       {
        temp=temp->next;
       }
       temp->next=newn;
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

template <class T>
void SinglyLL<T>::InsertAtPos(T iNo,int iPos)
{
    struct node<T> * newn=new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;
    struct node <T> * temp=First;
    int iNodeCnt=Count();

    if(iPos<1 && iPos>iNodeCnt+1)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    else if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==iNodeCnt+1)
    {
        InsertLast(iNo);
    }
    else
    {
        for(int i=0;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}
template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct node <T> * temp=First;

    if(First==NULL)
    {
        cout<<"Linked List is empty"<<"\n";
        return;
    }
    else if(First->next==NULL)
    {
        delete First;
        First=NULL;
    }
    else
    {
        First=First->next;
        delete temp;
    }
}
template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct node <T> * temp=First;

    if(First==NULL)
    {
        cout<<"Linked List is empty"<<"\n";
        return;
    }
    else if(First->next==NULL)
    {
        delete First;
        First=NULL;
    }
    else
    {
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}
template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    struct node <T> * temp1=First;
    struct node <T> * temp2=First;
    
    int iNodeCnt=Count();

    if(iPos<1 && iPos>iNodeCnt+1)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    else if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iNodeCnt+1)
    {
        DeleteLast();
    }
    else
    {
        for(int i=0;i<iPos-1;i++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp1->next->next;
        free(temp2);


    }
    
}
int main()
{
    int iRet=0;
    
    SinglyLL <char>cobj;
    cout<<"Chracter Linked List:"<<"\n"<<"\n";

    cobj.InsertFirst('d');
    cobj.InsertFirst('c');
    cobj.InsertFirst('b');
    cobj.InsertFirst('a');

    cobj.Display();
    iRet=cobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";

    cobj.InsertLast('u');
    cobj.InsertLast('v');
    cobj.InsertLast('x');
    cobj.InsertLast('z');

    cobj.Display();
    iRet=cobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";
   
    cobj.InsertAtPos('m',5);

    cobj.Display();
    iRet=cobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";

    cobj.DeleteAtPos(5);

    cobj.Display();
    iRet=cobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";

    cobj.DeleteFirst();
    cobj.DeleteLast();

    cobj.Display();
    iRet=cobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n"<<"\n";
   
   ////////////////////////////////////////////////////////////
   
    cout<<"Float Linked List:"<<"\n"<<"\n";
    
    SinglyLL <float>fobj;

    fobj.InsertFirst(41.1f);
    fobj.InsertFirst(31.2f);
    fobj.InsertFirst(21.4f);
    fobj.InsertFirst(11.5f);
    fobj.Display();
    iRet=fobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";

    fobj.InsertLast(61.2f);
    fobj.InsertLast(12.3f);
    fobj.InsertLast(13.1f);
    fobj.InsertLast(14.1f);

    fobj.Display();
    iRet=fobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";
   
    fobj.InsertAtPos(55.5f,5);

    fobj.Display();
    iRet=fobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";

    fobj.DeleteAtPos(5);

    fobj.Display();
    iRet=fobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";

    fobj.DeleteFirst();
    fobj.DeleteLast();

    fobj.Display();
    iRet=fobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n"<<"\n";

    ////////////////////////////////////////////////////////////////
   
    cout<<"Double Linked list:"<<"\n"<<"\n";

    SinglyLL <double>dobj;

    dobj.InsertFirst(41.10);
    dobj.InsertFirst(31.12);
    dobj.InsertFirst(21.22);
    dobj.InsertFirst(11.2);
    dobj.Display();
    iRet=dobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";

    dobj.InsertLast(11.10);
    dobj.InsertLast(12.11);
    dobj.InsertLast(13.21);
    dobj.InsertLast(14.41);

    dobj.Display();
    iRet=dobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";
   
    dobj.InsertAtPos(65.5,5);

    dobj.Display();
    iRet=dobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";

    dobj.DeleteAtPos(5);

    dobj.Display();
    iRet=dobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";

    dobj.DeleteFirst();
    dobj.DeleteLast();

    dobj.Display();
    iRet=dobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n"<<"\n";
   ///////////////////////////////////////////////////////////////////

    SinglyLL <int>iobj;

    cout<<"Integer Linked List:"<<"\n"<<"\n";

    iobj.InsertFirst(41);
    iobj.InsertFirst(31);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);

    iobj.Display();
    iRet=iobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";
    
    iobj.InsertLast(111);
    iobj.InsertLast(121);
    iobj.InsertLast(131);
    iobj.InsertLast(141);

    iobj.Display();
    iRet=iobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";
   
    iobj.InsertAtPos(105,5);

    iobj.Display();
    iRet=iobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";

    iobj.DeleteAtPos(5);

    iobj.Display();
    iRet=iobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";

    iobj.DeleteFirst();
    iobj.DeleteLast();

    iobj.Display();
    iRet=iobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n"<<"\n";
   
    return 0;
}