/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        //特殊情况：空串直接返回0
        if (s.size() == 0)
            return 0;
        int count = 0, i = s.length() - 1;
        //去掉末尾的空格直到遇到第一个字母
        while (s[i] == ' ' && i >= 0)
        {
            --i;
            //字串全部是空格则返回0
            if (i < 0)
                return 0;
        }
        //从字母开始往前扫描到第一个空格为止并计数
        while (i >= 0 && s[i] != ' ')
        {
            count++;
            i--;
        }
        return count;
    }
};
// @lc code=end
