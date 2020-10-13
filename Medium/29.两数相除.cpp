/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution
{
    //这题不会，直接看的题解
    /*
    如果被除数大于或等于除数，则进行如下循环，定义变量t等于除数，定义计数p，
    当t的两倍小于等于被除数时，进行如下循环，t扩大一倍，p扩大一倍，然后更新res和m。
    因为输入的都是int型，比如被除数是-2147483648，在int范围内，当除数是-1时,
    结果就超出了int范围，需要返回INT_MAX，所以对于这种情况我们就在开始用if判定，
    将其和除数为0的情况放一起判定，返回INT_MAX。
    然后我们还要根据被除数和除数的正负来确定返回值的正负，
    这里我们采用长整型long来完成所有的计算，最后返回值乘以符号即可。
    */
public:
    int divide(int dividend, int divisor)
    {
        //除数为0或者被除数是-2147483648，在int范围内，当除数是-1时,结果就超出了int范围，需要返回INT_MAX
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        long long m = abs((long long)dividend), n = abs((long long)divisor), res = 0;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        if (n == 1)
            return sign == 1 ? m : -m;
        while (m >= n)
        {
            //定义变量t等于除数，定义计数p，
            long long t = n, p = 1;
            //当t的两倍小于等于被除数时，进行如下循环，
            //t扩大一倍，p扩大一倍，然后更新res和m。
            while (m >= (t << 1))
            {
                t <<= 1;
                p <<= 1;
            }
            res += p;
            m -= t;
        }
        //根据被除数和除数的正负来确定返回值的正负,返回值乘以符号
        return sign == 1 ? res : -res;
    }
};
// @lc code=end
