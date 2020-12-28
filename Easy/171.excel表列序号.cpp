/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */

// @lc code=start
class Solution
{
public:
    // 第168题相反的过程
    int titleToNumber(string s)
    {
        // 返回变量
        int res = 0;
        // 扫描整个字符串
        for (int i = 0; i < s.size(); i++)
        {
            // 将每一位都转换成对应的数字,因为A表示1，所以减法后需要加1
            int temp = s[i] - 'A' + 1;
            //说白了这题就是二十六进制转换，每26位要向前进一位
            res = res * 26 + temp;
        }
        return res;
    }
};
// @lc code=end
