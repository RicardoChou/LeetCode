/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        //特殊情况
        if (obstacleGrid.size() == 0)
            return 0;
        //行数
        int m = obstacleGrid.size();
        //列数
        int n = obstacleGrid[0].size();
        //dp数组
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //如果第一列没有障碍物，dp数组设为1
        for (int i = 0; i < m && obstacleGrid[i][0] == 0; i++)
        {
            dp[i][0] = 1;
        }
        //如果第一行没有障碍物，dp数组设为1
        for (int i = 0; i < n && obstacleGrid[0][i] == 0; i++)
        {
            dp[0][i] = 1;
        }
        //更新dp数组
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                //没有障碍物的话，就认为是可以被通过
                if (obstacleGrid[i][j] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
