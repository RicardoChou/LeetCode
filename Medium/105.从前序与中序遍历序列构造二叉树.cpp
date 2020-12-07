/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    //从前序遍历可以确定根节点
    //再通过中序遍历可以确定左右子树
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, preorder.size() - 1);
    }
    TreeNode *buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight)
    {
        if (pLeft > pRight || iLeft > iRight)
            return NULL;
        int i;
        //在中序数组中找到根节点
        for (i = iLeft; i <= iRight; i++)
        {
            if (preorder[pLeft] == inorder[i])
                break;
        }
        TreeNode *cur = new TreeNode(preorder[pLeft]);
        //递归生成左子树
        cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
        //递归生成左子树
        cur->right = buildTree(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
        return cur;
    }
};
// @lc code=end
