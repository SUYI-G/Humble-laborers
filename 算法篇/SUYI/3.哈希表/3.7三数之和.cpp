//15. 三数之和
//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
//请你找出所有和为 0 且不重复的三元组。
//注意：答案中不可以包含重复的三元组。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() == 0) {
            return result;
        }
        sort(nums.begin(), nums.end());
        if (nums[0] > 0) {
            return result;
        }
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0;i < nums.size();i++) {
            if (i > 0 && nums[i] == nums[i - 1]) { //去重
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (right > left && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return result;
    }
};