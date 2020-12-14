/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        //返回数组
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; i++)
        {
            //因为是行数是从0开始计数，所以每一行其实大小是行数+1
            res[i].resize(i + 1);
            //最左和最右都是1
            res[i][0] = res[i][i] = 1;
            //中间的每个数是它左上方和右上方的数的和
            for (int j = 1; j < i; j++)
            {
                res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
            }
        }
        return res;
    }
};
// @lc code=end
