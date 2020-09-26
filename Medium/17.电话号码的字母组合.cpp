/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution
{
public:
    /*
 * 回溯过程中维护一个字符串，表示已有的字母排列
 * （如果未遍历完电话号码的所有数字，则已有的字母排列是不完整的）。
 * 该字符串初始为空。每次取电话号码的一位数字，
 * 从哈希表中获得该数字对应的所有可能的字母，
 * 并将其中的一个字母插入到已有的字母排列后面，
 * 然后继续处理电话号码的后一位数字，
 * 直到处理完电话号码中的所有数字，即得到一个完整的字母排列。
 * 然后进行回退操作，遍历其余的字母排列。
 * 回溯算法用于寻找所有的可行解，如果发现一个解不可行，则会舍弃不可行的解。
 * 在这道题中，由于每个数字对应的每个字母都可能进入字母组合，
 * 因此不存在不可行的解，直接穷举所有的解即可。
 */
    vector<string> letterCombinations(string digits)
    {
        //特殊情况
        if (digits.empty())
            return {};
        //返回变量
        vector<string> res = {""};
        //一个用于表示数字与字符之间关系的字典
        string dict[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        //扫描给定数字
        for (int i = 0; i < digits.size(); i++)
        {
            vector<string> temp;
            //字符减去'0'就是对应的数字
            string str = dict[digits[i] - '0'];
            //对字符串进行遍历添加每一个组合
            for (int j = 0; j < str.size(); j++)
            {
                //回溯法，每个新扫描到的字符都要加入到之前的组合中
                for (string s : res)
                    temp.push_back(s + str[j]);
            }
            //回溯法
            res = temp;
        }
        return res;
    }
};
// @lc code=end
