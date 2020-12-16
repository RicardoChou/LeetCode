/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution
{
    //一次遍历
public:
    int maxProfit(vector<int> &prices)
    {
        //最小的买入价格
        int minPrice = INT_MAX;
        //利润最大的情况
        int maxProfit = 0;
        //一次遍历
        for (int i = 0; i < prices.size(); i++)
        {
            //更新最小买入价格
            if (prices[i] < minPrice)
                minPrice = prices[i];
            //更新最大利润
            if (prices[i] - minPrice > maxProfit)
                maxProfit = prices[i] - minPrice;
        }
        return maxProfit;
    }
};
// @lc code=end
