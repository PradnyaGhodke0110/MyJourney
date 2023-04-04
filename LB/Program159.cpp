#include<iostream>
using namespace std;

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

class SinglyLL
{
    public:
    PNODE First;
    int iCount;

    SinglyLL();

    void InsertFirst(int iNo);
    void InsertLast(int iNo);
    void DeleteFirst();
    void DeleteLast();
    void InsertAtPos(int iNo,int iPos);
    void DeleteAtPos(int iPos);
    void Display();

};
SinglyLL::SinglyLL()
{
    First=NULL;
    iCount=0;
}
void SinglyLL::InsertLast(int iNo)
{
    PNODE newn=new NODE;

    newn->data=iNo;
    newn->next=NULL;

    
    if(First==NULL)
    {
        First=newn;
        iCount++;
    }
    else
    {
        PNODE temp=First;

        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        iCount++;
        
    }
}

void SinglyLL::InsertFirst(int iNo)
{
    PNODE newn=new NODE;

    newn->data=iNo;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;
        iCount++;
    }
    else
    {
        newn->next=First;
        First=newn;
        iCount++;

    }
}
void SinglyLL::Display()
{
    cout<<"elements of linked list are:"<<"\n";

    PNODE temp=First;
        
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|"<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";
}
/*int Count(PNODE First)
{
    int iCnt=0;

    while(First->next!=NULL)
    {
        iCnt++;
        First=First->next;
    }
    return iCnt;

}*/




void  SinglyLL:: DeleteFirst()
{
    if(First==NULL)
    {
        return;
    }
    else if((First)->next==NULL)
    {
        delete First;
        First=NULL;
        iCount--;

    }
    else
    {
        PNODE temp=First;
    
        First=First->next;
        delete temp;
        iCount--;
    }
}
void SinglyLL::DeleteLast()
{
    if(First==NULL)
    {
        return;
    }
    else if(First->next==NULL)
    {
        delete First;
        First=NULL;
        iCount--;
    }
    else
    {
        PNODE temp=First;
   
        while(temp->next->next!=NULL)
        {
            temp=temp->next;

        }
        delete temp->next;
        temp->next=NULL;
        iCount--;
    }
}
void SinglyLL:: InsertAtPos(int iNo,int iPos)
{
    

    if((iPos<1) || (iPos>(iCount+1)))
    {
        cout<<"Invalid position"<<"\n";
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
        PNODE newn=new NODE;

        newn->data=iNo;
        newn->next=NULL;
        PNODE temp=First;
    
        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
        iCount++;

    }
}
void SinglyLL::DeleteAtPos(int iPos)
{
    if((iPos<1) || (iPos>(iCount)))
    {
        cout<<"Invalid Position"<<"\n";
        return;
    }
    else if(iPos==1)
    {
        DeleteFirst();
    }
    else if(iPos==iCount)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp1=First;
       
        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp1=temp1->next;
        }
        PNODE temp2=temp1->next;
        temp1->next=temp1->next->next;
        delete temp2;
        iCount--;

    }


}


int main()
{
    SinglyLL obj;
    

    obj.InsertFirst(11);
    obj.InsertFirst(21);
    obj.InsertFirst(31);

    obj.Display();
    cout<<"Count of linked list elements is:\n"<<obj.iCount;

    obj.InsertLast(101);
    obj.InsertLast(121);
    obj.InsertLast(131);

    obj.Display();
    cout<<"Count of linked list elements is:\n"<<obj.iCount;


    
    obj.InsertAtPos(105,5);

    obj. Display();
    cout<<"Count of linked list elements is:\n"<<obj.iCount;

    obj.DeleteAtPos(5);

    obj.Display();
    cout<<"Count of linked list elements is:\n"<<obj.iCount;

    obj.DeleteFirst();
    obj.DeleteLast();

    obj.Display();
    cout<<"Count of linked list elements is:\n"<<obj.iCount;

    

    return 0;
}