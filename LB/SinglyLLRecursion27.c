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
int main()
{
    PNODE Head=NULL;
    int iRet=0;

    
    InsertLast(&Head,101);
    InsertLast(&Head,121);
    InsertLast(&Head,131);

    Display(Head);

    iRet=Count(Head);
    printf("Count of linked list elements is:%d\n",iRet);

    
   return 0;
}