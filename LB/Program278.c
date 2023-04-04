#include<stdio.h>
#include<stdbool.h>
//12th bit 
typedef unsigned int UNIT;

//0000  0000    0000    0000    0000    1000    0000    0000
// 0     0       0       0         0    8       0       0
//00000800
//0x00000800  
// 12 bit la ek deycha tyacha 4 digit mde decimal cha ani ntr to no sgla lihun gheycha ntr hex mde krych mhnun 0x add krych start la                     
bool CheckBit(UNIT No)
{
    UNIT iMask=0x00000800;
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
        printf("12th bit is on\n ");
    }
    else
    {
        printf("12th bit  is off\n");
    }

    return 0;
}