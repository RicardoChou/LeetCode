/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution
{
public:
    string intToRoman(int num)
    {
        //题目限制了整数范围是1-3999
        //将1-1000对应的罗马字符都枚举出来
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string reps[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;
        //利用贪婪算法的思想，每次找出整数中的最大值输出并减去其值，再循环下去
        for (int i = 0; i < 13; i++)
        {
            while (num >= values[i])
            {
                num -= values[i];
                res += reps[i];
            }
        }
        return res;
    }
};
// @lc code=end
