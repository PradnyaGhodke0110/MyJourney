#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First,int No)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));

    newn->data=No;
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

void InsertLast(PPNODE First,int No)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    PNODE temp=*First;
    newn->data=No;
    newn->next=NULL;

    if(temp==NULL)
    {
        temp=newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
    }
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
        (*First)==NULL;
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
        (*First)==NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void Display(PNODE First)
{
    printf("Elements in linked list are:\n");
    while(First !=NULL)
    {
        printf("|%d|->",First->data);
        First=First->next;

    }
    printf("NULL\n");
}

int Count(PNODE First)
{
    int iCnt=0;
    //printf("Elements in linked list are:\n");
    while(First !=NULL)
    {
       // printf("|%d|->",First->data);

        iCnt++;
        First=First->next;

    }
    return iCnt;
}


void InsertAtPos(PPNODE First,int iNo,int iPos )
{
    
    int iNodeCnt=Count(*First);

    if(iPos<1 || iPos>iNodeCnt+1)
    {
        printf("Invalid Position:\n");
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
        int iCnt;

        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next=newn;
    }
}

void DeleteAtPos(PPNODE First,int iPos )
{
    
    int iNodeCnt=Count(*First);

    if(iPos<1 || iPos>iNodeCnt+1)
    {
        printf("Invalid Position:\n");
        return;   
    }
    else if(iPos==1)
    {
        DeleteFirst(First);
    }
    else if(iPos==iNodeCnt+1)
    {
        DeleteLast(First);
    }
    else
    {
        PNODE temp=*First;
        PNODE temp1=temp->next;
        
        int iCnt;

        for(iCnt=1;iCnt<iPos-1;iCnt++)
        {
            temp=temp->next;
        }

        temp1=temp->next;
        temp->next=temp->next->next;
        free(temp1);
    }
}





int main()
{
    PNODE Head=NULL;
    int iRet;

    InsertFirst(&Head,51);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);

    Display(Head);

    iRet=Count(Head);
    printf("No of Nodes are %d\n",iRet);

    InsertLast(&Head,101);
    InsertLast(&Head,121);
    InsertLast(&Head,151);

    Display(Head);
    iRet=Count(Head);
    printf("No of Nodes are %d\n",iRet);


    DeleteFirst(&Head);
    Display(Head);
    iRet=Count(Head);
    printf("No of Nodes are %d\n",iRet);

    DeleteLast(&Head);
    Display(Head);
    iRet=Count(Head);
    printf("No of Nodes are %d\n",iRet);

    
    InsertAtPos(&Head,123,4);
    Display(Head);
    iRet=Count(Head);
    printf("No of Nodes are %d\n",iRet);

    DeleteAtPos(&Head,4);
    Display(Head);
    iRet=Count(Head);
    printf("No of Nodes are %d\n",iRet);



    

    return 0;
}