//142.��������II
//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//Ϊ�˱�ʾ���������еĻ�������ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ���� 
//��� pos �� - 1�����ڸ�������û�л���ע�⣬pos ���������ڱ�ʶ�����������������Ϊ�������ݵ������С�

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
};
