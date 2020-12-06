/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> res;
        //特殊情况
        if (!root)
            return res;
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
            res.push_back(temp);
        }
        return res;
    }
};
// @lc code=end

