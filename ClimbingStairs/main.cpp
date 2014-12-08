/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        int sum = 0;
		int maxTwoSteps = n >> 1;
		for (int i = 0; i <= maxTwoSteps; i++)
		{
			sum += C(i, n - i);
		}
		return sum;
    }
	int C(int selectNum, int choices)
	{
		if (selectNum == 0 || choices == 0)
		{
			return 1;
		}
		if (selectNum == 1 || selectNum == choices - 1)
		{
			return choices;
		}
		long long selectSum = 1;
		for (int i = 0; i < selectNum; i++)
		{
			selectSum *= choices - i;
			selectSum /= i + 1;
		}
		return selectSum;
	}
};
