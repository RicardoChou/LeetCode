/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode *root)
    {
        //特殊情况
        if (root == NULL)
            return true;
        //当前节点是否是平衡的
        else if (abs(getHeight(root->left) - getHeight(root->right)) > 1)
            return false;
        else
            //左右子树也必须都是平衡的
            return isBalanced(root->left) && isBalanced(root->right);
    }
    //辅助函数用于求出每个节点的高度
    int getHeight(TreeNode *root)
    {
        //递归出口
        if (root == NULL)
            return 0;
        //每个节点的高度就是左右子树中较高的那个高度再加一
        else
            return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};
// @lc code=end
