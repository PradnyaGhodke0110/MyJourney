#include<stdio.h>
#include<stdbool.h>
//4th  
typedef unsigned int UNIT;

//0000  0000    0000    0000    0000    0000   0000    0000
//1111  1111    1111    1111    1111    1111    1111    0111

//0xFFFFFFF7  
 
UNIT OffBit(UNIT No)
{
    UNIT iMask=0xFFFFFFF7;

    int iAns=No & iMask;

    return (iAns);
}

int main()
{
    UNIT Value=0;
    UNIT iRet=0;

    printf("Enter value");
    scanf("%d",&Value);

    iRet=OffBit(Value);

    printf("Updated no is:%d\n",iRet);
    return 0;
}