/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution
{
public:
    //要求算法时间复杂度必须是O(logn)级别，所以用二分法
    //二分法思想简单，细节很可怕！！
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res(2, -1);
        //特殊情况
        if (nums.size() == 0)
            return res;
        //第一次二分法求出左边界，注意这里high = nums.size() - 1
        int low = 0, high = nums.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid;
        }
        //不存在等于target的数返回[-1,-1]
        if (nums[high] != target)
            return res;
        //得到左边界
        res[0] = high;
        //注意这里high = nums.size()
        high = nums.size();
        //第二次二分法得到右边界，注意两次二分法里的具体实现细节区别很大
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target)
                low = mid + 1;
            else
                high = mid;
        }
        res[1] = low - 1;
        return res;
    }
};
// @lc code=end
