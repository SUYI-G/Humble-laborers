//27. 移除元素
//给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
//不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

//暴力解法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        for (int i = 0;i < len;i++) {
            if (nums[i] == val) {
                for (int j = 0;j < nums.size() - i - 1;j++) {
                    nums[i + j] = nums[i + j + 1];
                }
                len = len - 1;
                i = i - 1;    //注意别漏这行
            }
        }
        return len;
    }
};

//练习：双指针法
//相当于fastIndex遍历数组找到不等于val的元素，slowIndex从头依次把这些元素填入数组，覆盖原来的元素
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0;fastIndex < nums.size();fastIndex++) {
            if (nums[fastIndex] != val) {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
    }
};