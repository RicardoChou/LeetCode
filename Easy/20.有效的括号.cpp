/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
    //简单的括号匹配算法，用一个栈即可
public:
    bool isValid(string s)
    {
        //声明一个栈
        stack<char> res;
        char c;
        //对括号串进行扫描
        for (int i = 0; i < s.size(); i++)
        {
            c = s[i];
            //如果是左括号，压入栈中
            if (c == '(' || c == '{' || c == '[')
                res.push(c);
            /*如果发现扫描的括号不是左括号且栈已经为空，则说明匹配必定失败
            这里要加上这个条件语句，不加上的话，无法A，会报Runtime Error
            可能是因为空栈无法调用top函数的原因（猜测）
            */
            else if (res.empty())
                return false;
            /*
            如果扫描到的是右括号，三种右括号逻辑相同，均为如果栈顶是与其对应的
            左括号，则直接弹出，反之直接return false
            */
            else
            {
                switch (s[i])
                {
                case ')':
                    if (res.top() == '(')
                        res.pop();
                    else
                    {
                        return false;
                    }
                    break;
                case ']':
                    if (res.top() == '[')
                        res.pop();
                    else
                    {
                        return false;
                    }
                    break;
                case '}':
                    if (res.top() == '{')
                        res.pop();
                    else
                    {
                        return false;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        //如果扫描全部完成，最后栈内还留有括号（肯定是左括号)则表明匹配还是失败的
        if (res.empty())
            return true;
        else
            return false;
    }
};
// @lc code=end
