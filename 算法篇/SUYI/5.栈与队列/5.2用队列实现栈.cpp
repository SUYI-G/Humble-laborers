//225. 用队列实现栈
//请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
//实现 MyStack 类：
//void push(int x) 将元素 x 压入栈顶。
//int pop() 移除并返回栈顶元素。
//int top() 返回栈顶元素。
//boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。

#include <iostream>
using namespace std;
#include <queue>

//使用2个队列
class MyStack1 {
public:
    queue<int> que1;
    queue<int> que2;
    MyStack1() {

    }

    void push(int x) {
        que1.push(x);
    }

    int pop() {
        for (int i = que1.size();i > 1;i--) {
            que2.push(que1.front());
            que1.pop();
        }
        int result = que1.front();
        que1.pop();
        while (!que2.empty()) {
            que1.push(que2.front());
            que2.pop();
        }
        return result;
    }

    int top() {
        return que1.back();
    }

    bool empty() {
        return que1.empty();
    }
};

//使用1个队列
class MyStack2 {
public:
    queue<int> que;

    MyStack2() {

    }

    void push(int x) {
        que.push(x);
    }

    int pop() {
        int size = que.size();
        for (size;size > 1;size--) {
            que.push(que.front());
            que.pop();
        }
        int result = que.front();
        que.pop();
        return result;
    }

    int top() {
        return que.back();
    }

    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */