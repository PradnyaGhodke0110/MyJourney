// Accept number and range from user, and toggle the bits from that range

// Input    0010    1010    1010    1110    1101    1010    0110    1101    // Start = 7    End = 17

// Output   0010    1010    1010    1111    0010    0101    1010    1101

// Mask     0000    0000    0000    0001    1111    1111    1100    0000

// Mask1    1111    1111    1111    1111    1111    1111    1111    1111
// Mask2    1111    1111    1111    1111    1111    1111    1111    1111

// Mask1 = Mask1 << (Start - 1)
//          1111    1111    1111    1111    1111    1111    1100    0000

// Mask2 = Mask2 >> (32 - End)
// Mask2 = Mask2 >> 15
//          0000    0000    0000    0001    1111    1111    1111    1111

// Mask = Mask1 & Mask2
//          1111    1111    1111    1111    1111    1111    1100    0000
//          0000    0000    0000    0001    1111    1111    1111    1111    &
//  ------------------------------------------------------------------------------
//          0000    0000    0000    0001    1111    1111    1100    0000

// Result = No ^ Mask
//          0010    1010    1010    1110    1101    1010    0110    1101 
//          0000    0000    0000    0001    1111    1111    1100    0000    ^
//  ---------------------------------------------------------------------------
//          

#include<stdio.h>

typedef unsigned int UINT;

UINT ToggleRange(UINT No, UINT Start, UINT End)
{
    UINT Mask1 = 0XFFFFFFFF, Mask2 = 0XFFFFFFFF, Mask = 0, Result = 0;

    Mask1 = Mask1 << (Start - 1);
    Mask2 = Mask2 >> (32 - End);
    Mask = Mask1 & Mask2;

    Result = No ^ Mask;
    return Result;
}

int main()
{
    UINT Value = 0;
    UINT i =0, j = 0;
    UINT Ret = 0;

    printf("Please enter number : \n");
    scanf("%d",&Value);

    printf("Enter starting bit position \n");
    scanf("%d",&i);

    printf("Enter ending bit position \n");
    scanf("%d",&j);

    Ret = ToggleRange(Value, i, j);
    printf("Updated number is : %d\n",Ret);

    return 0;
}