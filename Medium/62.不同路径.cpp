/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution
{
    //动态规划
public:
    int uniquePaths(int m, int n)
    {
        //dp动态规划解决
        //边界条件:第一行第一列都是只有一种选择，那就是向右或者向下
        //也就是第一行和第一列的所有值都应该是1（只有一种选择）
        //初始化数组的时候就设为1即可
        vector<vector<int>> dp(m, vector<int>(n, 1));
        //对于每一个可选路径而言，它都是只能由两种情况得到
        //就是左边的向右一步，或者上边的向下一步
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
