#include<stdio.h>
#include<stdbool.h>
//4th  
typedef unsigned int UNIT;

//0000  0000    0000    0000    0000    0000   0000    0000
//0000  0000    0000    0000    0000    0000   1000    1000

//0xFFFFFFF7  
 
UNIT ToggleBit(UNIT No)
{
    UNIT iMask=0x00000008;

    int iAns=No^iMask;

    return (iAns);
}

int main()
{
    UNIT Value=0;
    UNIT iRet=0;

    printf("Enter value");
    scanf("%d",&Value);

    iRet=ToggleBit(Value);

    printf("Updated no is:%d\n",iRet);
    return 0;
}