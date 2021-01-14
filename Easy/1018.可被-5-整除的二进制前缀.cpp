/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */

// @lc code=start
class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &A)
    {
        vector<bool> res;
        int temp = 0;
        for (int i = 0; i < A.size(); i++)
        {
            // 保留余数而不是整个数是为了防止溢出
            temp = ((temp << 1) + A[i]) % 5;
            res.push_back(temp == 0);
        }
        return res;
    }
};
// @lc code=end
