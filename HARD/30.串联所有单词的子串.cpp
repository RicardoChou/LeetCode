/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution
{
    // 滑动窗口
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        // 特殊情况
        if (words.empty())
            return res;
        int n = s.size(), m = words.size(), w = words[0].size();
        unordered_map<string, int> tot;
        for (string &word : words)
            tot[word]++;
        // 枚举余数
        for (int i = 0; i < w; i++)
        {
            int suc = 0;
            unordered_map<string, int> window;
            for (int j = i; j + w <= n; j += w)
            {
                if (j >= i + m * w)
                {
                    string cur = s.substr(j - m * w, w);
                    window[cur]--;
                    if (window[cur] < tot[cur])
                        suc--;
                }
                string cur = s.substr(j, w);
                window[cur]++;
                if (window[cur] <= tot[cur])
                    suc++;
                if (suc == m)
                    res.push_back(j - (m - 1) * w);
            }
        }
        return res;
    }
};
// @lc code=end
