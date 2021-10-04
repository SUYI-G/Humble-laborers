//707. 设计链表
//设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：
//val 和 next。val 是当前节点的值，next 是指向下一个节点的指针 / 引用。
//如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0 - index 的。
//
//在链表类中实现这些功能：
//get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回 - 1。
//addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
//addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
//addAtIndex(index, val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
//deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点

#include <iostream>
#include <vector>
using namespace std;

class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int val) :val(val), next(nullptr) {}
    };

    MyLinkedList() {
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    int get(int index) {
        if (index > 0 && index < _size) {
            LinkedNode* cur = _dummyHead->next;
            while (index > 0) {
                cur = cur->next;
                index--;
            }
            return cur->val;
        }
        else {
            return -1;
        }
    }

    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size = _size + 1;
    }

    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = newNode;
        _size = _size + 1;
    }

    void addAtIndex(int index, int val) {
        if (index < _size && index>0) {
            LinkedNode* newNode = new LinkedNode(val);
            LinkedNode* cur = _dummyHead;
            while (index > 0) {
                cur = cur->next;
                index--;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            _size = _size + 1;
        }
        else if (index == _size) {
            LinkedNode* newNode = new LinkedNode(val);
            LinkedNode* cur = _dummyHead;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = newNode;
            _size = _size + 1;
        }
        else if (index < 0 || index == 1) {
            LinkedNode* newNode = new LinkedNode(val);
            newNode->next = _dummyHead->next;
            _dummyHead->next = newNode;
            _size = _size + 1;
        }
    }

    void deleteAtIndex(int index) {
        if (index > 0 && index < _size) {
            LinkedNode* cur = _dummyHead;
            LinkedNode* temp;
            while (index > 0) {
                cur = cur->next;
                index--;
            }
            temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            _size = _size - 1;
        }
    }
private:
    int _size;
    LinkedNode* _dummyHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */