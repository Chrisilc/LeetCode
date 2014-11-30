/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1 << n, 0);
        int pos = 0;
        for (vector<int>::iterator it = result.begin() ; it != result.end(); ++it)
        {
            int t = 0;
            for (int i = 0; i < n; i++)
            {
                int index = pos >> i;
                t |= (((index&2)>>1)^(index&1))<<i;
            }
            pos++;
            *it = t;
        }
        return result;
    }
};

int main()
{
    Solution* s = new Solution();
    vector<int> result = s->grayCode(3);
    for (vector<int>::iterator it = result.begin() ; it != result.end(); ++it)
    std::cout << ' ' << *it;
    return 0;
}
