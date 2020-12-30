/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution
{
public:
    // 反转二进制:与反转十进制类似，对2取模然后累加
    uint32_t reverseBits(uint32_t n)
    {
        long result = 0;
        for (int i = 0; i < 32; i++)
        {
            // 对2取模然后累加
            result = result * 2 + n % 2;
            n /= 2;
        }
        return result;
    }
};
// @lc code=end
