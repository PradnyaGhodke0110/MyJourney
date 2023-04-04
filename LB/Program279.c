#include<stdio.h>
#include<stdbool.h>
//7 8 9 th bit 
typedef unsigned int UNIT;

//0000  0000    0000    0000    0000    0001    1100    0000
// 0     0       0       0         0       1      c       0
//000001c0
//0x000001c0  
 
bool CheckBit(UNIT No)
{
    UNIT iMask=0x000001c0;
    UNIT Result=0;

    Result=No & iMask;

    if(Result == iMask)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    UNIT Value=0;
    bool bRet=false;

    printf("Enter Value");
    scanf("%d",&Value);

    bRet=CheckBit(Value);

    if(bRet==true)
    {
        printf("7 8 9 th bit is on\n ");
    }
    else
    {
        printf("7 8 9th bit  is off\n");
    }

    return 0;
}