/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;
        while (x != 0)
        {
            /*INT_MAX是C++中表示int最大值的常量
            因为下面是需要res*10来进行反转，所以首先要判断res取正后是否大于INT_MAX/10，如果大于的话
            说明反转之后超出了int的最大值，按照题目要求直接返回0
            */
            if (abs(res) > INT_MAX / 10)
                return 0;
            //一位一位的进行反转，x%10相当于取最右的那一位
            res = res * 10 + x % 10;
            //x/10相当于去掉最右一位
            x /= 10;
        }
        return res;
    }
};
// @lc code=end
