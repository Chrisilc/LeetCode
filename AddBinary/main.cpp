/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        return int2String(string2Int(a) + string2Int(b));
    }
private:
    int string2Int(string str)
    {
        int result = 0;
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            char c = str[len - 1 - i];
            if (c == '1')
            {
                result += 1 << i;
            }
        }
        return result;
    }
    string int2String(int num)
    {
        if (num == 0)
        {
            return "0";
        }
        string result = "";
        while (num != 0)
        {
            result =  (char)('0' + (num & 1)) + result;
            num >>= 1;
        }
        return result;
    }
};

int main()
{
    Solution* s = new Solution();
    cout << s->addBinary("1111","1") << endl;
    return 0;
}
