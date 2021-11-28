//347. ǰK����ƵԪ��
//����һ���������� nums ��һ������ k �����㷵�����г���Ƶ��ǰ k �ߵ�Ԫ�ء�
//����԰� ����˳�� ���ش𰸡�

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
        //ͳ�Ƹ�Ԫ�س���Ƶ��
        unordered_map<int, int> map; //map<nums[i],��Ӧ���ֵĴ���>
        for (int i = 0;i < nums.size();i++) {
            map[nums[i]]++;
        }

        //��Ƶ������
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComparison> pri_que;   //���ȶ��ж��壺priority_queue<Type, Container, Functional>��������һ��С����
        for (unordered_map<int, int>::iterator it = map.begin();it != map.end();it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) {   //��֤�ѵĴ�СΪk
                pri_que.pop();
            }
        }

        //�õ�k����ƵԪ��
        vector<int> result(k);
        for (int i = k - 1;i >= 0;i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
        return result;
    }
};