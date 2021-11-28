//347. 前K个高频元素
//给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。
//你可以按 任意顺序 返回答案。

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include < unordered_map >

class Solution {
public:
    class myComparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //统计各元素出现频率
        unordered_map<int, int> map; //map<nums[i],对应出现的次数>
        for (int i = 0;i < nums.size();i++) {
            map[nums[i]]++;
        }

        //对频率排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pri_que;   //优先队列定义：priority_queue<Type, Container, Functional>，定义了一个小顶堆
        for (unordered_map<int, int>::iterator it = map.begin();it != map.end();it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {   //保证堆的大小为k
                pri_que.pop();
            }
        }

        //得到k个高频元素
        vector<int> result(k);
        for (int i = k - 1;i >= 0;i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};