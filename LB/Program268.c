#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Push(PPNODE First,int iNo)
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
int Pop(PPNODE First)
{
    int Value=(*First)->data;
    PNODE temp=*First;


    if(*First==NULL)
    {
        printf("Linked list is Empty\n");
        return -1;
    }
    else
    {
        
        
        (*First)=(*First)->next;
        free (temp);
    }
      return Value;
      

}
void Display(PNODE First)
{
    printf("Elements of stack are:\n");

    while(First!=NULL)
    {
        printf("|%d|\t",First->data);
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
bool IsStackEmpty(PNODE First)
{
    if(First==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    PNODE Head=NULL;
    int val=0,iRet=0;

    Push(&Head,31);
    Push(&Head,21);
    Push(&Head,11);
    Display(Head);
    iRet=Count(Head);
    printf("No.of Stack elements are:%d\n",iRet);
   

    val=Pop(&Head);
    printf("Poped elements is:%d\n",val);
    Display(Head);
    iRet=Count(Head);
    printf("No.of Stack elements are:%d\n",iRet);
   
    return 0;
}