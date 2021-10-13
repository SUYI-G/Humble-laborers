//1. ����֮��
//����һ����������nums��һ������Ŀ��ֵtarget�������ڸ��������ҳ���ΪĿ��ֵtarget�����������������������ǵ������±ꡣ
//����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
//����԰�����˳�򷵻ش𰸡�

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0;i < nums.size();i++) {
            auto iter = map.find(target - nums[i]); //auto����������ʱ���ݱ�����ʼֵ�����Զ�ѡ��ƥ�������
            if (iter != map.end()) {
                return { iter->second,i };  //map<��ֵ���±�>�� it->firstΪkey��it->secondΪvalue
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};