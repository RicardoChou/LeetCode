/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int size = nums.size();
        if (size == 1)
            return nums[0];
        vector<int> dp = vector<int>(size, 0);
        // 两个边界条件
        // 有一间房屋，则偷窃该房屋，可以偷窃到最高总金额
        // 只有两间房屋，选择其中金额较高的房屋进行偷窃，可以偷窃到最高总金额。
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; i++)
        {
            // 状态转移方程
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};
// @lc code=end
