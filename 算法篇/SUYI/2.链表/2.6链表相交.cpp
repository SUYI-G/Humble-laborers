//面试题 02.07.链表相交
//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
//请注意相交的定义基于节点的引用，而不是基于节点的值。
//换句话说，如果一个链表的第k个节点与另一个链表的第j个节点是同一节点（引用完全相同），则这两个链表相交。
//（题目数据保证整个链式结构中不存在环。）
//注意，函数返回结果后，链表必须 保持其原始结构 。

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