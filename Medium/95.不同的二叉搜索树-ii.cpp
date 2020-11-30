/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    //用递归即可
    //二叉搜索树:左子树的所有节点都小于根节点，右子树所有节点都大于根节点
    //遍历到n的所有的数，以每个数为根，递归将小于它的数作为它的左子树，大于它的数作为右子树
public:
    vector<TreeNode *> generateTrees(int start, int end)
    {
        //退出递归的条件
        if (start > end)
            return {nullptr};
        //return vector
        vector<TreeNode *> allTrees;
        //遍历每个数字作为根节点
        for (int i = start; i <= end; i++)
        {
            //所有的左子树
            vector<TreeNode *> leftTrees = generateTrees(start, i - 1);
            //所有的右子树
            vector<TreeNode *> rightTrees = generateTrees(i + 1, end);
            //从所有的左子树和右子树中分别取出一棵作为这一次生成树的左右子树
            for (auto &leftTree : leftTrees)
            {
                for (auto &rightTree : rightTrees)
                {
                    //根节点
                    TreeNode *curRootNode = new TreeNode(i);
                    curRootNode->left = leftTree;
                    curRootNode->right = rightTree;
                    //emplace_back是生成并插入vector最后
                    //push_back只是插入vector最后
                    allTrees.emplace_back(curRootNode);
                }
            }
        }
        return allTrees;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return {};
        return generateTrees(1, n);
    }
};
// @lc code=end
