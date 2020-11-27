/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution
{
public:
    vector<string> ans;
    void backtrace(string &s, int cnt, int index, string &str)
    {
        if (cnt == 4 || index == s.size()) //如果已经有了四段或者已经扫描到字符串最后了
        {
            if (cnt == 4 && index == s.size())                //如果扫描到字符串最后并且已经有四段了，说明是合法IP地址
                ans.push_back(str.substr(0, str.size() - 1)); //插入返回vector中
            return;
        }
        for (int i = 1; i <= 3; i++) //每一小段整数最多不超过三位数
        {
            //下面三个判断都是为了进行剪枝优化
            if (index + i > s.size()) //如果当前位置加上i之后超过了字符串的长度，则退出
                return;
            if (s[index] == '0' && i != 1) //如果这一段整数超过一位，就不能含有前导0
                return;
            if (i == 3 && s.substr(index, i) > "255") //每一段整数不能大于255
                return;
            str += s.substr(index, i);               //选中当前字符则获取每一段整数
            str.push_back('.');                      //每一段用"."来分割
            backtrace(s, cnt + 1, index + i, str);   //递归回溯查找下一段
            str = str.substr(0, str.size() - i - 1); //这一行代码是为了递归回溯之后不合法的IP地址给去掉
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        string str = "";
        backtrace(s, 0, 0, str);
        return ans;
    }
};
// @lc code=end
