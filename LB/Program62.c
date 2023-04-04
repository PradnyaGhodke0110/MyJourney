#include<stdio.h>
#include<stdlib.h>

void DisplayEvenOddCount(int Arr[],int size)
{
    int iCnt=0,iCount1=0,iCount2=0;

    for(iCnt=0;iCnt<size;iCnt++)
    {
        if(iCnt%2==0)
        {
            iCount1++;
           
        }
        else
        {
            iCount2++;
            
        }
         
        
    }
    printf("even no count is:%d\n",iCount1);
    printf("Odd no count is:%d\n",iCount2);   
    
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

    DisplayEvenOddCount(ptr,iLength);

   // printf("count of even no is:%d\n",iRet);
    
    free(ptr);
    return 0;

}