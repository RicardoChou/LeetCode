/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution
{
public:
    // 栈底元素为当前已经遍历过的元素中最后一个没有被匹配的右括号的下标
    // 对于遇到的每个 \text{‘(’}‘(’ ，我们将它的下标放入栈中
    // 对于遇到的每个 \text{‘)’}‘)’ ，我们先弹出栈顶元素表示匹配了当前右括号：
    // 如果栈为空，说明当前的右括号为没有被匹配的右括号，我们将其下标放入栈中来更新我们之前提到的「最后一个没有被匹配的右括号的下标」
    // 如果栈不为空，当前右括号的下标减去栈顶元素即为「以该右括号为结尾的最长有效括号的长度」
    int longestValidParentheses(string s)
    {
        int maxLen = 0;
        stack<int> stack;
        // 初始设置最后一个没有被匹配的右括号下标为-1
        stack.push(-1);
        for (int i = 0; i < s.size(); i++)
        {
            // 遇到左括号就将下标压入栈中
            if (s[i] == '(')
            {
                stack.push(i);
            }
            // 遇到右括号就弹出一个左括号
            else
            {
                stack.pop();
                // 如果弹出了左括号后栈为空，说明当前是最后一个没有被匹配的右括号，将下标压入栈
                if (stack.empty())
                {
                    stack.push(i);
                }
                else
                {
                    // 更新最大长度
                    maxLen = max(maxLen, i - stack.top());
                }
            }
        }
        return maxLen;
    }
};
// @lc code=end
