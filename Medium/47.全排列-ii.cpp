/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution
{
    //定义一个全局标记数组变量，用于标记该元素是否使用过
    vector<int> vis;

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        //用于返回的vector
        vector<vector<int>> res;
        //当前遍历组成的vector
        vector<int> output;
        //讲标记数组的大小设置为nums的大小
        vis.resize(nums.size());
        //对nums数组进行排序，这样可以使得重复的数字在一块
        sort(nums.begin(), nums.end());
        //进行递归回溯
        backtrack(output, res, 0, nums);
        return res;
    }
    //递归回溯辅助函数
    void backtrack(vector<int> &output, vector<vector<int>> &res, int cur, vector<int> &nums)
    {
        //所有数字都选完就将当前得到的数组插入到res中
        if (cur == nums.size())
        {
            res.push_back(output);
            return;
        }
        //记住要从头开始遍历每一个数字
        for (int i = 0; i < nums.size(); i++)
        {
            //如果当前遍历到的数字是访问过的或者当前数字与前面的相邻的数字相同
            //并且前面的数字没有访问过，那么就跳过，这是因为虽然题目给出的是有重复数字的数组
            //但是题目要求我们生成不重复的序列，所以我们规定重复的数字每次都只是从左到右的第
            //一个数字作为填入数字
            if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]))
                continue;
            //否则将其加入到当前遍历数组
            output.push_back(nums[i]);
            //标记数组置为1
            vis[i] = 1;
            //递归回溯
            backtrack(output, res, cur + 1, nums);
            //跳出循环时要让标记数组还原，这样可以让这个数字重新使用
            vis[i] = 0;
            //弹出
            output.pop_back();
        }
    }
};
// @lc code=end
