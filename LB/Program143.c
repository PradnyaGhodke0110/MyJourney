#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};


int main()
{
    struct node *newn=(struct node *)malloc(sizeof(struct node));

    newn->data=11;
    newn->next=NULL;

    
    printf("%d\n",newn->data);//11
    printf("%d\n",sizeof(struct node));//8   struct node=data 4+next 4=8
    printf("%d\n",sizeof(newn));//4
   
    return 0;
}