/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    //非递归中序遍历整个二叉搜索树，在遍历过程中比较前一个节点是否小于当前节点
    bool isValidBST(TreeNode *root)
    {
        //辅助栈
        stack<TreeNode *> stack;
        //用该变量来表示前一个节点的值
        long long pre = (long long)INT_MIN - 1;
        //栈非空或当前节点非空时循环
        while (!stack.empty() || root != NULL)
        {
            //当前节点非空时压入栈中，并不断往左子树走到最左下
            while (root != NULL)
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            // 如果中序遍历得到的节点的值小于等于前一个pre，说明不是二叉搜索树
            if (root->val <= pre)
            {
                return false;
            }
            pre = root->val;
            root = root->right;
        }
        return true;
    }
};
// @lc code=end
