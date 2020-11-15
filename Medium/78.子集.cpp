/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution
{
    //套用回溯模板即可
    //这里之所以可以不用考虑子集得大小（也就是可能子集有一个元素吗，也可能子集有两个元素）
    //是因为回溯模板中有两种选择
    //1.将当前元素加入temp，也就是选择当前元素再递归回溯
    //2.不选择当前元素，直接递归回溯
public:
    //全局vector
    vector<int> temp;
    vector<vector<int>> res;

    //递归回溯辅助算法
    void dfs(int cur, vector<int> &nums)
    {
        //当前temp的长度满足就把temp加入res并直接返回
        if (cur == nums.size())
        {
            res.push_back(temp);
            return;
        }
        //1.将当前元素加入temp，也就是选择当前元素再递归回溯
        temp.push_back(nums[cur]);
        dfs(cur + 1, nums);
        //2.不选择当前元素，同时递归回溯
        temp.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(0, nums);
        return res;
    }
};
// @lc code=end
