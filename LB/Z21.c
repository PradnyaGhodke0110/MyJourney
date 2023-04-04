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
typedef struct node ** PPNODE;

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
        (*First)=newn;
    }
}

void InsertLast(PPNODE First,int iNo)
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
        PNODE temp=*First;

        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newn;
        newn->prev=temp;
    }
}

void DeleteFirst(PPNODE First)
{
    if(*First==NULL)
    {
        printf("Elements are not present\n");
        return;
    }
    if((*First)->next==NULL)
    {
        
         free(*First);
        (*First)==NULL;
        
    }
    else 
    {
        PNODE temp=(*First);
        (*First)=(*First)->next;
        free(temp);
        (*First)->prev=NULL;
    }
}

void DeleteLast(PPNODE First)
{
        
    if(*First==NULL)
    {
        printf("Elements are not present\n");
        return;
    }
    if((*First)->next==NULL)
    {
        
         free(*First);
        (*First)==NULL;
        
    }
    else 
    {
        PNODE temp=(*First);

        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}
 int Count(PNODE First)
    {
        int icnt=0;

        while(First != NULL)
        {
            icnt++;
            First=First->next;
        }
        return icnt;
    }


void InsertAtPos(PPNODE First,int iNo,int iPos)
{
    int iNodeCnt=Count(*First);
    PNODE newn=(PNODE)malloc(sizeof(NODE));

    if(iPos==-1 || iPos>iNodeCnt+1)
    {
        printf("element not present");
        return;
    }
    if(iPos==1)
    {
        InsertFirst(First,iNo);
        
    }
    else if(iPos==iNodeCnt+1)
    {
        InsertLast(First,iNo);
    }
    else
    {
        PNODE temp=*First;
        for(int icnt=1;icnt<iPos;icnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        newn->prev=temp;
        temp->next=newn;

    }

}

void DeleteAtPos(PPNODE First,int iPos)
{
    int iNodeCnt=Count(*First);
    
    if(iPos==-1 || iPos>iNodeCnt+1)
    {
        printf("element not present");
        return;
    }
    if(iPos==1)
    {
        DeleteFirst(First);
        
    }
    else if(iPos==iNodeCnt+1)
    {
        DeleteLast(First);
    }
    else
    {
        PNODE temp1=*First;
        PNODE temp2=NULL;
        for(int icnt=1;icnt<iPos-1;icnt++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        temp2->next->prev=temp1;
        free(temp2);

    }
}

void Display(PNODE First)
{
        printf("Elements of linked list are:\n");
        printf("NULL");

        while(First != NULL)
        {
            printf("<=|%d|=>",First->data);
            First=First->next;
        }
        printf("NULL\n");
}

   


int main()
{
    PNODE Head=NULL;
    int iret=0;

    InsertFirst(&Head,31);
    InsertFirst(&Head,21);
    InsertFirst(&Head,11);
    Display(Head);
    iret=Count(Head);
    printf("%d\n",iret);

    InsertLast(&Head,111);
    InsertLast(&Head,121);
    InsertLast(&Head,131);
    Display(Head);
    iret=Count(Head);
    printf("%d\n",iret);

    DeleteFirst(&Head);
    Display(Head);
    iret=Count(Head);
    printf("%d\n",iret);

    DeleteLast(&Head);
    Display(Head);
    iret=Count(Head);
    printf("%d\n",iret);

    InsertAtPos(&Head,105,5);
    Display(Head);
    

    DeleteAtPos(&Head,5);
    Display(Head);
    

    return 0;
}
