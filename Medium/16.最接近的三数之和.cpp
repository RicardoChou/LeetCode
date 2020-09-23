/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        //temp用于存储与target的最小差值
        int temp = INT_MAX, res = 0;
        //和第15题类似，先对数组进行排序
        sort(nums.begin(), nums.end());
        //和15题一样，先固定一个数，然后内部再用双指针进行相加
        for (int k = 0; k < nums.size(); k++)
        {
            //和15题一样，先固定一个数，然后内部再用双指针一个从左到右，一个从右到左，进行相加
            int i = k + 1, j = nums.size() - 1;
            while (i < j)
            {
                //如果三个数相加等于target，那就是最接近的，直接返回target就行了
                if (nums[i] + nums[j] + nums[k] == target)
                    return target;
                //如果三数相加之和小于target，那就要移动左指针
                else if (nums[i] + nums[j] + nums[k] < target)
                {
                    //更新res和temp
                    if (target - (nums[i] + nums[j] + nums[k]) < temp)
                    {
                        res = nums[i] + nums[j] + nums[k];
                        temp = target - (nums[i] + nums[j] + nums[k]);
                    }
                    //跳过重复的数字
                    while (i < j && nums[i] == nums[i + 1])
                        i++;
                    //左指针右移
                    i++;
                }
                //如果三数相加之和大于target，那就要移动右指针
                else if (nums[i] + nums[j] + nums[k] > target)
                {
                    ////更新res和temp
                    if (nums[i] + nums[j] + nums[k] - target < temp)
                    {
                        res = nums[i] + nums[j] + nums[k];
                        temp = nums[i] + nums[j] + nums[k] - target;
                    }
                    //跳过重复的数字
                    while (i < j && nums[j] == nums[j - 1])
                        j--;
                    //右指针左移
                    j--;
                }
            }
        }
        return res;
    }
};
// @lc code=end
