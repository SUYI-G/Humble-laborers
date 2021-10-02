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
        ListNode*NewHead = new ListNode(0, head);
        ListNode*pre = NewHead;
        ListNode*ptr = head;
        while (ptr){
            if (ptr -> val == val){
                ListNode*tmp = ptr;
                ptr = ptr -> next;
                pre -> next = ptr;
                delete tmp;
                
            }
            else{
                pre = ptr;
                ptr = ptr -> next;
            }
        }
        head = NewHead -> next;
        delete NewHead;
        return head;
    }
};