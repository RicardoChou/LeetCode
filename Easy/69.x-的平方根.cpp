/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    //二分查找法
    int mySqrt(int x)
    {
        int l = 0, r = x, ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            //这里需要进行强制类型转换，不然乘方后可能会超出int的最大范围
            if ((long long)mid * mid <= x)
            {
                //转到右半部寻找
                ans = mid;
                l = mid + 1;
            }
            else
            {
                //转到左半部寻找
                r = mid - 1;
            }
        }
        return ans;
    }
};

// @lc code=end
