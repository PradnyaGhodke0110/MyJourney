#include<stdio.h>
#include<stdbool.h>

typedef unsigned int UNIT;

//ji pos ahe toch fkt toggle krycha baki sgle  1 pahijet

UNIT  ToggleBit(UNIT No,UNIT Pos)
{
    UNIT iMask=0x00000001;
    UNIT Result=0;
    iMask=iMask<<(Pos-1);

    iMask=~iMask;

    Result=No&iMask;

    return (Result);
}

int main()
{
    UNIT Value=0;
    UNIT iRet=0,Position=0;

    printf("Enter value");
    scanf("%d",&Value);

    printf("Enter Position");
    scanf("%d",&Position);

    iRet=ToggleBit(Value,Position);

    printf("Updated no is:%d\n",iRet);
    
    return 0;
}