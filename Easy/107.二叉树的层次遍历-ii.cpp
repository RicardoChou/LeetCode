/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
    //用普通的层次遍历，最后将vector进行转置即可
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> res;
        //特殊情况
        if (root == NULL)
            return res;
        //层次遍历用队列
        queue<TreeNode *> Q;
        //根节点入队
        Q.push(root);
        //队不空时循环
        while (!Q.empty())
        {
            int size = Q.size();
            //记住这个temp数组一定要在这里定义而不能在循环外定义
            vector<int> temp;
            //将每一层的节点加入temp数组，并且将下一层节点加入队列
            for (int i = 0; i < size; i++)
            {
                TreeNode *p;
                p = Q.front();
                Q.pop();
                temp.push_back(p->val);
                if (p->left)
                    Q.push(p->left);
                if (p->right)
                    Q.push(p->right);
            }
            //将temp数组加入res
            res.push_back(temp);
        }
        //将res进行转置
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
