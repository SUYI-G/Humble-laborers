//第454题.四数相加II
//给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组(i, j, k, l) 能满足：
//(1) 0 <= i, j, k, l < n
//(2) nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> mapAB;   //key:a+b的数值，value:a+b数值出现的次数
        for (int a : nums1) {
            for (int b : nums2) {
                mapAB[a + b]++;
            }
        }
        int count = 0;    //符合条件的元组个数
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