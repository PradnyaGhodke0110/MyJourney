/*accept 2 numbers from user and check they are anagram*/

// numbers of digit should be same
// frequency of digit should be same

#include <iostream>
using namespace std;
class Demo
{
public:
    int iNo1, iNo2;
    Demo()
    {
        iNo1 = 0;
        iNo2 = 0;
    }
    Demo(int m, int n)
    {
        iNo1 = m;
        iNo2 = n;
    }
    bool checkAnagram()
    {
        int freq1[10] = {0}, freq2[10] = {0};
        int iRem1 = 0, iRem2 = 0;

        while (iNo1 != 0)
        {
            iRem1 = iNo1 % 10;
            freq1[iRem1]++;
            iNo1 = iNo1 / 10;
        }
        while (iNo2 != 0)
        {
            iRem2 = iNo2 % 10;
            freq2[iRem2]++;
            iNo2 = iNo2 / 10;
        }
        bool flag = true;
        for (int iCnt = 0; iCnt < 10; iCnt++)
        {
            if (freq1[iCnt] != freq2[iCnt])
            {
                flag = false;
                break;
            }
        }
        return flag;
    }
};
int main()
{
    int iVal1 = 0, iVal2 = 0;
    bool bRet = false;

    cout << "Enter two numbers:\n";
    cin >> iVal1 >> iVal2;
    Demo obj(iVal1, iVal2);
    bRet = obj.checkAnagram();
    if (bRet == true)
    {
        cout << "numnbers are Anagrams.\n";
    }
    else
    {
        cout << "numbers are not Anagrams.\n";
    }

    return 0;
}