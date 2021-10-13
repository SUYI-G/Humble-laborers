//1. 两数之和
//给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值target的那两个整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0;i < nums.size();i++) {
            auto iter = map.find(target - nums[i]); //auto在声明变量时根据变量初始值类型自动选择匹配的类型
            if (iter != map.end()) {
                return { iter->second,i };  //map<数值，下标>， it->first为key，it->second为value
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};