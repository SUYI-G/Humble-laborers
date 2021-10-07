class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        // 将虚拟头结点指向head，方面后面的删除操作
        dummyHead->next = head; 
        ListNode* cur = dummyHead;
        //while中的判断条件需要注意一下
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next; // 记录临时节点
            ListNode* tmp1 = cur->next->next->next; // 记录临时节点

            cur->next = cur->next->next;    // 步骤一
            cur->next->next = tmp;          // 步骤二
            cur->next->next->next = tmp1;   // 步骤三

          // cur移动两位，准备下一轮交换
            cur = cur->next->next; 
        }
        return dummyHead->next;
    }
};
