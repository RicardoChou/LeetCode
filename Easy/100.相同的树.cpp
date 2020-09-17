/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    //递归即可
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        //设置一个bool类型变量用于进行最终的返回
        bool flag;
        //作为最后的跳出递归语句
        if (p == NULL && q == NULL)
            return true;
        //一个为空一个不为空则返回false
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL))
            return false;
        //如果都不为空且值不相同则返回fasle
        if (p != NULL && q != NULL && p->val != q->val)
            return false;
        //两个节点均不为空且值相同，则递归进行左子树与右子树的判断
        if (p->val == q->val)
            flag = isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        //最终返回
        return flag;
    }
};
// @lc code=end
