/*accept number from digit and return largest frequency */

/*
input :798604
output: 0 occurs 1 time
        4 occurs 1 time
        6 occurs 1 time
        7 occurs 1 time
        8 occurs 1 time
        9 ocuurs 1 time
*/
#include <iostream>
using namespace std;

class DigitX
{
public:
    int iNo;
    DigitX()
    {
        iNo = 0;
    }
    DigitX(int i)
    {
        iNo = i;
    }
    void displayFrequency()
    {
        int iTemp = 0;
        iTemp = iNo;
        int frequency[10] = {0};
        int iDigit = 0;
        int iMaxFrequency = 0;
        int iMaxDigit = 0;
        while (iTemp != 0)
        {
            iDigit = iTemp % 10;
            frequency[iDigit]++;
            iTemp = iTemp / 10;
        }
        for (int iCnt = 0; iCnt < 10; iCnt++)
        {
            if (frequency[iCnt] > iMaxFrequency)
            {
                iMaxFrequency = frequency[iCnt];
                iMaxDigit = iCnt;
            }
        }
        cout << iMaxDigit << " and  its frequency is " << iMaxFrequency << "\n";
    }
};

int main()
{
    int iVal = 0;
    cout << "Please enter number : \n";
    cin >> iVal;

    DigitX obj(iVal);
    obj.displayFrequency();
    // cout << "Largest frequency of digit:" << iRet << "\n";
    cout << obj.iNo << "\n";
    return 0;
}