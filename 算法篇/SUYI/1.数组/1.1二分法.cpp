//题目：704.二分查找
//给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
//写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 - 1。

//写法1：[left, right]
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] > target) { //target下标在[l,m-1]
                r = m-1;
            }
            else if (nums[m] < target) {    //target下标在[m+1,r]
                l = m+1;
            }
            else {
                return m;
            }
        }
        return -1;
    }
};

//写法2：[left, right）
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] > target) { //target下标在[l,m)
                r = m;
            }
            else if (nums[m] < target) {   //target下标在[m+1,r)
                l = m + 1;
            }
            else {
                return m;
            }
        }
        return -1;
    }
}