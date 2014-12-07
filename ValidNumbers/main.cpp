/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/
#include <iostream>
using namespace std;
class Solution {
public:
    bool isNumber(const char *s) {
        _head = s;
		_isHeadBlank = true;
		_isPrefixAppeared = false;
		_isDotAppeared = false;
		_isEAppeared = false;
		while (*s != 0)
		{
			if (!checkChar(s))
			{
				return false;
			}
			s++;
		}
		return true;
    }

private:
    const char* _head;
	bool is029(char c)
	{
		int code = c - '0';
		return code >= 0 && code <= 9;
	}

	bool isPrefix(char c)
	{
        return c == '+' || c == '-';
	}

	bool isE(char c)
	{
        return c == 'e' || c == 'E';
	}

	bool checkChar(const char* pc)
	{
		char c = *pc;
		if (is029(c))
		{
            _isHeadBlank = false;
			return true;
		}
		switch(c)
		{
		case ' ':
			return checkBlank(pc);
		case '+':
		case '-':
			return checkPrefix(pc);
		case '.':
			return checkDot(pc);
		case 'e':
		case 'E':
			return checkE(pc);
		default:
			return false;
		}
	}

	bool _isHeadBlank;
	bool checkBlank(const char* pc)
	{
		char next = *(pc + 1);
		if (_isHeadBlank)
		{
			return next == ' ' || isPrefix(next) || is029(next) || next == '.';
		}
		char pre = *(pc-1);
		return (is029(pre) || pre == ' ' || pre == '.') && (next == ' ' || next == 0);
	}
	bool _isPrefixAppeared;
	bool checkPrefix(const char* pc)
	{
		_isHeadBlank = false;
		if (_isPrefixAppeared)
		{
			return false;
		}
		_isPrefixAppeared = true;
		char pre = 0;
		if (pc != _head)
		{
            pre = *(pc-1);
		}
		char next = *(pc+1);
		return (pc == _head || pre == ' ' || isE(pre))
		&& (is029(next) || next == '.');
	}

    bool _isDotAppeared;
	bool checkDot(const char* pc)
	{
		_isHeadBlank = false;
		if (_isDotAppeared || _isEAppeared)
		{
			return false;
		}
		_isDotAppeared = true;
		char pre = 0;
		if (pc != _head)
		{
            pre = *(pc-1);
		}
		char next = *(pc+1);
		return
		 (pc == _head || is029(pre) || isPrefix(pre) || isE(pre) || pre == ' ')
		 && (is029(next) || next == 0 || next == ' ' || isE(next))
		 && (is029(pre) || is029(next));
	}

    bool _isEAppeared;
	bool checkE(const char *pc)
	{
		_isHeadBlank = false;
		if (_isEAppeared)
		{
			return false;
		}
		_isEAppeared = true;
		_isPrefixAppeared=false;
		char next = *(pc+1);
		char pre = 0;
		if (pc != _head)
		{
            pre = *(pc-1);
		}
		return (is029(pre) || pre == '.') && (is029(next) || isPrefix(next) || next == '.');
	}
};

int main()
{
    char input[10] = {'+', '.', '9'};
    Solution* s = new Solution();
    cout << s->isNumber(input);
	return 0;
}
