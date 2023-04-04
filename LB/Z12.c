#include<stdio.h>
#include<stdlib.h>

#pragma stack(1)
struct node
{
    int data;
    struct node * next;
    struct node * prev;
};

typedef struct node  NODE;
typedef struct node *  PNODE;
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
    else if((*First)->next==NULL)
    {
        ((*First)->next)=newn;
        newn->prev=*First;
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
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        (*First)==NULL;
    }
    else
    {
        PNODE temp=(*First);
        (*First)=((temp->next));
        free(temp);
        (*First)->prev=NULL;

    }
}
void DeleteLast(PPNODE First)
{
    if(*First==NULL)
    {
        return;
    }
    else if((*First)->next == NULL)
    {
        free(*First);
        (*First)==NULL;
    }
    else
    {
        PNODE temp=(*First);
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
    printf("Elements of linked list are:\n");
    while(First != NULL)
    {
        printf("|%d|->\t",First->data);
        First=First->next;
    }
    printf("NULL\n");
}

int count(PNODE First)
{
    int icnt=0;
    //printf("Elements of linked list are:\n");
    while(First != NULL)
    {
       // printf("|%d|->\t",First->data);

       icnt++;
        First=First->next;
    }
    return icnt;
    //printf("NULL\n");
}

int main()
{
    PNODE Head=NULL;
    int iRet=0;

    InsertFirst(&Head,50);
    InsertFirst(&Head,30);
    InsertFirst(&Head,10);

    iRet=count(Head);
    printf("No of nodes are %d:\n",iRet);
    Display(Head);

    InsertLast(&Head,100);
    InsertLast(&Head,150);
    InsertLast(&Head,200);

    iRet=count(Head);
    printf("No of nodes are %d:\n",iRet);
    Display(Head);

    DeleteFirst(&Head);
    iRet=count(Head);
    printf("No of nodes are %d:\n",iRet);
    Display(Head);

    DeleteLast(&Head);
    iRet=count(Head);
    printf("No of nodes are %d:\n",iRet);
    Display(Head);


    return 0;
}
