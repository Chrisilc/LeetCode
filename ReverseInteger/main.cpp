/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
Test cases had been added to test the overflow behavior.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int y = 0;
        int o = x;
        while(x != 0)
        {
            y = y * 10 + x % 10;
            x /= 10;
        }
        if ((o > 0 && y < 0) || (o < 0 && y > 0))
        {
            return 0;
        }
        return y;
    }
};

int main()
{
    Solution* s = new Solution();
    cout << s->reverse(2147483647) << endl;
    return 0;
}


