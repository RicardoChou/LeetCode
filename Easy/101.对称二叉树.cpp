/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    //是镜像对称的树得话，可以理解为同一个根节点的左右子树是相同的
    //也就是同一个根节点的左子树的最左子节点和右子树的最右子节点是相同的，可以用递归的方法
    bool isEqual(TreeNode *p, TreeNode *q)
    {
        //都为NULL则相同
        if (!p && !q)
            return true;
        //一个为空一个不为空
        if (!p || !q)
            return false;
        //都不为空则要求值相等，并且p的左子树和q的右子树也要对称，p的右子树和q的左子树也要对称
        return p->val == q->val && isEqual(p->left, q->right) && isEqual(p->right, q->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        //从根节点开始
        return isEqual(root, root);
    }
};
// @lc code=end
