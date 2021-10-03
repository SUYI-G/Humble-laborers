class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*pre = nullptr;
        ListNode*cur = head;
        while (cur){
            ListNode*tmp = cur;
            cur = cur -> next;
            tmp -> next = pre;
            pre = tmp;
        }
        return pre;

    }
};