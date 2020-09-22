/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        //用于返回的vector
        vector<vector<int>> res;
        int j, k, n = nums.size();
        //先进行排序
        sort(nums.begin(), nums.end());
        //如果数组为空或者所有数字都大于0或者所有数字都小于0则返回空
        if (nums.empty() || nums[0] > 0 || nums[n - 1] < 0)
            return {};
        for (int i = 0; i < n; i++)
        {
            //从左往右的指针如果扫描的数字大于0，那接下来一定不可能相加得到0
            //所以直接跳出即可
            if (nums[i] > 0)
                break;
            //跳过重复的数字
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            //在确定了一个nums[i]的情况下下面使用双指针，这是从左向右的指针
            j = i + 1;
            //双指针，从右往左
            k = nums.size() - 1;
            while (j < k)
            {
                //三个数相加得到0则加入用于返回的vector
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    //跳过重复数字
                    while (j < k && nums[j] == nums[j + 1])
                        j++;
                    //跳过重复数字
                    while (j < k && nums[k] == nums[k - 1])
                        k--;
                    //双指针均移动
                    j++;
                    k--;
                }
                //如果三个数相加得到的值小于0,那就把左指针右移
                else if (nums[i] + nums[j] + nums[k] < 0)
                    j++;
                //如果三个数相加得到的值大于0,那就把右指针左移
                else
                    k--;
            }
        }
        return res;
    }
};
// @lc code=end
