/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0;
        int tail = s.length() - 1;
        while (head < tail)
        {
            char hc = s[head];
            if (!isAlphanumeric(hc))
            {
                head++;
                continue;
            }
            char tc = s[tail];
            if (!isAlphanumeric(tc))
            {
                tail--;
                continue;
            }
            if (hc == tc)
            {
                head++;
                tail--;
                continue;
            }
            if ((hc >='0' && hc <= '9') || (tc >= '0' && tc <= '9') || (tc - hc != 'a'-'A' && tc - hc != 'A' - 'a'))
            {
                return false;
            }
            head++;
            tail--;
        }
        return true;
    }
private:
    bool isAlphanumeric(char c)
    {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }
};

int main()
{
    Solution* s = new Solution();
    cout << s->isPalindrome("1a2") << endl;
    return 0;
}
