/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
    //递归实现组合型枚举
    //我们需要在n个元素选k个，在dfs的时候需要多传入一个参数k，
    //即dfs(cur,n,k)。在每次进入这个dfs函数时,我们都去判断当前temp的长度是否为k，
    //如果为k，就把temp加入答案并直接返回
public:
    vector<int> temp;
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k)
    {
        dfs(1, n, k);
        return res;
    }
    void dfs(int cur, int n, int k)
    {
        //剪枝优化:如果当前temp的大小+剩余可选的数字数目小于k，说明不可能凑出长度为k的组合
        //可以直接返回
        if (temp.size() + (n - cur + 1) < k)
            return;
        //当前temp的长度是否为k，如果为k，就把temp加入答案并直接返回
        if (temp.size() == k)
        {
            res.push_back(temp);
            return;
        }
        //如果当前位置的数目是被选择的话，就添加进temp并且进行递归
        temp.push_back(cur);
        dfs(cur + 1, n, k);
        temp.pop_back();
        //如果当前位置的数目是不被选择的话，直接进行递归
        dfs(cur + 1, n, k);
    }
};
// @lc code=end
