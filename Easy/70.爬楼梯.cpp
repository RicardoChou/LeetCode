/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution
{
    //动态规划题
public:
    /*我们用 f(x) 表示爬到第 x 级台阶的方案数
    考虑最后一步可能跨了一级台阶，也可能跨了两级台阶，所以动态规划的转移方程为：
    f(x)=f(x−1)+f(x−2)
    边界条件：
    从第 0 级爬到第 0 级我们可以看作只有一种方案，即 f(0) = 1
    从第0级爬到第1级有1种方案，即f(1)=1
    验证：从第0级爬到第2级有2种方案，即f(2)=f(0)+f(1)=1+1=2
    */
    int climbStairs(int n)
    {
        //动态规划就是用空间换时间，其实这题就是斐波那契数列
        vector<int> dp(n + 1);
        //边界条件
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            //转移方程
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
// @lc code=end
