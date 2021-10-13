//��454��.�������II
//�����ĸ��������� nums1��nums2��nums3 �� nums4 �����鳤�ȶ��� n ����������ж��ٸ�Ԫ��(i, j, k, l) �����㣺
//(1) 0 <= i, j, k, l < n
//(2) nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mapAB;   //key:a+b����ֵ��value:a+b��ֵ���ֵĴ���
        for (int a : nums1) {
            for (int b : nums2) {
                mapAB[a + b]++;
            }
        }
        int count = 0;    //����������Ԫ�����
        for (int c : nums3) {
            for (int d : nums4) {
                if (mapAB.find(0 - c - d) != mapAB.end()) {
                    count = count + mapAB[0 - c - d];
                }
            }
        }
        return count;
    }
};