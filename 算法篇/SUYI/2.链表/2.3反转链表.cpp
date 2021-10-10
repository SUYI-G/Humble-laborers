//206. ��ת����
//���㵥�����ͷ�ڵ� head �����㷴ת���������ط�ת�������

#include <iostream>
using namespace std;

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

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = NULL;
        ListNode* temp;
        while (cur != NULL) {
            temp = cur->next;
            cur->next = pre;
            if (pre == head) {
                pre->next = NULL;
            }
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};