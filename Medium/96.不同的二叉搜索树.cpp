/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution
{
public:
    //用动态规划，具体可以看LeetCode的题解
    int numTrees(int n)
    {
        //dp数组
        vector<int> G(n + 1, 0);
        //初始条件是G[0]=G[1]=1
        G[0] = 1;
        G[1] = 1;
        //外循环是用来遍历所有数来作为根节点的
        for (int i = 2; i <= n; ++i)
        {
            //用来表示左子树的节点数
            for (int j = 1; j <= i; ++j)
            {
                //当前数字作为根节点所包含的搜索树的个数等于左子树的个数乘以右子树的个数
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};
// @lc code=end
