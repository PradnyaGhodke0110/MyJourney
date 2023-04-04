#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertLast(PPNODE First,int iNo)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));

    newn->data=iNo;
    newn->next=NULL;

    PNODE temp=*First;

    if(*First==NULL)
    {
        *First=newn;
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

void InsertFirst(PPNODE First,int iNo)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));

    newn->data=iNo;
    newn->next=NULL;

    if(*First==NULL)
    {
        *First=newn;
    }
    else
    {
        newn->next=*First;
        *First=newn;

    }
}
void Display(PNODE First)
{
    printf("elements of linked list are:");
        
    while(First!=NULL)
    {
        printf("|%d|->",First->data);
        First=First->next;
    }
    printf("NULL\n");
}
int Count(PNODE First)
{
    int iCnt=0;

    while(First->next!=NULL)
    {
        iCnt++;
        First=First->next;
    }
    return iCnt;

}




void DeleteFirst(PPNODE First)
{
    PNODE temp=*First;
    if(*First==NULL)
    {
        return;
    }
    else if((*First)->next==NULL)
    {
        free(*First);
        (*First)=NULL;

    }
    else
    {
        *First=(*First)->next;
        free(temp);
    }
}
void DeleteLast(PPNODE First)
{
    PNODE temp=*First;
    if(*First==NULL)
    {
        return;
    }
    else if((*First)->next==NULL)
    {
        free(*First);
        (*First)=NULL;
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
void InsertAtPos(PPNODE First,int iNo,int iPos)
{
    PNODE temp=NULL;
    int iNodeCnt=Count(*First);

    if((iPos<1) || (iPos>(iNodeCnt+1)))
    {
        printf("Invalid position");
        return;
    }
    else if(iPos==1)
    {
        InsertFirst(First,iNo);
    }
    else if(iPos==iNodeCnt+1)
    {
        InsertLast(First,iNo);

    }
    else
    {
        PNODE newn=(PNODE)malloc(sizeof(NODE));

        newn->data=iNo;
        newn->next=NULL;

         PNODE temp=*First;

        for(int iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;

    }
}
void DeleteAtPos(PPNODE First,int iPos)
{
    int NodeCnt=Count(*First);

    PNODE temp1=NULL;
    PNODE temp2=NULL;

    
    if((iPos<1) || (iPos>(NodeCnt+1)))
    {
        printf("Invalid Position");
        return;
    }
    else if(iPos==1)
    {
        DeleteFirst(First);
    }
    else if(iPos==NodeCnt+1)
    {
        DeleteLast(First);
    }
    else
    {
        temp1=*First;
       
        for(int iCnt=1;iCnt<iPos-1;iCnt++)
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
    PNODE Head=NULL;
    int iRet=0;

    InsertFirst(&Head,11);
    InsertFirst(&Head,21);
    InsertFirst(&Head,31);

    Display(Head);

    iRet=Count(Head);
    printf("Coutn of linked list elements is:%d\n",iRet);

    InsertLast(&Head,101);
    InsertLast(&Head,121);
    InsertLast(&Head,131);

    Display(Head);

    iRet=Count(Head);
    printf("Count of linked list elements is:%d\n",iRet);

    InsertAtPos(&Head,105,5);

    Display(Head);

    iRet=Count(Head);
    printf("Count of linked list elements is:%d\n",iRet);

    DeleteAtPos(&Head,5);

    Display(Head);

    iRet=Count(Head);
    printf("Count of linked list elements is:%d\n",iRet);


    DeleteFirst(&Head);
    DeleteLast(&Head);

    Display(Head);

    iRet=Count(Head);
    printf("Count of linked list elements is:%d\n",iRet);

}