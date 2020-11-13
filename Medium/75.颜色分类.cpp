/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
    //双指针遍历
public:
    void sortColors(vector<int> &nums)
    {
        //双指针遍历，p0指示值是0的数，p2指示值是2的数
        //同时也充当右指针
        int p0 = 0, p2 = nums.size() - 1;
        //i充当左指针，左指针到达右指针的位置就可以结束了
        for (int i = 0; i <= p2; i++)
        {
            //找到右半部分最左边的不是2的数来与左边的2进行交换
            while (i < p2 && nums[i] == 2)
            {
                swap(nums[i], nums[p2]);
                p2--;
            }
            //将扫描到的0与p0位置的数进行交换
            if (nums[i] == 0)
            {
                swap(nums[i], nums[p0]);
                p0++;
            }
        }
    }
};
// @lc code=end
