#include<stdio.h>
#include<stdlib.h>

    int Summation(int ar[],int iSize)
    {
        int sum=0;

        for(int i=0;i<iSize;i++)
        {
            sum=sum+ar[i];
        }
        return sum;
    }

int main()
{
    int iRet=0;
    int *ptr=NULL;
    int length;

    printf("Enter the no. of elements that you want to store");
    scanf("%d",&length);

    ptr=(int *)malloc(length*sizeof(int));

    printf("Enter the elements");
    for(int i=0;i<length;i++)
    {
        scanf("%d",&ptr[i]);
    }
    iRet=Summation(ptr,length);

    printf("Addition of elements is : %d",iRet);

}