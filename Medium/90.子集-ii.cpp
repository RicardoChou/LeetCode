/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
public:
    //递归回溯辅助算法
    //注意temp和res都要加上&引用地址符号
    void dfs(vector<int> &temp, vector<vector<int>> &res, int cur, vector<int> nums)
    {
        //每一次回溯递归都要将temp加入到res中
        res.push_back(temp);
        for (int i = cur; i < nums.size(); i++)
        {
            //选择了当前的数字
            temp.push_back(nums[i]);
            //递归回溯
            dfs(temp, res, i + 1, nums);
            //不选择当前数字
            temp.pop_back();
            //去掉重复数字
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> temp;
        vector<vector<int>> res;
        //先排序
        sort(nums.begin(), nums.end());
        dfs(temp, res, 0, nums);
        return res;
    }
};
// @lc code=end
