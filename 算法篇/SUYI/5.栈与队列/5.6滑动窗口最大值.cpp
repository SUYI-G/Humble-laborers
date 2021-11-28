//239. 滑动窗口最大值
//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
//你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//返回滑动窗口中的最大值。

#include <iostream>
using namespace std;
#include <vector>
#include <deque>

class Solution {
private:
    class MyQueue {  //单调递减队列
    public:
        deque<int> que;
        void pop(int value) { //当弹出元素等于队列的出口元素时弹出
            if (que.front() == value && !que.empty()) {
                que.pop_front();
            }
        }
        void push(int value) { //当push的元素大于入口元素，则弹出入口元素，直到入口元素大于要push的元素
            while (!que.empty() && que.back() < value) {
                que.pop_back();
            }
            que.push_back(value);
        }
        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> result;
        for (int i = 0;i < k;i++) {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = 0;i < nums.size() - k;i++) {
            que.pop(nums[i]);
            que.push(nums[i + k]);
            result.push_back(que.front());
        }
        return result;
    }
};