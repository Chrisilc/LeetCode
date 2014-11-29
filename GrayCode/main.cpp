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
        Write(&seqNum, 0, 0);
        Write(&seqNum, 1, 1);
        Write(&seqNum, 2, 3);
        Write(&seqNum, 3, 2);
        len = (n >> 1) + (n & 1);
        isFullLen = ((n & 1) == 0);
        bins = 0;
        jumpFlag = ~0;
        vector<int> result;
        result.push_back(0);
        isNotFullFlag = true;
        while(isNotFullFlag)
        {
            int index = 0;
            for (; index < len - 1; index++)
            {
                if (!plusOne(index))
                {
                    break;
                }
            }
            if (index == len - 1 && headPlusOne())
            {
                isNotFullFlag = false;
            }
            else
            {
                result.push_back(OutputBins());
            }
        }
        return result;
    }
private:
    bool isFullLen;
    int len;
    int seqNum;
    int bins;
    int jumpFlag;
    bool isNotFullFlag;
    bool plusOne(int index)
    {
        int cur = Read(&bins, index);
        int curflag = Read(&jumpFlag, index);
        if (cur == curflag)
        {
            Write(&jumpFlag, index,  (curflag + 3) & 3);
            return true;
        }
        Write(&bins, index, (cur + 1) & 3);
        return false;
    }
    bool headPlusOne()
    {
        int head = Read(&bins, len - 1);
        if ((isFullLen && head < 3)||(!isFullLen && head < 1))
        {
            Write(&bins, len - 1, head + 1);
            return false;
        }
        else
        {
            return true;
        }
    }
    int OutputBins()
    {
        int index = 0;
        int result = 0;
        for (; index < len; index++)
        {
            int cur = Read(&seqNum, Read(&bins, index));
            if (cur == 0) continue;
            int eights = 1;
            for (int i = 1; i <= index; i++)
            {
                eights <<= 3;
            }
            result += cur * eights;
        }
        return result;
    }

    int Read(int* source, int index)
    {
        return (*source >> (index << 1)) & 3;
    }

    void Write(int* source, int index, int data)
    {
        int clearMask = 3;
        data &= 3;
        for (int i = 0; i < index; i++)
        {
            clearMask <<= 2;
            data <<= 2;
        }
        *source = (*source & (~clearMask)) | data;
    }
};

int main()
{
    Solution* s = new Solution();
    vector<int> result = s->grayCode(4);
    for (vector<int>::iterator it = result.begin() ; it != result.end(); ++it)
    std::cout << ' ' << *it;
    return 0;
}
