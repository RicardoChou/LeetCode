/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution
{
public:
    //设 n 阶格雷码集合为 G(n)，则 G(n+1) 阶格雷码为：
    //给 G(n) 阶格雷码每个元素二进制形式前面添加 0，得到 G'(n)
    //设 G(n) 集合倒序（镜像）为 R(n)，给 R(n)每个元素二进制形式前面添加 1，得到 R'(n)
    //G(n+1)=G′(n)∪R′(n) 拼接两个集合即可得到下一阶格雷码。
    vector<int> grayCode(int n)
    {
        vector<int> res;
        //格雷码默认以0开头
        res.push_back(0);
        int head = 1;
        for (int i = 0; i < n; i++)
        {
            //计算R'(n)
            for (int j = res.size() - 1; j >= 0; j--)
                res.push_back(head + res[j]);
            head <<= 1;
        }
        return res;
    }
};
// @lc code=end
