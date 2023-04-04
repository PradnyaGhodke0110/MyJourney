#include<stdio.h>
#include<stdlib.h>

// Step 5 : Perform the operation on array
int Index(int Arr[], int iSize, int iNo)
{
    int iCnt =0, iFrequency = 0;

    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            return iCnt;
        }
        else
        {
            return -1;
        }
    }
    
}

int main()
{
    int *ptr = NULL;
    int iLength = 0, i = 0, iValue = 0, iRet = 0;

    // Step 1 : Accept size of array
    printf("Enter number of elements : \n");
    scanf("%d",&iLength);

    // Step 2 : Allocate memory for array
    ptr = (int *)malloc(iLength * sizeof(int));

    // Step 3 : Accept the elements of array
    printf("Enter the elements : \n");

    for(i = 0 ;i < iLength; i++)
    {
        scanf("%d",&ptr[i]);
    }

    printf("Enter the element  : \n");
    scanf("%d",&iValue);

    // Step 4 : Call the function
    iRet = Index(ptr, iLength, iValue);

    printf("index of %d is %d\n",iValue,iRet);

    // Step 6 : Deallocate the memory
    free(ptr);

    return 0;
}