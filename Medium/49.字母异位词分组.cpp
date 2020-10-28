/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution
{
    //遍历strs，对每一个字符串进行排序，虽然字母异位词的排列不同，但是他们排序后的结果是相同的
    //可以用一个map来存储键值，key是排序后的字符串，value是排序前的字符串
    //这样的话，因为排序后的字符串是唯一的，所以以其为key值的话唯一，而value值可以用vector表示
    //就可以在同一个key值里存储vector<string>，存储同一组字母异位词
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        //返回变量
        vector<vector<string>> res;
        //map将排序后的字符串作为key，排序前的同一组字母异位词作为value
        unordered_map<string, vector<string>> m;
        //遍历strs
        for (string &str : strs)
        {
            string temp = str;
            //将排序后的字符串作为key，排序前的同一组字母异位词作为value(vector<string>)
            sort(temp.begin(), temp.end());
            m[temp].push_back(str);
        }
        for (auto n : m)
        {
            //将排序前的同一组字母异位词插入返回变量中
            res.push_back(n.second);
        }
        return res;
    }
};
// @lc code=end
