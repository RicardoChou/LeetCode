/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution
{
public:
    // 数字n中最低位的1总是对应n−1中的0。
    // 将n和n−1与运算总是能把n中最低位的1变成0 ，并保持其他位不变
    int hammingWeight(uint32_t n)
    {
        int sum = 0;
        while (n != 0)
        {
            sum++;
            n &= (n - 1);
        }
        return sum;
    }
};
// @lc code=end
