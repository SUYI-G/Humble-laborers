class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slowPtr = -1;
        int fastPtr = 0;
        for (; fastPtr < nums.size(); fastPtr++){
            if (nums[fastPtr]){
                slowPtr++;
                nums[slowPtr] = nums[fastPtr];
            }
        }
        slowPtr++;
        for(;slowPtr < nums.size(); slowPtr++){
            nums[slowPtr] = 0;
        }

    }
};