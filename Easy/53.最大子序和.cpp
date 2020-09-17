/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
class Solution
{
public:
    //动态规划法
    int maxSubArray(vector<int> &nums)
    {
        //初始值定义成理论上的最小值
        int result = INT_MIN;
        int numsSize = nums.size();
        //dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> dp(numsSize);
        //初始用于比较的dp[0]和result
        dp[0] = nums[0];
        result = dp[0];
        //每次扫描更新dp数组和result
        for (int i = 1; i < numsSize; i++)
        {
            //dp数组中永远填充最大的那个数
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            //更新result
            result = max(result, dp[i]);
        }
        return result;
    }
};
// @lc code=end
