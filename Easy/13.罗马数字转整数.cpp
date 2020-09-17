/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution
{
public:
    int romanToInt(string s)
    {
        int res = 0;
        //unordered_map是一种无序map，用来存放key和对应的value，key和value的类型可以是不同的
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < s.size(); ++i)
        {
            //s[i]就是题目给定的罗马字符，将其作为key值，从unordered_map中取出对应的value数字
            int val = m[s[i]];
            //1.如果扫描到的字符是最后一个字符，也就是在右边的话，那是要加上去的
            //2.如果扫描到的字符是右边的小于等于左边的，那么也是要加上去的
            if (i == s.size() - 1 || m[s[i + 1]] <= m[s[i]])
                res += val;
            //如果扫描到的字符是右边的比左边的大的话，那么就要用右边的减去左边的
            else
                res -= val;
        }
        return res;
    }
};
// @lc code=end
