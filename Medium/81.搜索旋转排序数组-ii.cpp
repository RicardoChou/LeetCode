/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组II
 */

// @lc code=start
class Solution
{
public:
    //用与第33题不同的方法:双指针遍历法
    //用两个指针指向头和尾
    //如果target小于left指向的元素而大于right指向的元素，则肯定不在数组中
    //若target不等于left或者right指向的值，则left左移，right右移
    //因为是旋转的数组，所以可以肯定地是，即使旋转点在中间，
    //从数组末尾到前面旋转点地部分也是有序地
    bool search(vector<int> &nums, int target)
    {
        //特殊情况
        if (nums.size() == 0)
            return false;
        int left = 0, right = nums.size() - 1;
        //循环
        while (left <= right)
        {
            //如果target小于left指向的元素而大于right指向的元素，则肯定不在数组中
            if (target < nums[left] && target > nums[right])
                return false;
            //找到等于target的元素了
            else if (target == nums[left] || target == nums[right])
                return true;
            left++;
            right--;
        }
        return false;
    }
};
// @lc code=end
