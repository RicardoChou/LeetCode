/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        //初始就是一个1
        if (n == 1)
            return "1";
        //使用递归来一层一层往前推
        string previous = countAndSay(n - 1), result = "";
        //count用来计数，递归时候与前一个进行比较看是否是相同的数组，相同则需要计数+1
        int count = 1;
        for (int i = 0; i < previous.length(); i++)
        {
            //比如previous是111221时，111部分会让count=3，此时i在第三个1处
            if (previous[i] == previous[i + 1])
            {
                count++;
            }
            else
            {
                //result会从空变成“31”（当i在第三个1处时）
                result += to_string(count) + previous[i];
                //由于i在第三个1处时，i+1处的值为2，1 != 2，所以count重新变成1
                count = 1;
            }
        }
        return result;
    }
};

// @lc code=end
