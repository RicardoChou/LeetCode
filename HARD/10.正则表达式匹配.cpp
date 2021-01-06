/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution
{
    // 没做出来，直接看的官方题解
    // 用的动态规划，写起来太复杂了，想复习直接看官方题解吧
public:
    bool isMatch(string s, string p)
    {
        int m = s.size();
        int n = p.size();

        // 辅助函数match用于进行两个字符串中字符匹配的
        auto matches = [&](int i, int j) {
            if (i == 0)
            {
                return false;
            }
            if (p[j - 1] == '.')
            {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        // 边界条件
        f[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // 如果是*号的话，那么可以匹配0至n次
                if (p[j - 1] == '*')
                {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1))
                    {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                // 如果不是*号，那么就要一对一匹配
                else
                {
                    if (matches(i, j))
                    {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
        }
        return f[m][n];
    }
};
// @lc code=end
