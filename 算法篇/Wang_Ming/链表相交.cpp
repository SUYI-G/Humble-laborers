class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        //计算两个链表的长度
        ListNode*cur = headA;
        int LenA = 0;
        while (cur){
            LenA++;
            cur = cur -> next;
        }
        int LenB = 0;
        cur = headB;
        while (cur){
            LenB++;
            cur = cur -> next;
        }
        //消去长度差的影响
        int gap;
        if (LenB > LenA){
            cur = headA;
            headA = headB;
            headB = cur;
            gap = LenB - LenA;
        }
        else{
            gap = LenA - LenB;
        }
        while (gap){
            headA = headA -> next;
            gap--;
        }
        //开始找点
        while( headA && headA != headB){
            headA = headA -> next;
            headB = headB -> next;
        }
        return headA;
    }
};