#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void insertFirst(PPNODE first, PPNODE Last, int ino)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = ino;
    newn->next = NULL;

    if ((*first == NULL) && (*Last == NULL))
    { // empty LL
        *first = *Last = newn;
        (*Last)->next = *first;
    }
    else
    {
        newn->next = *first;
        *first = newn;
        (*Last)->next = *first;
    }
}

void insertLast(PPNODE first, PPNODE last, int ino)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));
    newn->data = ino;
    newn->next = NULL;

    if ((*first == NULL) && (*last == NULL))
    { // empty LL
        *first = *last = newn;
        (*last)->next = *first;
    }
    else
    {
        (*last)->next = newn;
        *last = newn;
        (*last)->next = *first;
    }
}
void display(PNODE first, PNODE Last)
{
    printf("Elements of LINKEd list :\n");

    do
    {
        printf("|%d|->", first->data);
        first = first->next;
    } while (first != Last->next);

    printf("\n");
}
int count(PNODE first, PNODE last)
{
}
int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    insertFirst(&head, &tail, 78);
    insertFirst(&head, &tail, 7);

    display(head, tail);

    insertLast(&head, &tail, 89);
    display(head, tail);
    return 0;
}