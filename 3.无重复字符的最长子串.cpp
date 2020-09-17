/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    /*
   考虑用一种滑动窗口机制来扫描字符串，我们设置两个指针left和right
   right指针作为工作指针和窗口的右边界，left指针指向窗口的左边界的前一位
   这样窗口的大小也就确定了（right-left）
   这里我们利用HashMap来建立字符和其出现位置之间的映射
   是将字符出现的所有位置都记录还是只记录一个位置呢？
    1.若right指针指向的字符在之前没有出现过，那将该字符与HashMap建立映射，并直接扩大右边界即可
    2.若right指针指向的字符在之前出现过，那么分两种情况：
        1）该字符在窗口外，这时候我们就不用理会，直接扩大右窗口即可
        2）该字符在窗口内，那么我们就需要将该字符从窗口内去除，而去除的方法并不需要left指针从左到右遍历，
        而只需要直接移动到该字符最后出现的位置即可
        所以其实我们只要记录字符最后一次出现的位置就可以了。
        定义一个len用来记录最长无重复子串的长度，因为left指向窗口的前一位，所以初始化就是-1，
        每次更新left都让left指向重复字符，这样保证了left始终为当前边界的前一个位置
    */
    int lengthOfLongestSubstring(string s)
    {
        //left指向滑动窗口的前一位，所以初始化就是-1
        int len = 0, left = -1;
        //利用HashMap来建立字符和其出现位置之间的映射
        unordered_map<char, int> m;
        //right始终指向右边界
        for (int right = 0; right < s.size(); right++)
        {
            //如果right指针扫描到的字符出现过并且该字符在左边界的右边，也就是在窗口内
            //那么就需要将左边界指针指向该字符在窗口内第一次出现的位置（也就是滑动了窗口）
            //这样的话就等于是将窗口内的该字符移出窗口了
            if (m.count(s[right]) && m[s[right]] > left)
                left = m[s[right]];
            //如果right指针扫描到的字符没有出现过或者出现过但是该字符在左边界的左边也就是在窗口外
            //那就不用管左边界指针，直接扩大右边界即可
            m[s[right]] = right;
            //每次扫描都要更新最大的窗口大小
            len = max(len, right - left);
        }
        return len;
    }
};
// @lc code=end
