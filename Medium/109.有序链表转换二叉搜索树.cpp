/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head)
    {
        //初始right设置为NULL,也就是终节点
        return buildTree(head, NULL);
    }
    //快慢双指针遍历链表，快指针每次遍历两个节点，慢指针每次遍历一个节点
    //当快指针到达链表末尾时，慢指针指向的就是中位数节点
    ListNode *getMidNode(ListNode *left, ListNode *right)
    {
        ListNode *fastNode = left;
        ListNode *slowNode = left;
        //快指针到达尾节点，慢指针就到达中位数节点
        while (fastNode != right && fastNode->next != right)
        {
            fastNode = fastNode->next;
            fastNode = fastNode->next;
            slowNode = slowNode->next;
        }
        return slowNode;
    }
    //生成树的辅助算法
    TreeNode *buildTree(ListNode *left, ListNode *right)
    {
        if (left == right)
            return NULL;
        //获取中位数节点作为根
        ListNode *midNode = getMidNode(left, right);
        TreeNode *root = new TreeNode(midNode->val);
        //递归生成左子树
        root->left = buildTree(left, midNode);
        //递归生成左子树
        root->right = buildTree(midNode->next, right);
        return root;
    }
};
// @lc code=end
