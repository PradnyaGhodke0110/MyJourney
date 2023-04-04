#include<iostream>
using namespace std;

#pragma stack(1);
template <class T>
struct node
{
    T data;
     struct node *next;
    struct node *prev;

};
template <class T>
class DoublyCL
{
    public:
    struct node<T> * First;
    struct node<T> * Last;

    DoublyCL();
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
DoublyCL<T>::DoublyCL()
{
    First=NULL;
    Last=NULL;
}

template <class T>
void DoublyCL<T>::InsertFirst(T iNo)
{
    struct node<T> * newn=new struct node<T>;

    newn->data=iNo;
    newn->prev=NULL;
    newn->next=NULL;

    if(First==NULL && Last==NULL)
    {
        First=Last=newn;
    }
    else
    {
        newn->next=First;
        First->prev=newn;
        First=newn;
    }
    First->prev=Last;
    Last->next=newn;
}
template <class T>
void DoublyCL<T>::InsertLast(T iNo)
{
    struct node<T> * newn=new struct node<T>;

    newn->data=iNo;
    newn->prev=NULL;
    newn->next=NULL;

    if(First==NULL && Last==NULL)
    {
        First=Last=newn;
    }
    else
    {
        Last->next=newn;
        newn->prev=Last;
        Last=newn;
    }
    First->prev=Last;
    Last->next=First;
    
}
template <class T>
void DoublyCL<T>::Display()
{
    struct node<T> * temp=First;
    cout<<"Elements of Linked List are:"<<"\n";
    do
    {
        cout<<"|"<<temp->data<<"|->"<<" ";
        temp=temp->next;
    } while (temp!=Last->next);
    cout<<"NULL"<<"\n";
}
template <class T>
int DoublyCL<T>::Count()
{
    struct node<T> * temp=First;
    int iCnt=0;

    do
    {
         iCnt++;
        temp=temp->next;
    } while (temp!=Last->next);
    return iCnt;
}
template <class T>
void DoublyCL<T>::InsertAtPos(T iNo,int iPos)
{
    struct node<T> * newn=new struct node<T>;

    newn->data=iNo;
    newn->prev=NULL;
    newn->next=NULL;

    int iNodeCnt=Count();

    if(iPos<1 || iPos>iNodeCnt+1)
    {
        cout<<"Invalid Position"<<"\n";
        return ;
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
        temp->next->prev=newn;
        newn->prev=temp;
        temp->next=newn;
    }
    
}
template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First==NULL && Last==NULL)
    {
        cout<<"Linked list is Empty"<<"\n";
        return;
    }
    else if(First==Last)

    {delete First;
        First=Last=NULL;
    }
    else
    {
        First=First->next;
       delete Last->next; 
    }
    First->prev=Last;
    Last->next=First;
    
}
template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First==NULL && Last==NULL)
    {
        cout<<"Linked list is Empty"<<"\n";
        return;
    }
    else if(First==Last)

    {
        delete First;
        First=Last=NULL;
    }
    else
    {
        Last=Last->prev;
        delete (First)->prev;
    }
    First->prev=Last;
    Last->next=First;
    
}
template <class T>
void  DoublyCL<T>::DeleteAtPos(int ipos)
{
    int iNodeCnt = Count();
    struct node<T> * temp = NULL;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iNodeCnt))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(ipos ==1)
    {
        DeleteFirst();
    }
    else if(ipos == iNodeCnt)
    {
        DeleteLast();
    }
    else
    {
        temp = First;
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete (temp->next->prev);
        temp->next->prev = temp;
    }
}

int main()
{
    DoublyCL<int> iObj;
    int iRet=0;
    
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

    ///////////////////////////////////////////////////////

    cout<<"Double Linked list:"<<"\n"<<"\n";

    DoublyCL <double>dobj;

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

   //////////////////////////////////////////////////

   cout<<"Float Linked List:"<<"\n"<<"\n";
    
    DoublyCL <float>fobj;

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
   
    DoublyCL <char>cobj;
    
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
    

}
