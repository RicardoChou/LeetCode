/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution
{
    //因为是升序数组，但是有旋转，所以它是由两段升序数组构成的，所以可以对两段升序数组分别进行二分法查找
public:
    int search(vector<int> &nums, int target)
    {
        int size = nums.size();
        //两个特殊情况
        if (size == 0)
        {
            return -1;
        }
        if (size == 1)
        {
            return nums[0] == target ? 0 : -1;
        }
        //二分法进行查找
        int low = 0, high = size - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            //找到直接返回
            if (nums[mid] == target)
                return mid;
            //因为nums[0]<=nums[mid]，所以证明nums[0]到nums[mid]这一段是升序的，（只有这一种可能）可以使用二分查找
            if (nums[0] <= nums[mid])
            {
                //如果target在左部的升序数组中就跳转到左部
                if (nums[0] <= target && target < nums[mid])
                {
                    high = mid - 1;
                }
                //如果target在右部的升序数组中就跳转到右部
                else
                {
                    low = mid + 1;
                }
            }
            //反之同理
            else
            {
                if (nums[mid] < target && target <= nums[size - 1])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        //搜索不到返回-1
        return -1;
    }
};
// @lc code=end
