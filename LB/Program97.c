/*
row=4
col=4

1 * * *
* 2 * *
* * 3 *
* * * 4

*/
#include<stdio.h>
void Display(int iRows,int iCols)
{
    int i=0,j=0;

    if(iRows!=iCols)
    {
        printf("Row and Columns are diffrent\n");
        return ;
    }

    for(i=1;i<=iRows;i++)
    {
        for(j=1;j<=iCols;j++)
        {
        if(i==j)
        {
            printf("%d\t",j);
        }
        else
        {
            printf("*\t");
        }
        }
        
        printf("\n");
    
    }
}
int main()
{
    int iValue1=0,iValue2=0;
    

    printf("Enter the no.of Rows:\n");
    scanf("%d",&iValue1);
    printf("Enter the no.of columns:\n");
    scanf("%d",&iValue2);
    
    Display(iValue1,iValue2);

    return 0;
}