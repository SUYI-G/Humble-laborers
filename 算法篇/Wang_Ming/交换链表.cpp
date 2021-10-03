class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        ListNode*_dummyHead = new ListNode(0, head);
        ListNode*pre = _dummyHead;
        ListNode*cur = head;
        while (cur != nullptr && cur -> next != nullptr){
            // cout << cur -> val;
            ListNode*tmp1 = cur;
            ListNode*tmp2 = cur -> next;
            cur = tmp2 -> next;
            pre -> next = tmp2;
            tmp2 -> next =tmp1;
            pre = tmp1;
        }
        // cout << "测试";
        pre -> next = cur;
        head = _dummyHead -> next;
        
        delete _dummyHead;
        // cout << "测试";
        // cout << head ->val;
        return head;

    }
};