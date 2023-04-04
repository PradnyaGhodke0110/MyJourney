#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    
    struct node *next;
    struct node *prev;

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node  ** PPNODE;

class DoublyLL
{
    public:

    int data;
    PNODE First;
    int iCount;

    DoublyLL();

    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void Display();
    void InsertAtPos(int iNo,int iPos);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};
DoublyLL::DoublyLL()
{
    iCount=0;
    First=NULL;

}

void DoublyLL::InsertFirst(int iNo)
{
    PNODE newn=new NODE;

    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if(First==NULL)
    {
        First=newn;
    }
    else
    {
        newn->next=First;
        First->prev=newn;
        First=newn;
        iCount++;
    }


}
void DoublyLL::InsertLast(int iNo)
{
    PNODE newn=new NODE;

    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    PNODE temp=First;


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
        newn->prev=temp;
        iCount++;

       
    }

}
void DoublyLL:: Display()
{
    cout<<"Elements of linked list are:"<<endl;
    cout<<"NULL"<<endl;

    PNODE temp=First;
    
    while(temp!=NULL)
    {
        cout<<"<=|"<<temp->data<<"|=>"<<endl;
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
/*int Count()
{
    int iCnt=0;

    while(First!=NULL)
    {
        iCnt++;
        First=First->next;
    }
    return iCnt++;
}*/

void DoublyLL::InsertAtPos(int iNo,int iPos)
{

    

    PNODE newn=new NODE;
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    PNODE temp=First;

    if(iPos<1 && iPos>iCount+1)
    {
        cout<<"Invalid Position:"<<endl;
        return;
    }
    else if(iPos==1)
    {
        InsertFirst(iNo);
    }
    
    else if(iPos==iCount+1)
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
        temp->next->prev=newn;
        newn->prev=temp;
        iCount++;
    }

}
void DoublyLL:: DeleteFirst()
{
    PNODE temp=First;
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete First;
        First==NULL;
        iCount--;
    }
    else
    {
        First=First->next;
        delete temp;
        First->prev=NULL;
        iCount--;
    }
}

void DoublyLL:: DeleteLast()
{
    PNODE temp=First;
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete First;
        First==NULL;
        
    }
    delete temp->next;
    temp->next==NULL;
    iCount--;
    

}
void DoublyLL:: DeleteAtPos(int iPos)
{
    PNODE temp1=First;
    PNODE temp2=NULL;

   

    if(iPos<1 && iPos>iCount)
    {
        cout<<"Invalid Position:"<<endl;
        return;
    }
    if(iPos==1)
    {
        DeleteFirst();
    }
    
    else if(iPos==iCount)
    {
        DeleteLast();
    }
    else
    {
        for(int i=1;i<iPos-1;i++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        temp2->next->prev=temp1;
        delete temp2;
        iCount--;

       

    }


    

}


int main()
{
    DoublyLL obj;

    

    obj.InsertFirst(51);
    obj.Display();

    obj.InsertFirst(21);
    obj.Display();

    obj.InsertFirst(11);
    obj.Display();

    obj.InsertLast(101);
    obj.Display();

    obj.InsertLast(111);
    obj.Display();

    obj.InsertLast(121);
    obj.Display();
    cout<<"Number of elelemnts are :"<<obj.iCount<<endl;

    obj.InsertAtPos(105,5);
    obj.Display();

    obj.DeleteAtPos(5);
    obj.Display();

    obj. DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    cout<<"Number of elelemnts are :"<<obj.iCount<<endl;

    return 0;


}