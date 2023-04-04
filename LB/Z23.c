#include<stdio.h>
#include<stdlib.h>

#pragma stack(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;

    
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First,PPNODE Last,int iNo)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if(*First==NULL && *Last==NULL)
    {
        (*First)=newn;
        (*Last)=newn;
    }
    else
    {
        newn->next=(*First);
        (*First)->prev=newn;
        (*First)=newn;
        
    }
    (*First)->prev=*Last;
    (*Last)->next=(*First);
}

void InsertLast(PPNODE First,PPNODE Last,int iNo)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    if(*First==NULL && *Last==NULL)
    {
        (*First)=newn;
        (*Last)=newn;
    }
    else
    {
        (*Last)->next=newn;
        newn->prev=(*Last);
        (*Last)=newn;
        
    }
    (*First)->prev=*Last;
    (*Last)->next=(*First);


    
}

void Display(PNODE First,PNODE Last)
{
    do
    {
        printf("|%d|=>",First->data);
        First=First->next;
    }while(First != Last->next);
    printf("NULL\n");
    
}

int Count(PNODE First,PNODE Last)
{
    int icnt=0;
    do
    {
        //printf("|%d|=>",First->data);
        icnt++;
        First=First->next;
    }while(First != Last->next);
    return icnt;
    
}

void DeleteFirst(PPNODE First,PPNODE Last)
{
    if(*First==NULL && *Last==NULL)
    {
        printf("elements are not present:\n");
        return;
    }
    else if(*First==*Last)
    {
        free(*First);
        (*First)==NULL;
        (*Last)==NULL;
    }
    else
    {
        (*First)=(*First)->next;
        free((*Last)->next);
    }
    (*First)->prev=*Last;
    (*Last)->next=(*First);


}

void DeleteLast(PPNODE First,PPNODE Last)
{
    if(*First==NULL && *Last==NULL)
    {
        printf("elements are not present:\n");
        return;
    }
    else if(*First==*Last)
    {
        free(*First);
        (*First)==NULL;
        (*Last)==NULL;
    }
    else
    {
        (*Last)=((*Last)->prev);
        free((*First)->prev);
    }
    (*First)->prev=*Last;
    (*Last)->next=(*First);


}
void InsertAtPos(PPNODE First,PPNODE Last,int iNo,int iPos)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;
    newn->prev=NULL;

    int NodeCnt=Count(*First,*Last);

    if(iPos<1 || iPos>NodeCnt+1)
    {
      printf("Invalid Position\n");
      return;  
    }
    if(iPos==1)
    {
        InsertFirst(First,Last,iNo);
    }
    else if(iPos==NodeCnt+1)
    {
        InsertLast(First,Last,iNo);
    }
    else
    {
        PNODE temp=(*First);
        for(int icnt=1;icnt<iPos;icnt++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        temp->next->prev=newn;
        temp->next=newn;
        newn->prev=temp;

    }


}
void DeleteAtPos(PPNODE First,PPNODE Last,int iPos)
{
    

    int NodeCnt=Count(*First,*Last);

    if(iPos<1 || iPos>NodeCnt+1)
    {
      printf("Invalid Position\n");
      return;  
    }
    if(iPos==1)
    {
        DeleteFirst(First,Last);
    }
    else if(iPos==NodeCnt)
    {
        DeleteLast(First,Last);
    }
    else
    {
        PNODE temp=(*First);
        PNODE temp1=NULL;
        for(int icnt=1;icnt<iPos-1;icnt++)
        {
            temp=temp->next;
        }
        
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;

    }


}

int main()
{
    PNODE Head=NULL;
    PNODE Tail=NULL;
    int iret=0;

    InsertFirst(&Head,&Tail,31);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);
    Display(Head,Tail);
    iret=Count(Head,Tail);
    printf("%d\n",iret);

    InsertLast(&Head,&Tail,111);
    InsertLast(&Head,&Tail,121);
    InsertLast(&Head,&Tail,131);
    Display(Head,Tail);
    iret=Count(Head,Tail);
    printf("%d\n",iret);

    DeleteFirst(&Head,&Tail);
    Display(Head,Tail);
    iret=Count(Head,Tail);
    printf("%d\n",iret);

    DeleteLast(&Head,&Tail);
    Display(Head,Tail);
    iret=Count(Head,Tail);
    printf("%d\n",iret);

    InsertAtPos(&Head,&Tail,105,5);
    Display(Head,Tail);
    iret=Count(Head,Tail);
    printf("%d\n",iret);

    DeleteAtPos(&Head,&Tail,5);
    Display(Head,Tail);
    iret=Count(Head,Tail);
    printf("%d\n",iret);


    return 0;
}

