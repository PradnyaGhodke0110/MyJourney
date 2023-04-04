#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class Queue
{
    public:

    struct node *First;
    int iCount;

    Queue();
    bool IsQueueEmpty();
    void EnQueue(int no);
    int DeQueue();
    void Display();
};
Queue::Queue()

{
    First=NULL;
    iCount=0;
}
bool Queue::IsQueueEmpty()
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
void Queue::EnQueue(int no)//InsertLast
{
    struct node *newn=new node;

    newn->data=no;
    newn->next=NULL;

    if(First==NULL)
    {
        First=newn;    
    }
    else
    {
        struct node * temp=First;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        
    }
    iCount++;

    //cout<<no<<"gets pushed in the stack successfully"<<"\n";

}
int  Queue::DeQueue()//DeleteFirst
{
    if(First==NULL)
    {
        cout<<"Unable to pop the element as stack empty."<<"\n";
        return -1;
    }
    else
    {
        int value=First->data;

        struct node *temp=First;

        First=First->next;
        delete temp;

        iCount--;
        return value;
    }
}

void Queue::Display()
{
    if(First==NULL)
    {
        cout<<"Stack is empty."<<"\n";
    }
    else
    {
        cout<<"Elements of stack are:"<<"\n";

        struct node *temp=First;
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
    Queue obj;

    obj.EnQueue(11);
    obj.EnQueue(21);
    obj.EnQueue(51);
    obj.EnQueue(101);

    obj.Display();

    int iret=obj.DeQueue();
    cout<<"Poped elements is:"<<iret<<"\n";

    iret=obj.DeQueue();
    cout<<"Poped elements is:"<<iret<<"\n";
    obj.Display();

    return 0;

}