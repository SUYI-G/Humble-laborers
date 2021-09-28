class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size();
        while (s < e){
            int middle = (e - s) / 2 + s;
            if (nums[middle] == target) return middle; 
            if (nums[middle] > target) e = middle;
            else if (nums[middle] < target) s = middle + 1;
        } 
        return -1;
    }
};