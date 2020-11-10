/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution
{
    //中间是"."的情况直接去掉，是".."时删掉它上面挨着的一个路径
    //而下面的边界条件给的一些情况中可以得知
    //如果是空的话返回"/"，如果有多个"/"只保留一个。
    //那么我们可以把路径看做是由一个或多个"/"分割开的众多子字符串
    //把它们分别提取出来一一处理即可
public:
    string simplifyPath(string path)
    {
        vector<string> v;
        int i = 0;
        int length = path.size();
        //对path进行一遍扫描，按照'/'来划分出每一个子字符串
        while (i < length)
        {
            //找出子字符串第一个非'/'的字符
            while (path[i] == '/' && i < length)
                i++;
            //如果已经扫描到尾部就break
            if (i == length)
                break;
            //子字符串的开头
            int start = i;
            //找出子字符串末尾的'/'
            while (path[i] != '/' && i < length)
                i++;
            //记住v数组存的是不包含'/'的字符串，所以需要减去1
            int end = i - 1;
            //按照'/'来划分子字符串
            string s = path.substr(start, end - start + 1);
            //模拟一个栈，如果当前子字符串是'..',并且栈不为空，那么就将栈顶弹出
            if (s == "..")
            {
                if (!v.empty())
                    v.pop_back();
            }
            //如果当前子字符串是'.'，就保持不变，不然的话就将其压入栈中
            else if (s != ".")
            {
                v.push_back(s);
            }
        }
        //栈为空则直接返回'/'
        if (v.empty())
            return "/";
        string res;
        //对栈进行扫描，用'/'来作为划分
        for (int i = 0; i < v.size(); i++)
        {
            res += "/" + v[i];
        }
        return res;
    }
};
// @lc code=end
