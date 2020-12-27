/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution
{
public:
    string convertToTitle(int n)
    {
        string res = "";
        while (n > 0)
        {
            // 这里使用n-=1而不是n-1的原因是
            // 如果是n-1,假设数字是26的话，那么(26-1)%26=25----->Z
            // 但是n/26=1,会进入下一层循环，但实际上是不需要进入下一层循环的
            // 而如果使用n-=1的话，n从26变为了25,这时候n/26=0,就不需要进入下一层了
            n -= 1;
            res.push_back('A' + (n % 26));
            n /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
