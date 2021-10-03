/*203. 移除链表元素
给你一个链表的头节点 head 和一个*/整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* tmp;
        ListNode* tmp1 = head;
        while (head->val == val) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        while (tmp1 != NULL && tmp1->next != NULL) {
            if (tmp1->next->val == val) {
                tmp = tmp1->next;
                tmp1->next = tmp1->next->next;
                delete tmp;
            }
            else {
                tmp1 = tmp1->next;
            }
        }
        return head;
    }
};