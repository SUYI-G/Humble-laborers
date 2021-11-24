//225. �ö���ʵ��ջ
//�����ʹ����������ʵ��һ�������ȳ���LIFO����ջ����֧����ͨջ��ȫ�����ֲ�����push��top��pop �� empty����
//ʵ�� MyStack �ࣺ
//void push(int x) ��Ԫ�� x ѹ��ջ����
//int pop() �Ƴ�������ջ��Ԫ�ء�
//int top() ����ջ��Ԫ�ء�
//boolean empty() ���ջ�ǿյģ����� true �����򣬷��� false ��

#include <iostream>
using namespace std;
#include <queue>

//ʹ��2������
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

//ʹ��1������
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