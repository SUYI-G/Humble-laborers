/*203. �Ƴ�����Ԫ��
����һ�������ͷ�ڵ� head ��һ������ val ������ɾ���������������� Node.val == val �Ľڵ㣬������ �µ�ͷ�ڵ� ��*/

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

//��ͨ����
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* tmp;
        ListNode* tmp1 = head;
        while (head->val == val) {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        while (tmp1 != NULL && tmp1->next != NULL) {
            if (tmp1->next->val == val) {
                tmp = tmp1->next;
                tmp1->next = tmp1->next->next;
                delete tmp;
            }
            else {
                tmp1 = tmp1->next;
            }
        }
        return head;
    }
};

//��������ͷ���
class Solution1 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while (cur->next != NULL) {
            if (cur->next == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};