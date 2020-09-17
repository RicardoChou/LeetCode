/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution
{
    //这题题设要求的公共子串是从头开始就要能匹配上，相对而言比较简单
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        //如果整个vector都是空的，那就直接返回""即可
        if (strs.empty())
            return "";
        //返回字符串串
        string res = "";
        //从vector的第一个字符串的每一个字符作为比较的源头字符，进行外部循环
        for (int j = 0; j < strs[0].size(); j++)
        {
            //第一个字符串的每一个字符作为比较的源头字符
            char c = strs[0][j];
            //从第二个字符串开始将对应的每一列的那个字符与源头字符进行比较，进行内部循环
            for (int i = 1; i < strs.size(); i++)
            {
                //如果某一个字符匹配不成功，返回
                //或者某一行的那个字符串已经到头，从而长度小于源头字符串的长度，返回
                if (strs[i][j] != c || j > strs[i].size())
                    return res;
            }
            //那一列的每一行的每一个字符都匹配成功，则将该字符压入返回串，作为公共前缀的末尾
            res.push_back(c);
        }
        return res;
    }
};
// @lc code=end
