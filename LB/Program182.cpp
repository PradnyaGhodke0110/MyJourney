

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
    
    
   } 


}
void SinglyLL::InsertAtPosition(int no,int pos)
{

}
void SinglyLL::DeleteFirst()
{

}
void SinglyLL::DeleteLast()
{

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
    
    cout<<sizeof(obj1)<<"\n";
    cout<<"First pointer contains:"<<obj1.First<<"\n";
    
    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.Display();

    cout<<"Number of nodes are:"<<obj1.iCount<<"\n";

    /*obj1.InsertLast(51);
    obj1.InsertLast(21);
    obj1.InsertLast(11);

    obj1.Display();
    
    cout<<"Number of nodes are:"<<obj1.iCount<<"\n";*/

    
    
    
    
    return 0;
}