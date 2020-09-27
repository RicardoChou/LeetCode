/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        //返回变量res
        set<vector<int>> res;
        //临时变量
        int temp;
        //对数组进行排序
        sort(nums.begin(), nums.end());
        //先用双重循环固定两个数
        for (int i = 0; i < int(nums.size() - 3); i++)
        {
            //先用双重循环固定两个数
            for (int j = i + 1; j < int(nums.size() - 2); j++)
            {
                //跳过重复数字
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                //双指针遍历
                int m = j + 1, n = nums.size() - 1;
                while (m < n)
                {
                    //求四个数之和
                    temp = nums[i] + nums[j] + nums[m] + nums[n];
                    //如果四个数之和等于target，就直接返回这四个数
                    if (temp == target)
                    {
                        vector<int> out = {nums[i], nums[j], nums[m], nums[n]};
                        res.insert(out);
                        //双指针均移动
                        m++;
                        n--;
                    }
                    //如果temp比target小，那就移动左指针往较大的数走
                    else if (temp < target)
                        m++;
                    else
                    //如果temp比target大，那就移动右指针往较小的数走
                        n--;
                }
            }
        }
        //返回
        return vector<vector<int>>(res.begin(), res.end());
    }
};
// @lc code=end
