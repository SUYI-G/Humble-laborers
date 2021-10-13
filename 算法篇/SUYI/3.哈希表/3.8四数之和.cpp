//18. 四数之和
//给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
//请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] ：
//(1) 0 <= a, b, c, d  < n
//(2) a、b、c 和 d 互不相同
//(3) nums[a] + nums[b] + nums[c] + nums[d] == target
//你可以按 任意顺序 返回答案 。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() == 0) {
            return result;
        }
        sort(nums.begin(), nums.end());
        for (int k = 0;k < nums.size(); k++) {
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1;i < nums.size();i++) {
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    if (nums[k] + nums[i] + nums[left] + nums[right] > target) {
                        right--;
                    }
                    else if (nums[k] + nums[i] + nums[left] + nums[right] < target) {
                        left++;
                    }
                    else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        while (right > left && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        while (right > left && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        right--;
                        left++;
                    }
                }
            }
        }
        return result;
    }
};