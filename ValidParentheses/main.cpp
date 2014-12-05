/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
#include <iostream>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        string bracketStack = "";
        long len = s.length();
        for (long i = 0; i < len; i++)
        {
            char c = s[i];
            switch (c)
            {
                case '(':
                case '[':
                case '{':
                    bracketStack += c;
                    break;
                case ')':
                    if(pop(&bracketStack) != '(')
                    {
                        return false;
                    }
                    break;
                case ']':
                    if (pop(&bracketStack) != '[')
                    {
                        return false;
                    }
                break;
                    case '}':
                    if (pop(&bracketStack) != '{')
                    {
                        return false;
                    }
                    break;
            }
        }
        return bracketStack == "";
    }
private:
    char pop(string* str)
    {
        long len = (*str).length();
        if (len < 1)
        {
            return 0;
        }
        char c = (*str)[len - 1];
        (*str).pop_back();
        return c;
    }
};

int main(int argc, const char * argv[])
{
    Solution* s = new Solution();
    cout << s->isValid("[()]");
    return 0;
}
