/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution
{
    //双指针法
public:
    int singleNumber(vector<int> &nums)
    {
        //先排序
        sort(nums.begin(), nums.end());
        //题设中每个元素要么出现一次，要么出现两次，所以步长设为2
        for (int i = 0, j = 1; j < nums.size(); i += 2, j += 2)
        {
            if (nums[i] != nums[j])
                return nums[i];
        }
        //因为题设中这个数肯定存在，所以遍历到末尾那就是最后一个数
        return nums[nums.size() - 1];
    }
};
// @lc code=end
