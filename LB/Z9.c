#include<stdio.h>
#include<stdlib.h>
int CheckOccurence(int arr[],int size,int no)
{
    int icnt;

    for(icnt=0;icnt<size;icnt++)
    {
        if(arr[icnt] == no)
        {
            break;  
        }   
    }
    if(icnt==size)
    {
        return -1;
    }
    else
    {
        return icnt;
    }
}

int main()
{
    int i,length,iValue,bRet;
    int *ptr=NULL;

    printf("Enter the size of elements\n");
    scanf("%d\n",&length);

    ptr=(int *)malloc(length * sizeof(int));

    printf("Enter the elements you want in a array\n");
    for(i=0;i<length;i++)
    {
         scanf("%d\n",&ptr[i]);
    }

    printf("enter the element that you want to search");
    scanf("%d\n",&iValue);

    bRet=CheckOccurence(ptr,length,iValue);

    if(bRet==-1)
    {
        printf("Elements is not found in the array\n");
    }
    else
    {
        printf("%d is found at index %d\n",iValue,bRet);
    }
     return 0;
}