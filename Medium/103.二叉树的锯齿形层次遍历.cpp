/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
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
    //普通的层次遍历的基础上，行数从1开始，每遍历一行行数加一
    //偶数行的temp进行转置即可
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        //特殊情况
        if (!root)
            return res;
        //行数初始设为1
        int level = 1;
        queue<TreeNode *> Q;
        //根节点入队
        Q.push(root);
        //队不空时循环
        while (!Q.empty())
        {
            //每一行的节点数
            int size = Q.size();
            //存储每一行节点的值
            vector<int> temp;
            for (int i = 0; i < size; i++)
            {
                TreeNode *p = Q.front();
                Q.pop();
                temp.push_back(p->val);
                if (p->left)
                    Q.push(p->left);
                if (p->right)
                    Q.push(p->right);
            }
            //偶数层的temp需要进行转置
            if (level % 2 == 0)
                reverse(temp.begin(), temp.end());
            res.push_back(temp);
            //遍历每一行则行数加一
            level++;
        }
        return res;
    }
};
// @lc code=end
