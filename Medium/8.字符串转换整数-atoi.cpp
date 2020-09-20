/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string str)
    {
        //空字符串直接返回0
        if (str.size() == 0)
            return 0;
        //flag用于表示是正数还是负数
        int flag = 1, i = 0;
        long long res = 0;
        //去掉字符串前部的所有的空格
        while (i < str.size() && str[i] == ' ')
            i++;
        //确定数字的正负
        if (str[i] == '+' || str[i] == '-')
        {
            if (str[i] == '+')
            {
                flag = 1;
                i++;
            }
            else
            {
                flag = -1;
                i++;
            }
        }
        //如果遇到的是数字就可以将字符转换成相应的数字
        while (i < str.size() && str[i] >= '0' && str[i] <= '9')
        {
            //数字字符串转换成数字的公式
            res = res * 10 + str[i++] - '0';
            //用于判断正数是否超出了INT上界
            if (flag == 1 && res * flag > INT_MAX)
                return INT_MAX;
            //用于判断负数是否超出了INT下界
            if (flag == -1 && res * flag < INT_MIN)
                return INT_MIN;
        }
        return res * flag;
    }
};
// @lc code=end
