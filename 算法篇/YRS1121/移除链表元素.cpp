//第一种方法，不使用虚拟的头结点，分情况进行讨论
class Solution
{
public:
  ListNode* removeElements(ListNode* head, int val){
    //删除头结点
    while(head!=Null && head->val==val){
      ListNode* tmp = head;
      head = head->next;
      delete tmp;
    }
    
    //删除非头结点
    ListNode* cur = head;         //用指针进行遍历
    while(cur!=NULL && cur->next!=NULL)
      if (cur->next->var==var)
      {
        ListNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
      }
      else
      {
       cur = cur->next; 
      }
    return head;  
  }
};


//第二种方法，使用虚拟的头结点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if(cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};
