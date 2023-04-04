#include<stdio.h>
#include<stdlib.h>

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

void InsertFirst(PPNODE First,int iNo)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));

    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if(*First==NULL)
    {
        *First=newn;
    }
    else
    {
        newn->next=*First;
        (*First)->prev=newn;
        *First=newn;
    }


}
void InsertLast(PPNODE First,int iNo)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));

    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

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
        newn->prev=temp;

       
    }

}
void Display(PNODE First)
{
    printf("Elements of linked list are:\n");
    printf("NULL ");
    
    while(First!=NULL)
    {
        printf("<=|%d|=>",First->data);
        First=First->next;
    }
    printf("NULL\n");
}
int Count(PNODE First)
{
    int iCnt=0;

    while(First!=NULL)
    {
        iCnt++;
        First=First->next;
    }
    return iCnt++;
}

void InsertAtPos(PPNODE First,int iNo,int iPos)
{

    int iNodeCnt=Count(*First);

    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    PNODE temp=*First;

    if(iPos<1 && iPos>iNodeCnt+1)
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
        for(int i=1;i<iPos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        newn->prev=temp;
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
        *First==NULL;
    }
    else
    {
        *First=(*First)->next;
        free(temp);
        (*First)->prev=NULL;
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
        *First==NULL;
    }
    free(temp->next);
    temp->next==NULL;
    

}
void DeleteAtPos(PPNODE First,int iPos)
{

    int iNodeCnt=Count(*First);

   
    PNODE temp1=*First;
    PNODE temp2=NULL;

   

    if(iPos<1 && iPos>iNodeCnt)
    {
        printf("Invalid Position:\n");
        return;
    }
    if(iPos==1)
    {
        DeleteFirst(First);
    }
    
    else if(iPos==iNodeCnt)
    {
        DeleteLast(First);
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
        free(temp2);
    }

}


int main()
{
    PNODE Head=NULL;

    int iRet = 0;

    InsertFirst(&Head,51);
    Display(Head);

    InsertFirst(&Head,21);
    Display(Head);

    InsertFirst(&Head,11);
    Display(Head);

    InsertLast(&Head,101);
    Display(Head);

    InsertLast(&Head,111);
    Display(Head);

    InsertLast(&Head,121);
    Display(Head);

    iRet = Count(Head);
    printf("Number of elelemnts are : %d\n",iRet);

    InsertAtPos(&Head,105,5);
    Display(Head);

    DeleteAtPos(&Head,5);
    Display(Head);

    DeleteFirst(&Head);
    DeleteLast(&Head);

    Display(Head);

    iRet = Count(Head);
    printf("Number of elelemnts are : %d\n",iRet);
    
    return 0;


}