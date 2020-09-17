/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        //特殊情况
        if (numRows <= 1)
            return s;
        //返回字符串
        string res = "";
        int size = 2 * numRows - 2;
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = i; j < s.size(); j += size)
            {
                res += s[j];
                int tmp = j + size - 2 * i;
                if (i != 0 && i != numRows - 1 && tmp < s.size())
                    res += s[tmp];
            }
        }
        return res;
    }
};
// @lc code=end
