/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
	string countAndSay(int n) {
	    string output = "1";
        for (int i = 2; i <= n; i++)
        {
            output = countOneNumber(output);
        }
        return output;
	}

private:

	char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

	string numberToString(int n)
	{
		if (n == 0)
		{
			return "0";
		}
		std::string str = "";
		while (n > 0)
		{
			str += numbers[n % 10];
			n /= 10;
		}
		str.reserve();
		return str;
	}

	string countOneNumber(string n)
	{
		char currentChar = n[0];
		int currentCount = 1;
		string output = "";
		for (int i = 1; i < n.length(); i++)
		{
			if (currentChar != n[i])
			{
                output += numberToString(currentCount);
                output += currentChar;
				currentChar = n[i];
				currentCount = 1;
			}
			else
			{
                currentCount++;
			}
		}
		output += numberToString(currentCount);
        output += currentChar;
        return output;
	}
};
