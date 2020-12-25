/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution
{
public:
    // 因为输入数组是一个升序数组，所以先固定一个数，第二个数在第一个数右边用二分查找
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        for (int i = 0; i < numbers.size(); i++)
        {
            // 二分查找
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high)
            {
                int mid = (high - low) / 2 + low;
                if (numbers[i] == target - numbers[mid])
                    // 下标是从1开始的，所以返回要+1
                    return {i + 1, mid + 1};
                else if (numbers[i] < target - numbers[mid])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return {-1, -1};
    }
};
// @lc code=end
