/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        //特殊情况
        if (s.size() <= 1)
            return s;
        //设置len，maxlen，begin的初始值
        int len = s.size(), maxlen = 0, begin = 0;
        //以每个字符为中心扫描调用辅助函数
        for (int i = 0; i < len - 1; ++i)
        {
            //两种可能：1.字符串是奇数个字符，则需要将自己与自己比较
            //2.字符串是偶数个字符，则需要将自己与下一个字符比较
            searchPalindrome(s, i, i, begin, maxlen);
            searchPalindrome(s, i, i + 1, begin, maxlen);
        }
        return s.substr(begin, maxlen);
    }
    /*辅助函数：以每个字符为中心，向两边扩散，类似窗口模式
      但是是扩大窗口而不是滑动窗口。若窗口的边界字符相同，那就继续扩大
      若不相同，就移到下个字符重新开始扩散
    */
    void searchPalindrome(string s, int left, int right, int &begin, int &maxlen)
    {
        //没有达到两个边界并且新纳入的两个字符是相同的，就继续两边同时扩大
        while (left >= 0 && right <= s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        //每次调用辅助函数都要刷新maxlen
        if (maxlen < right - left - 1)
        {
            //begin等于这次扫描得到的最长回文子串的左边界，是用于最后进行字符串截取的
            //因为上述while最后一次循环内部left--了，所以如果之后跳出循环
            //那么该left所指向的字符不属于回文子串
            //所以begin等于left+1才是指向回文子串的左边界
            begin = left + 1;
            maxlen = right - left - 1;
        }
    }
};
// @lc code=end
