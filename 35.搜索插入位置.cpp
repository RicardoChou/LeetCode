/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution
{
public:
    //题设规定这是个升序的数组,所以可以用二分法
    int searchInsert(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1, mid;
        //比最大的数还大则返回最后的index
        if (nums[high] < target)
            return high + 1;
        //二分循环
        while (low < high)
        {
            mid = low + (high - low) / 2;
            //找到则返回
            if (nums[mid] == target)
                return mid;
            //转到左半边寻找
            else if (nums[mid] > target)
                high = mid;
            //转到右半边寻找
            else
                low = mid + 1;
        }
        return low;
    }
};
// @lc code=end
