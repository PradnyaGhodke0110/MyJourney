#include<iostream>
using namespace std;

#pragma pack(1)
template <class T>
struct node
{
    T data;
    struct node *next;
};
template <class T>
class SinglyCL
{
    public:
    struct node <T> * First;
    struct node <T> * Last;

    SinglyCL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void Display();
    int Count();
    void InsertAtPos(T iNo,int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL <T>::SinglyCL()
{
    First=NULL;
    Last=NULL;
}

template <class T>
void SinglyCL <T>::InsertFirst(T iNo)
{
    struct node <T> * newn=new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;
    

    if(First==NULL && Last==NULL)
    {
        First=Last=newn;
        Last->next=First;
    }
    else
    {
        newn->next=First;
        First=newn;
    }
    Last->next=First;
    

}
template <class T>
void SinglyCL <T>::InsertLast(T iNo)
{
    struct node <T> * newn=new struct node <T>;
    newn->data=iNo;
    newn->next=NULL;
    

    if(First==NULL && Last==NULL)
    {
        First=Last=newn;
        Last->next=First;
    }
    else
    {
        Last->next=newn;
        Last=newn;
    }
    Last->next=First;
    

}
template <class T>
void SinglyCL <T>::Display()
{
    cout<<"Elements of linked list are:"<<endl;
    struct node <T> * temp=First;
    do
        {
            cout<<"|"<<temp->data<<"|->"<<" ";
            temp=temp->next;
        }while(temp!=Last->next);
        
        cout<<"NULL\n";
    
    
}

template <class T>
int SinglyCL <T>::Count()
{
    int iCnt=0;
    struct node <T> * temp=First;
    
        do
        {
            iCnt++;
            temp=temp->next;
        }while(temp!=Last->next);
        return iCnt;
    
    
}

template <class T>
void SinglyCL <T>::InsertAtPos(T iNo,int iPos)
{
    struct node <T> * newn=new struct node<T>;
    newn->data=iNo;
    newn->next=NULL;
    struct node<T> * temp=First;
    

    int iNodeCnt=Count();
    
    if(iPos<1 || iPos>iNodeCnt+1)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos==1)
    {
        InsertFirst(iNo);
    }
    else if(iPos==iNodeCnt+1)
    {
        InsertLast(iNo);
    }
    
    else
    {
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }


}
template <class T>
void SinglyCL <T>::DeleteFirst()
{
    if(First==NULL && Last==NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }
    
    else if(First==Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
        struct node <T> * temp=First; 
    
        
        First=First->next;
        
        delete temp;
        temp=NULL;
        
    }
    Last->next=First;

    
}
template <class T>
void SinglyCL <T>::DeleteLast()
{
    if(First==NULL && Last==NULL)
    {
        cout<<"Linked list is empty"<<"\n";
        return;
    }
    
    else if(First==Last)
    {
        delete First;
        First=NULL;
        Last=NULL;
    }
    else
    {
        struct node <T> * temp=First; 
    
        while(temp->next!=Last)
        {
            temp=temp->next;
        }
        delete temp->next;
        Last=temp;
    }
    
        Last->next=First;
    
    
}
template <class T>
void SinglyCL <T>::DeleteAtPos(int iPos)
{
    int iNodeCnt=Count();

    if(iPos<1 || iPos>iNodeCnt)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iNodeCnt)
    {
        DeleteLast();
    }
    
    else
    {
        struct node <T> * temp1=First;
        struct node <T>* temp2=NULL;

        for(int i=1;i<iPos-1;i++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        delete temp2;
        temp2=NULL;
    }
    
}
int main()
{
    int iRet=0;

    SinglyCL <int>iobj;
    

    iobj.InsertFirst(31);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);

    iobj.InsertLast(111);
    iobj.InsertLast(121);
    iobj.InsertLast(131);

    iobj.Display();
    iRet=iobj.Count();
    cout<<"Numbers of nodes are:"<<iRet<<"\n";
    
    iobj.InsertAtPos(155,5);
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

    ///////////////////////////////////////////////////////

    SinglyCL <char>cobj;
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
    
    SinglyCL <float>fobj;

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

    SinglyCL <double>dobj;

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

     return 0;
}


