/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    //全局vector
    vector<vector<int>> res;
    vector<int> temp;
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        getPath(root, sum);
        return res;
    }
    void getPath(TreeNode *root, int sum)
    {
        //空节点直接返回
        if (!root)
            return;
        //节点非空则加入temp
        temp.push_back(root->val);
        //更新sum
        sum -= root->val;
        //叶子节点并且sum减去节点值为0时说明是一条正确的路径，加入res
        if (!root->left && !root->right && sum == 0)
        {
            res.emplace_back(temp);
        }
        //深度遍历递归左右子树
        getPath(root->left, sum);
        getPath(root->right, sum);
        //跳出当前节点，返回父节点从父节点的另一棵子树遍历
        temp.pop_back();
    }
};
// @lc code=end
