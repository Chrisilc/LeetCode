/*
 Given numRows, generate the first numRows of Pascal's triangle.
 
 For example, given numRows = 5,
 Return
 
 [
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
 ]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>>result;
        if (numRows < 1)
        {
            return result;
        }
        vector<int> preRow(1, 1);
        result.push_back(preRow);
        for (int i = 1; i < numRows; i++)
        {
            preRow = generateRow(preRow);
            result.push_back(preRow);
        }
        return result;
    }
private:
    vector<int> generateRow(vector<int> preRow)
    {
        int pre = 0;
        vector<int> result;
        vector<int>::iterator it = preRow.begin();
        do
        {
            result.push_back(pre + *it);
            pre = *it;
            it++;
        }while (it != preRow.end());
        result.push_back(1);
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> pascal = (new Solution())->generate(10);
    for (vector<vector<int>>::iterator itP = pascal.begin(); itP != pascal.end(); itP++)
    {
        for (vector<int>::iterator itI = (*itP).begin(); itI != (*itP).end(); itI++)
        {
            cout << *itI << " ";
        }
        cout << endl;
    }
    return 0;
}
