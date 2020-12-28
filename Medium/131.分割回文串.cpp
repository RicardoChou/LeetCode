/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution
{
public:
    // 返回字符串数组
    vector<vector<string>> res;
    // 存放临时的是回文串的字符串
    vector<string> path;

    vector<vector<string>> partition(string s)
    {
        backtracking(s, 0);
        return res;
    }
    // 回溯算法
    // start变量是用于在回溯时确定for循环的起始点的
    void backtracking(string &s, int start)
    {
        // 如果起始位置已经大于整个字符串的大小，说明已经找到了一个分割方案
        if (start >= s.size())
        {
            // 加入res字符串数组
            res.push_back(path);
            return;
        }
        // for循环用来进行横向扫描
        for (int i = start; i < s.size(); i++)
        {
            // 判断截取的那一段字符串是否是回文串
            if (isPalindrom(s, start, i))
            {
                // 截取的那一段字符串是否是回文串的话就获取那一段子串加入path字符串数组
                string str = s.substr(start, i - start + 1);
                path.push_back(str);
            }
            else
            {
                // 截取的那一段字符串不是回文串就跳过
                continue;
            }
            // 寻找i+1为起始位置的子串
            backtracking(s, i + 1);
            // 回溯过程，弹出本次已经填在的子串
            path.pop_back();
        }
    }
    // 判断是否是回文串的辅助函数
    bool isPalindrom(string &s, int start, int end)
    {
        // 双指针法进行回文串的判断
        for (int i = start, j = end; i < j; i++, j--)
        {
            if (s[i] != s[j])
                return false;
        }
        return true;
    }
};
// @lc code=end
