#include<iostream>
using namespace std;

#pragma pack(1)
template <class T>
struct node
{
    T data;
    struct node *prev;
    struct node *next;

};
template <class T>
class DoublyLL
{
    public:
    struct node<T> * First;

    DoublyLL();
    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void Display();
    int Count();
    void InsertAtPos(T data,int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);


};

template <class T>
DoublyLL <T>::DoublyLL()
{
    First=NULL;
}
template <class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
    struct node<T> * newn=new struct node<T>;

    newn->data=iNo;
    newn->prev=NULL;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        newn->next=First;
        First->prev=newn;
        First=newn;
    }

}
template <class T>
void DoublyLL<T>::InsertLast(T iNo)
{
    struct node<T> * newn=new struct node<T>;

    newn->data=iNo;
    newn->prev=NULL;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        struct node<T> * temp=First;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }

}



template <class T>
void DoublyLL<T>::Display()
{
    struct node<T> * temp=First;

    cout<<"Elements of linked list are:"<<"\n";
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|=>";
        temp=temp->next;
    }
    cout<<"\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    struct node<T> * temp=First;
    int iCnt=0;

    cout<<"Elements of linked list are:"<<"\n";
    while(temp!=NULL)
    {
        iCnt++;
        temp=temp->next;
    }
    return iCnt;
}
template <class T>
void DoublyLL<T>::InsertAtPos(T iNo,int iPos)
{
    struct node<T> * newn=new struct node<T>;

    newn->data=iNo;
    newn->prev=NULL;
    newn->next=NULL;

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
        struct node<T> * temp=First;

        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        newn->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;
    }

}
template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First==NULL)
    {
        cout<<"linked list is empty"<<"\n";
        return;
    }
    else if(First->next==NULL)
    {
        delete (First);
        First=NULL;
    }
    else
    {
        First=First->next;
        delete (First->prev);
        First->prev=NULL;
    }
}
template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(First==NULL)
    {
        cout<<"linked list is empty"<<"\n";
        return;
    }
    else if(First->next==NULL)
    {
        delete (First);
        First=NULL;
    }
    else
    {
        struct node<T> *temp=First;

        while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
        delete temp->next;
        temp->next=NULL;
        
    }
}
template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    
    int iNodeCnt=Count();

    if(iPos<1 || iPos>iNodeCnt+1)
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iNodeCnt+1)
    {
        DeleteLast();
    }
    else
    {
        struct node<T> * temp=First;
        struct node<T> * temp2=NULL;


        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        temp2=temp->next;
        temp->next=temp->next->next;
        temp->next->next->prev=temp;
        free(temp2);

    }
}



int main()
{
    
    DoublyLL <char>cobj;
    int iRet=0;
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

     //// ///////////////////////////////////////////////////////////////////////
    
    cout<<"Float Linked List:"<<"\n"<<"\n";
    
    DoublyLL <float>fobj;

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

    DoublyLL <double>dobj;

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

    DoublyLL<int> iObj;
    
    iObj.InsertFirst(31);
    iObj.InsertFirst(21);
    iObj.InsertFirst(11);

    iObj.InsertLast(111);
    iObj.InsertLast(121);
    iObj.InsertLast(131);
    
    
    iObj.Display();
    iRet=iObj.Count();
    cout<<"count of nodes are:"<<iRet<<"\n";

    iObj.InsertAtPos(105,5);
    iObj.Display();
    iRet=iObj.Count();
    cout<<"count of nodes are:"<<iRet<<"\n";

    iObj.DeleteAtPos(5);
    iObj.Display();
    iRet=iObj.Count();
    cout<<"count of nodes are:"<<iRet<<"\n";


    iObj.DeleteFirst();
    iObj.DeleteLast();
    iObj.Display();
    iRet=iObj.Count();
    cout<<"count of nodes are:"<<iRet<<"\n";

    return 0;
}

