/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution
{
    //模拟竖式乘法:如果num1和num2之一是 0，则直接将0作为结果返回即可。
    //如果num1和num2都不是 0，则可以通过模拟「竖式乘法」的方法计算乘积。
    //从右往左遍历乘数，将乘数的每一位与被乘数相乘得到对应的结果，再将每次得到的结果累加。
    //这道题中，被乘数是num1，乘数是num2。
    //需要注意的是，num2除了最低位以外，其余的每一位的运算结果都需要补 0。
public:
    string multiply(string num1, string num2)
    {
        //乘数和被乘数有一个为0则直接返回0
        if (num1 == "0" || num2 == "0")
            return "0";
        string res = "0";
        int m = num1.size(), n = num2.size();
        for (int i = n - 1; i >= 0; i--)
        {
            string cur;
            //用于保存进位
            int add = 0;
            //除了乘数的最低位外，其余的运算低位都需要补0
            for (int j = n - 1; j > i; j--)
            {
                cur.push_back(0);
            }
            //用被乘数num1的每一位与乘数num1的固定位相乘
            int y = num2.at(i) - '0';
            for (int j = m - 1; j >= 0; j--)
            {
                int x = num1[j] - '0';
                int product = x * y + add;
                cur.push_back(product % 10);
                //进位
                add = product / 10;
            }
            //进位不为0，低位保留，高位上传至下一次运算
            while (add != 0)
            {
                cur.push_back(add % 10);
                add /= 10;
            }
            //运算是push_back函数，是从末尾添加，所以高位和低位是反过来的
            reverse(cur.begin(), cur.end());
            //将数值型转换成字符串
            for (auto &c : cur)
            {
                c += '0';
            }
            //字符串相加
            res = addStrings(res, cur);
        }
        return res;
    }
    //字符串相加的辅助函数
    string addStrings(string &num1, string &num2)
    {
        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
        //返回变量
        string res;
        //最后一个add!=0的条件，是为了让最后一个高位的1也能保存进去
        while (i >= 0 || j >= 0 || add != 0)
        {
            //将字符变成int型变量
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            //对应位相加
            int temp = x + y + add;
            //保留低位，进位留到高位继续相加
            res.push_back(temp % 10);
            //进位保留，加到高位
            add = temp / 10;
            i--;
            j--;
        }
        reverse(res.begin(), res.end());
        for (auto &c : res)
        {
            c += '0';
        }
        return res;
    }
};
// @lc code=end
