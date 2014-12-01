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
        int alen = a.length();
        int blen = b.length();
        string result = "";
        int moreStep = 0;
        for (int i = 0; i < alen || i < blen; i++)
        {
            int sa = 0;
            int sb = 0;
            if (i < alen)
            {
                sa = a[alen - 1 - i] - '0';
            }
            if (i < blen)
            {
                sb = b[blen - 1 - i] - '0';
            }
            int sum = sa + sb + moreStep;
            result = (char)('0' + (sum & 1)) + result;
            moreStep = sum >> 1;
        }
        if (moreStep > 0)
        {
            result = '1' + result;
        }
        return result;
    }
};

int main()
{
    Solution* s = new Solution();
    cout << s->addBinary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101"
    ,"110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011") << endl;
    return 0;
}
