/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--)
        {
            //如果扫描到的那个数字是9，则当前这个数字直接置为0，并且继续向前扫描
            if (digits[i] == 9)
                digits[i] = 0;
            else
            {
                //如果扫描到的这个数字不是9，则说明加1之后不会再进位，可以直接返回
                digits[i] += 1;
                return digits;
            }
        }
        //一种特殊情况，如果数组只有一个整数9，则经过上述循环之后会变为[0]
        //但是正确结果是[1,0]，所以需要在数组开头插入1
        if (digits[0] == 0)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
// @lc code=end
