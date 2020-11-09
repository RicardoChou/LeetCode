/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        //特殊情况
        if (grid.size() == 0)
            return 0;
        //行数
        int m = grid.size();
        //列数
        int n = grid[0].size();
        //dp数组
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //dp[0][0]就是grid[0][0]
        dp[0][0] = grid[0][0];
        //第一列特殊求法
        for (int i = 1; i < m; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        //第一行特殊求法
        for (int i = 1; i < n; i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        //dp动态计算每一个元素
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[i][j] = dp[i - 1][j] + grid[i][j] <= dp[i][j - 1] + grid[i][j] ? dp[i - 1][j] + grid[i][j] : dp[i][j - 1] + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
