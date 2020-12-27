/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // 特殊情况
        if (nums.size() == 1 || nums.size() == 2)
            return nums[0];
        // 排序便于比较
        sort(nums.begin(), nums.end());
        int count = 1;
        // 遍历整个数组
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果下一个数与当前数相同则count加1
            if (nums[i + 1] == nums[i])
            {
                count++;
                // 满足多数元素则返回该数
                if (count > nums.size() / 2)
                    return nums[i];
            }
            // 重置count
            else
                count = 1;
        }
        return nums[nums.size() - 1];
    }
};
// @lc code=end
