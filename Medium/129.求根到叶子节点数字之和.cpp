/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根到叶子节点数字之和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
    // 深搜
    int dfs(TreeNode *root, int rootSum)
    {
        // 空节点返回0
        if (!root)
            return 0;
        // 之前的值乘以10加上当前节点的值得到新的sum
        int sum = rootSum * 10 + root->val;
        // 叶子节点直接返回sum
        if (!root->left && !root->right)
            return sum;
        else
            // 非叶子节点递归计算子树的值
            return dfs(root->left, sum) + dfs(root->right, sum);
    }
};
// @lc code=end
