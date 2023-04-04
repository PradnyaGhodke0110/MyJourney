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


void DisplayR(PNODE First)
{
        
    if(First!=NULL)
    {
        printf("|%d|->",First->data);
        First=First->next;
        DisplayR(First);
    }
}
int CountR(PNODE First)
{
    static int iCnt=0;

    if(First!=NULL)
    {
        iCnt++;
        First=First->next;
        CountR(First);
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

    DisplayR(Head);

    iRet=CountR(Head);
    printf("\nCount of linked list elements is:%d\n",iRet);

    
   return 0;
}