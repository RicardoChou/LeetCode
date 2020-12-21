/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        //用一个数组来存储字符和数字，去掉原来字符串中的标点符号
        vector<char> temp;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
                temp.push_back(s[i]);
            //把大写字母变为小写字母
            if (s[i] >= 'A' && s[i] <= 'Z')
                temp.push_back(s[i] + 32);
        }
        int i = 0;
        int j = temp.size() - 1;
        //回文串判断
        while (i < j)
        {
            if (temp[i] == temp[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
};
// @lc code=end
