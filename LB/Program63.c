#include<stdio.h>
#include<stdlib.h>

void DisplayEvenOddAddition(int Arr[],int size)
{
    int iCnt=0,iEvensum=0,iOddSum=0;

    for(iCnt=0;iCnt<size;iCnt++)
    {
        if(iCnt%2==0)
        {
            iEvensum=iEvensum+Arr[iCnt];
            
        }
        else
        {
           iOddSum=iOddSum+Arr[iCnt]; 
            
        }
         
        
    }
    printf("even no sum is:%d\n",iEvensum);
    printf("Odd no sum is:%d\n",iOddSum);   
    
}
int main()
{
    int *ptr=NULL;
    int iLength=0,i=0;
    
    printf("enter no of elements:\n");
    scanf("%d",&iLength);

    ptr=(int *)malloc(iLength*sizeof(int));
    printf("enter the elements:\n");

    for(i=0;i<iLength;i++)
    {
        scanf("%d",&ptr[i]);
    }

    DisplayEvenOddAddition(ptr,iLength);

   // printf("count of even no is:%d\n",iRet);
    
    free(ptr);
    return 0;

}