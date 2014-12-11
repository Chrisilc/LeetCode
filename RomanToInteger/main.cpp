/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    int romanToInt(string s) {
        int len = s.length();
        int result = 0;
        int pre = 0;
        int cur = 0;
        for (int i = 0; i < len; i++)
        {
            cur = SingleRomanToInt(s[i]);
            if (cur == 0)
            {
                return 0;
            }
            else if (pre == 0 || cur <= pre)
            {
                result += pre;
                pre = cur;
            }
            else
            {
                if (!CanSubtract(pre, cur))
                {
                    return 0;
                }
                result += cur - pre;
                pre = 0;
            }
        }
        result += pre;
        if (result > 3999)
        {
            return 0;
        }
        else
        {
            return result;
        }
    }

private:
    int SingleRomanToInt(char r)
    {
        switch (r)
        {
            case 'i':
            case 'I':
                return 1;
            case 'v':
            case 'V':
                return 5;
            case 'x':
            case 'X':
                return 10;
            case 'l':
            case 'L':
                return 50;
            case 'c':
            case 'C':
                return 100;
            case 'd':
            case 'D':
                return 500;
            case 'm':
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
    
    const int IntListSize = 7;
    int IntList[7] = {1, 5, 10, 50, 100, 500, 1000};
    
    bool CanSubtract(int pre, int cur)
    {
        int preIndex = -1;
        for (int i = 0; i < IntListSize; i++)
        {
            if (IntList[i] == pre)
            {
                preIndex = i;
            }
        }
        return preIndex >= 0 && preIndex < IntListSize - 2 
            && 
            (IntList[preIndex + 1] == cur 
            || IntList[preIndex + 2] == cur);
    }
};
