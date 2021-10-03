class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*_dummyHead = new ListNode(0, head);
        ListNode*pre = _dummyHead;
        ListNode*fast = _dummyHead;
        while(n){
            fast = fast -> next;
            n--;
        }
        while (fast -> next){
            pre = pre -> next;
            fast = fast -> next;
        }
        ListNode*tmp = pre -> next;
        pre -> next = tmp -> next;
        head = _dummyHead -> next;
        delete tmp, _dummyHead;
        return head;

    }
};