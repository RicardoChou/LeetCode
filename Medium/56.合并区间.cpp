/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        //特殊情况
        if (intervals.size() == 0)
            return {};
        //返回vector
        vector<vector<int>> res;
        //sort函数用于vector<vector<int>>可以按照每个vector的左端点排序
        sort(intervals.begin(), intervals.end());
        //先把第一个数组加入到res中
        res.push_back(intervals[0]);
        //对每一个intervals中的数组，比较当前数组的左端点是否比res中最后一个数组的右端点大
        //如果当前数组的左端点比res中最后一个数组的右端点大，说明无法合并，直接将当前数组加入到res的最后
        //如果当前数组的左端点比res中最后一个数组的右端点小，说明可以合并
        //这时候就要将当前数组的右端点与res中最后一个数组的右端点的中大的更新为新的右端点
        for (int i = 1; i < intervals.size(); i++)
        {
            if (res.back()[1] >= intervals[i][0])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};
// @lc code=end
