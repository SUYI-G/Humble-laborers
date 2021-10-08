//������ 02.07.�����ཻ
//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣�����������û�н��㣬���� null ��
//��ע���ཻ�Ķ�����ڽڵ�����ã������ǻ��ڽڵ��ֵ��
//���仰˵�����һ������ĵ�k���ڵ�����һ������ĵ�j���ڵ���ͬһ�ڵ㣨������ȫ��ͬ�����������������ཻ��
//����Ŀ���ݱ�֤������ʽ�ṹ�в����ڻ�����
//ע�⣬�������ؽ����������� ������ԭʼ�ṹ ��

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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != NULL) {
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL) {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (lenA > lenB) {
            for (int i = 0;i < lenA - lenB;i++) {
                if (curA != NULL) {
                    curA = curA->next;
                }
            }
        }
        else if (lenA < lenB) {
            for (int i = 0;i < lenB - lenA;i++) {
                if (curB != NULL) {
                    curB = curB->next;
                }
            }
        }
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};