/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution
{
    //回溯法
    void backtrack(vector<string> &ans, string &cur, int left, int right, int n)
    {
        //如果current的括号字符串的长度等于2n，说明已经这次匹配已经完成
        //直接加入到最终返回字符串vector中，同时返回
        if (cur.size() == n * 2)
        {
            ans.push_back(cur);
            return;
        }
        //如果左括号小于n，则可以在current的括号字符串中插入一个'('
        //同时递归到下一层
        if (left < n)
        {
            cur.push_back('(');
            backtrack(ans, cur, left + 1, right, n);
            cur.pop_back();
        }
        //如果右括号小于左括号的数量，则可以在current的括号字符串中插入一个')'
        //同时低轨道下一层
        if (right < left)
        {
            cur.push_back(')');
            backtrack(ans, cur, left, right + 1, n);
            cur.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        string current;
        //初始层数为0，即左括号和右括号都为0
        backtrack(result, current, 0, 0, n);
        return result;
    }
};
// @lc code=end
