/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        int n = nums.size();
        int begin = 0, i = 1;
        while (i < n)
        {
            // 这边要用i与i-1来进行比较，不能用i与i+1进行比较，不然会导致溢出
            // 还有要进行类型转换(long)
            if ((long)nums[i] - (long)nums[i - 1] != 1)
            {
                // 该范围就一个数的话直接插入即可
                if (begin == i - 1)
                {
                    res.emplace_back(to_string(nums[begin]));
                }
                // 该范围不止一个数就按照规定格式输出
                else
                {
                    res.emplace_back(to_string(nums[begin]) + "->" + to_string(nums[i - 1]));
                }
                // 更新begin
                begin = i;
            }
            ++i;
        }
        // 特殊情况：如果最后一段范围内还有数
        if (n != 0)
        {
            if (begin == i - 1)
            {
                res.emplace_back(to_string(nums[begin]));
            }
            else
            {
                res.emplace_back(to_string(nums[begin]) + "->" + to_string(nums[i - 1]));
            }
        }
        return res;
    }
};
// @lc code=end
