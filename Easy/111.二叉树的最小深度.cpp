/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int minDepth(TreeNode *root)
    {
        //退出递归的条件
        if (root == NULL)
            return 0;
        //退出递归的条件
        if (root->left == NULL && root->right == NULL)
            return 1;
        //初始化最小深度
        int min_Depth = INT_MAX;
        //递归左子树求最小深度
        if (root->left)
            min_Depth = min(minDepth(root->left), min_Depth);
        //递归右子树求最小深度
        if (root->right)
            min_Depth = min(minDepth(root->right), min_Depth);
        return min_Depth + 1;
    }
};
// @lc code=end
