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
    return iCnt;
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

    iRet = Count(Head);
    printf("Number of elelemnts are : %d\n",iRet);

    return 0;



}