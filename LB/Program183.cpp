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
        int iCount=0;


        SinglyLL();

        void InsertFirst(int no);
        void InsertLast(int no);
        void InsertAtPosition(int no,int ipos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPosition(int ipos);
        
        void Display();
       // int Count();
};
/*returntype classname::functionname(return value)
{

}*/
SinglyLL::SinglyLL()
{
    First=NULL;

}
void SinglyLL::InsertFirst(int no)
{
   PNODE newn=new NODE;

   newn->data=no;
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
void SinglyLL::InsertLast(int no)
{
    PNODE newn=new NODE;

   newn->data=no;
   newn->next=NULL;

   if(First==NULL)
   {
    First=newn;
    iCount++;
   }
   else
   {
    PNODE temp=First;

    while(temp!=NULL)
    {
        temp=temp->next;

    }
    temp->next=newn;
    iCount++;
    
   } 


}
void SinglyLL::InsertAtPosition(int no,int pos)
{

}
void SinglyLL::DeleteFirst()
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
        temp->next = NULL;

        iCount--;
    
    }

}
void SinglyLL::DeleteAtPosition(int pos)
{

}
void SinglyLL::Display()
{
    cout<<"elememts of linked list are:"<<"\n";

    PNODE temp=First;
    while(temp!=NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp=temp->next;

    }
    cout<<"NULL"<<"\n";

}

int main()
{
    SinglyLL obj1;
    SinglyLL obj2;
    
    cout<<sizeof(obj1)<<"\n";
    cout<<"First pointer contains:"<<obj1.First<<"\n";
    
    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    cout<<"elemts of first linked list are:"<<"\n";

    obj1.Display();

    cout<<"Number of nodes are:"<<obj1.iCount<<"\n";
    
    obj1.InsertLast(101);
    obj1.InsertLast(111);
    obj1.InsertLast(121);
    obj1.Display();
    cout<<"Number of nodes in first linkedlist are : "<<obj1.iCount<<"\n";
    
    obj1.DeleteFirst();
    obj1.DeleteLast();

    obj1.Display();
    cout<<"Number of nodes in first linkedlist are : "<<obj1.iCount<<"\n";
   
    
    
    return 0;
}