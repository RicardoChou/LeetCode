/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{
public:
    //和组合总和I一样采用回溯法，区别在于I中数字可以重复使用，而这题数字不可以重复使用
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> combinations;
        vector<int> combination;
        //进行排序是为了加速剪枝
        sort(candidates.begin(), candidates.end());
        //进行回溯
        dfs(combinations, combination, target, 0, candidates);
        //该步骤是为了进行去重
        set<vector<int>> s(combinations.begin(), combinations.end());
        combinations.assign(s.begin(), s.end());
        //返回
        return combinations;
    }
    //深度遍历回溯函数
    void dfs(vector<vector<int>> &combinations, vector<int> &combination, int target,
             int lastIndex, vector<int> &candidates)
    {
        ////满足条件，插入返回vector
        if (target == 0)
        {
            combinations.push_back(combination);
            return;
        }
        ////如果结果小于0，则肯定不满足，直接剪枝
        else if (target < 0)
            return;
        else
        {
            for (int i = lastIndex; i < candidates.size(); i++)
            {
                // //加速剪枝，因为整个原数组是经过排序的
                //如果减去当前数字之后小于0，则减去后面的数字也肯定小于0（排序过的）可以直接返回
                if (target - candidates[i] < 0)
                {
                    break;
                }
                int curNum = candidates[i];
                combination.push_back(curNum);
                //进行回溯
                dfs(combinations, combination, target - curNum, i + 1, candidates);
                combination.pop_back();
            }
        }
    }
};
// @lc code=end
