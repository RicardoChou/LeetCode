/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        //O(1)空间的迭代
        Node *ptr = head;
        Node *medium = NULL;
        if (head == NULL)
            return NULL;
        // 在每一个旧节点相邻的地方创建一个新的节点，这样可以不用一个map来表示该节点是否已经创建过
        //创建相邻结点
        while (ptr != NULL)
        {
            medium = ptr->next;
            ptr->next = new Node(ptr->val); //ptr后创建新结点
            ptr->next->next = medium;
            ptr = ptr->next->next;
        }
        //遍历新链表，修改新结点的random指针
        ptr = head;
        while (ptr != NULL)
        {
            if (ptr->random != NULL)
            {
                ptr->next->random = ptr->random->next;
            }
            else
            {
                ptr->next->random = NULL;
            }
            ptr = ptr->next->next;
        }
        //修改链表结构
        Node *ptr_old_list = head;
        Node *ptr_new_list = head->next;
        Node *result = head->next;
        while (ptr_old_list != NULL)
        {
            ptr_old_list->next = ptr_old_list->next->next;
            if (ptr_new_list->next != NULL)
                ptr_new_list->next = ptr_new_list->next->next;
            else
                ptr_new_list->next = NULL;
            ptr_old_list = ptr_old_list->next;
            ptr_new_list = ptr_new_list->next;
        }
        return result;
    }
};
// @lc code=end
