/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution
{
public:
    //没做出了，这是官方题解
    /*
    思路:
    由于最后输出的是不包含空格的字符串，所以我们其实并不需要管每一行中间在哪里会出现空格，
    而只需要将每个字符应该处在Z字形图案的哪一行确定下来就可以了，
    这里采用的方法是每当我们新字符串的指针移动到第一行的时候，就开始从上至下填充字符（也即行数递增），
    而到最后一行的时候，我们需要改变指针的方向，开始从下到上填充字符（也即行数递减）
    反思：
    其实每一行出现的空格对结果没有一点影响，因为最终输出的是不包含空格的字符串，
    只需要将每个字符应该处在Z字形图案的哪一行确定下来就可以了，
    所以Z字形图案也完全可以理解为输出字符的方式是从上至下变为从下至上再变为从上至下的循环过程即可
    */
    string convert(string s, int numRows)
    {
        //特殊情况
        if (numRows == 1)
            return s;
        //存储字符串的vector
        vector<string> rows(min(numRows, int(s.size())));
        //当前行数的指针
        int curRow = 0;
        //表明是从上至下还是从下至上
        bool goingDown = false;
        for (char c : s)
        {
            rows[curRow] += c;
            //每次扫描的字符串的第一行或者最后一行的时候，就需要改变填充字符的方向
            //也就是从上至下改为从下至上或者从下至上改为从上至下
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        string ret;
        //输出变换后的字符串
        for (string row : rows)
            ret += row;
        return ret;
    }
};
// @lc code=end
