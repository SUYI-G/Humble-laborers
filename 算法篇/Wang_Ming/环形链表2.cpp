class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode*fastPtr = head -> next;
        ListNode*slowPtr = head;
        while (fastPtr != NULL && fastPtr -> next != NULL && fastPtr != slowPtr){
            fastPtr = fastPtr -> next -> next;
            slowPtr = slowPtr -> next;
        }
        if (fastPtr == NULL || fastPtr -> next == NULL) return NULL;
        fastPtr = fastPtr -> next;
        slowPtr = head;
        while (fastPtr != slowPtr){
            fastPtr = fastPtr -> next;
            slowPtr = slowPtr -> next;
        }
        return fastPtr;        
    }
};