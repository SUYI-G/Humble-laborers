//209.长度最小的子数组
//给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，
//并返回其长度。如果不存在符合条件的子数组，返回 0。

#include <iostream>
#include <vector>
using namespace std;

//我的暴力解法：找到以每个元素为子数组第一个元素的符合条件的最短子数组，然后返回其中长度最短的子数组的长度
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size()+1, sum = 0;
        for (int i = 0;i < nums.size();i++) {
            sum = 0;
            for (int j = 0;j < nums.size() - i;j++) {
                sum = sum + nums[i + j];
                if (sum >= target) {
                    if (minLen >= j + 1) {
                        minLen = j + 1;
                    }
                    break;
                }
            }
        }
        if (minLen == nums.size()+1) {    //没有符合条件的子数组就返回0
            minLen = 0;
        }
        return minLen;
    }
};

////暴力解法调试
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int minLen = nums.size()+1, sum = 0;
//        for (int i = 0;i < nums.size();i++) {
//            cout << "第" << i << "个:";
//            sum = 0;
//            for (int j = 0;j < nums.size() - i;j++) {
//                sum = sum + nums[i + j];
//                if (sum >= target) {
//                    if (minLen >= j + 1) {
//                        minLen = j + 1;
//                        cout << "数组:";
//                        for (int t = 0;t < j + 1;t++) {
//                            cout << nums[i + t] << " ";
//                        }
//                        cout << ", minLen:" << minLen << " ";
//                    }
//                    break;
//                }
//            }
//            cout << endl;
//        }
//        if (minLen == nums.size()+1) {    //没有符合条件的子数组就返回0
//            minLen = 0;
//        }
//        return minLen;
//    }
//};

//练习：滑动窗口
class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size() + 1, sum = 0, l = 0;
        for (int r = 0;r < nums.size();r++) {
            sum = sum + nums[r];
            while (sum >= target) {
                if ((l - r + 1) < minLen) {
                    minLen = r - l + 1;
                }
                sum = sum - nums[l];
                l++;
            }
        }
        return minLen;
    }
};

void main() {
    vector<int> a = { 1,1,2,3,2,6 };
    Solution solution;
    cout << "Solution:" << solution.minSubArrayLen(7, a) << endl;
    Solution solution2;
    cout << "Solution2:" << solution2.minSubArrayLen(7, a) << endl;
}