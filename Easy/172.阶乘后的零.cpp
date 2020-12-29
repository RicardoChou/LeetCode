/*
 * @lc app=leetcode.cn id=172 lang=cpp
 *
 * [172] 阶乘后的零
 */

// @lc code=start
class Solution
{
public:
    // 先求阶乘再对0的个数进行计数会超时
    // 看了题解，是数学题。。
    // 因为末尾有多少个0其实取决于2和5，因为是2*5才能得到10，才能在末尾有一个0
    // 而一旦有一个5出现，必然会有一个2在之前出现，所以只需要统计5的个数即是尾数0的个数
    int trailingZeroes(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count += n / 5;
            n /= 5;
        }
        return count;
    }
};
// @lc code=end
