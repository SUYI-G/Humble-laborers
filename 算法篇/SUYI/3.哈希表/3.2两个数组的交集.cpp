//349. 两个数组的交集
//题意：给定两个数组，编写一个函数来计算它们的交集。
//说明：输出结果中的每个元素一定是唯一的。我们可以不考虑输出结果的顺序。

#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (int num : nums2) {
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};