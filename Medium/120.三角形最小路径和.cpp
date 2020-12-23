/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
class Solution
{
public:
    //dp动态规划做
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        //dp数组
        vector<vector<int>> dp(n, vector<int>(n));
        //边界条件
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++)
        {
            //如果是每一行的最左侧的话，那么它的上一行一定也是最左侧
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            //其他情况按照题目要求来选上一层中最小路径值
            for (int j = 1; j < triangle[i].size() - 1; j++)
            {
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
            }
            //如果是每一行的最右侧的话，那么它的上一行一定也是最右侧的
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
        }
        //返回dp数组中第n-1行的最小元素，就是最小路径和
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
// @lc code=end
