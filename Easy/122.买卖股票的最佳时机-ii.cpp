/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp[n][2];
        //dp[0][0]表示第i天交易完后手里没有股票的最大利润
        //dp[0][1]表示第i天交易完后手里持有一支股票的最大利润
        //第0天交易结束的时候dp[0][0]=0，dp[0][1]=−prices[0]
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i)
        {
            //如果这一天交易完后手里没有股票，那么可能的转移状态为前一天已经没有股票，
            //即dp[i−1][0]，或者前一天结束的时候手里持有一支股票，即dp[i−1][1]，
            //这时候我们要将其卖出，并获得prices[i]的收益
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            //可能的转移状态为前一天已经持有一支股票，即dp[i−1][1]，
            //或者前一天结束时还没有股票，即dp[i−1][0]，这时候我们要将其买入
            //并减少prices[i]的收益。
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        //全部交易结束后，持有股票的收益一定低于不持有股票的收益,
        //因此这时候dp[n−1][0]的收益必然是大于dp[n−1][1]的，最后的答案即为dp[n−1][0]
        return dp[n - 1][0];
    }
};
// @lc code=end
