/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution
{
    //回溯法
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        //最终返回vector
        vector<vector<int>> combinations;
        //其中一组满足条件的vector
        vector<int> combination;
        //进行排序是为了加速剪枝
        sort(candidates.begin(), candidates.end());
        //进行回溯
        dfs(combinations, combination, target, 0, candidates);
        return combinations;
    }

    //深度遍历回溯函数
    void dfs(vector<vector<int>> &combinations, vector<int> &combination,
             int target, int lastIndex, vector<int> &candidates)
    {
        //满足条件，插入返回vector
        if (target == 0)
        {
            combinations.push_back(combination);
            return;
        }
        //如果结果小于0，则肯定不满足，直接剪枝
        else if (target < 0)
        {
            return;
        }
        else
        {
            for (int i = lastIndex; i < candidates.size(); i++)
            {
                //加速剪枝，因为整个原数组是经过排序的
                //如果减去当前数字之后小于0，则减去后面的数字也肯定小于0（排序过的）可以直接返回
                if (target - candidates[i] < 0)
                {
                    break;
                }
                int curNum = candidates[i];
                combination.push_back(curNum);
                //进行回溯
                dfs(combinations, combination, target - curNum, i, candidates);
                combination.pop_back();
            }
        }
    }
};
// @lc code=end
