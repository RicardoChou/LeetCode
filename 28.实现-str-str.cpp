/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution
{
public:
    //KMP辅助算法，KMP算法的核心就是求出主串的next数组
    void KMP(vector<int> &next, string key)
    {
        //resize()函数用于改变vector的大小
        next.resize(key.length());
        //next[0]初始设为-1
        next[0] = -1;
        int i = 0;
        int j = -1;
        //求出主串的next数组
        while (i < key.length() - 1)
        {
            if (j == -1 || key[i] == key[j])
            {
                i++;
                j++;
                next[i] = j;
            }
            else
                j = next[j];
        }
    }
    //主函数
    int strStr(string haystack, string needle)
    {
        //模式串为空串则返回0
        if (needle.size() == 0)
            return 0;
        int i = 0, j = 0;
        //声明一个next数组vector
        vector<int> next;
        //调用KMP辅助算法求出主串的next数组
        KMP(next, needle);
        //进行主串和模式串的模式匹配
        while (j == -1 || i < haystack.size() && j < needle.size())
        {
            //匹配成功则next数组后移且模式串后移
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
            }
            //匹配失败则根据next数组跳转模式串
            else
                j = next[j];
        }
        //模式匹配成功则返回index
        if (j == needle.size())
            return i - needle.size();
        else
            //匹配失败返回的是-1.与模式串为空串的结果不同
            return -1;
    }
};
// @lc code=end
