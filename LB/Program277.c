#include<stdio.h>
#include<stdbool.h>
//10th bit 
typedef unsigned int UNIT;

//0000  0000    0000    0000    0000    0010    0000    0000
// 0     0       0       0         0      2       0       0
//00000200
//0x00000200                     
bool CheckBit(UNIT No)
{
    UNIT iMask=0x00000200;
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
        printf("10th bit is on\n ");
    }
    else
    {
        printf("10th bit  is off\n");
    }

    return 0;
}