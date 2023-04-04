#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void EnQueue(struct node ** First,int iNo)
{
    struct node *newn=(struct node *)malloc(sizeof(struct node));

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
void Display(struct node * First)
{
    printf("elements of  Queue are:\n");

    while(First!=NULL)
    {
        printf("|%d|\t",First->data);
        First=First->next;
    }
    printf("NULL\n");
}
int Count(struct node * First)
{
    int icnt=0;

    while(First!=NULL)
    {
        icnt++;
        First=First->next;
    }
    return icnt;
}
int DeQueue(struct node ** First)
{
    int Value=(*First)->data;
    struct node * temp=*First;


    if(*First==NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        *First=(*First)->next;
        free (temp);
    }
        return Value;
    
}
bool IsQueueEmpty(struct node *First)
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
    struct node *Head=NULL;
    int iRet=0;

    EnQueue(&Head,11);
    EnQueue(&Head,21);
    EnQueue(&Head,31);
    Display(Head);
    iRet=Count(Head);
    printf("Elements of Queue are:%d\n",iRet);

    int Val=DeQueue(&Head);
    printf("Poped elemnt is:%d\n",Val);
    Display(Head);
    iRet=Count(Head);
    printf("Elements of Queue are:%d\n",iRet);

    
    return 0;
}
