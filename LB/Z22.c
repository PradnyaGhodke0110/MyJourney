#include<stdio.h>
#include<stdlib.h>

#pragma stack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void InsertFirst(PPNODE First,PPNODE Last,int iNo)
{

    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;

    if(*First==NULL && *Last==NULL)
    {
        (*First)=(*Last)=newn;
        ((*Last)->next)=(*First);
    }
    
    else
    {
        newn->next=(*First);
        (*First)=newn;
        ((*Last)->next)=(*First);
    }

}

void InsertLast(PPNODE First,PPNODE Last,int iNo)
{

    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;

    if(*First==NULL && *Last==NULL)
    {
        (*First)=(*Last)=newn;
        ((*Last)->next)=(*First);
    }
    
    else
    {
        (*Last)->next=newn;
        (*Last)=newn;
        (*Last)->next=(*First);
    }

}

void Display(PNODE First,PNODE Last)
{
    printf("Elements of linked list are:\n ");
    do
    {
        printf("|%d|->",First->data);
        First=First->next;

    }while(First != Last->next);

    printf("NULL\n");
}

int Count(PNODE First,PNODE Last)
{
    //printf("Elements of linked list are:\n ");
   int icnt=0;
    do
    {
       // printf("%d",First->data);
       icnt++;
        First=First->next;

    }while(First != Last->next);

    return icnt;
}

void DeleteFirst(PPNODE First,PPNODE Last)
{
    if((*First==NULL) && (*Last=NULL))
    {
        printf("No elements:\n");
        return;
    }
    else if((*First)==(*Last))
    {
        free(*First);
        free(*Last);
        (*First)=NULL;
        (*Last)=NULL;
    
    }
    else
    {
        PNODE temp=(*First);
        (*First)=(*First)->next;
        free(temp);
        (*Last)->next=(*First);

    }
}

void DeleteLast(PPNODE First,PPNODE Last)
{
    if((*First==NULL) && (*Last=NULL))
    {
        printf("No elements:\n");
        return;
    }
    else if((*First)==(*Last))
    {
        free(*First);
        free(*Last);
        (*First)=NULL;
        (*Last)=NULL;
    
    }
    else
    {
        PNODE temp=(*First);

        while(temp->next != (*Last))
        {
            temp=temp->next;
        }
        (*Last)=temp;
        free(temp->next);
        (*Last)->next=(*First);
        
    }
}

void InsertAtPos(PPNODE First,PPNODE Last,int iNo,int iPos)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;

    int iNodeCnt=Count(*First,*Last);

     if(iPos<1 && iPos>iNodeCnt+1)
     {
        printf("Invalid Position\n");
        return;
     }
     if(iPos==1)
     {
        InsertFirst(First,Last,iNo);
     }
     else if(iPos=iNodeCnt+1)
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
        temp=newn;
     }
}


void DeleteAtPos(PPNODE First,PPNODE Last,int iPos)
{
   /* PNODE newn=(PNODE)malloc(sizeof(NODE));
    newn->data=iNo;
    newn->next=NULL;*/

    int iNodeCnt=Count(*First,*Last);

     if(iPos<1 && iPos>iNodeCnt+1)
     {
        printf("Invalid Position\n");
        return;
     }
     if(iPos==1)
     {
        DeleteFirst(First,Last);
     }
     else if(iPos=iNodeCnt+1)
     {
        DeleteLast(First,Last);
     }
     else
     {
        PNODE temp1=(*First);
        PNODE temp2=NULL;
        for(int icnt=1;icnt<iPos-1;icnt++)
        {
            temp1=temp1->next;

        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        free(temp2);
        }
}


int main()
{
    PNODE Head=NULL;
    PNODE Tail=NULL;
    int iRet=0;

    InsertFirst(&Head,&Tail,31);
    InsertFirst(&Head,&Tail,21);
    InsertFirst(&Head,&Tail,11);
    Display(Head,Tail);
     iRet=Count(Head,Tail);
    printf("%d\n",iRet);

    InsertLast(&Head,&Tail,111);
    InsertLast(&Head,&Tail,121);
    InsertLast(&Head,&Tail,131);
    Display(Head,Tail);
    iRet=Count(Head,Tail);
    printf("%d\n",iRet);

    DeleteFirst(&Head,&Tail);
    Display(Head,Tail);
    
    DeleteLast(&Head,&Tail);
    Display(Head,Tail);

    InsertAtPos(&Head,&Tail,105,5);
    Display(Head,Tail);

    DeleteAtPos(&Head,&Tail,5);
    Display(Head,Tail);
    
    
    return 0;
}