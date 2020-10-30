/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
    //快速幂算法，详解看LeetCode官方
public:
    double myPow(double x, int n)
    {
        long long N = n;
        //如果N>0，则直接返回quickMul(x, N)，否则将其作为分母
        return N > 0 ? quickMul(x, N) : 1.0 / quickMul(x, N);
    }

    double quickMul(double x, long long N)
    {
        //递归的边界
        if (N == 0)
            return 1.0;
        //用y来表示x^(n/2)，（n/2向下取整），从而不断的递归直至达到递归边界
        double y = quickMul(x, N / 2);
        //如果n是偶数，那么x^n=y*y，如果n是奇数，那么x^n=y*y*x
        return N % 2 == 0 ? y * y : y * y * x;
    }
};
// @lc code=end
