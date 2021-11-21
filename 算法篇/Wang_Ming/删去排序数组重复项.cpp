class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int slowPtr = 0;
        int fastPtr = 1;
        for (; fastPtr < nums.size(); fastPtr++){
            if (nums[fastPtr] != nums[slowPtr]){
                slowPtr++;
                nums[slowPtr] = nums[fastPtr];
            }
        }
        return slowPtr + 1;
    }
};