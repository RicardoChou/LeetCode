/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution
{
    //双指针判断法
public:
    int removeDuplicates(vector<int> &nums)
    {
        //先判断数组为空的特殊情况
        if (nums.empty())
            return 0;
        //双指针
        int slow = 0, fast;
        //这里结束循环的条件需要fast<nums.size()-1，因为循环内有fast+1的情况，
        //如果不减去1的话，会造成数组下标越界
        for (fast = 0; fast < nums.size() - 1; ++fast)
        {
            //如果fast指针与其后面的数字不相同的时候
            if (nums[fast] != nums[fast + 1])
            {
                //将不同的那个数字移到slow的后一个位置上
                nums[++slow] = nums[fast + 1];
            }
        }
        //slow是从0开始的，所以新数组的长度是slow+1
        return slow + 1;
    }
};
// @lc code=end
