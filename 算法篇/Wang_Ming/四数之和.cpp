class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i] > 0 && nums[i] > target) break;
            for (int j = i + 1; j < nums.size() - 2; j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if (nums[i] + nums[j] > 0 && nums[i] + nums[j] > target) continue;
                int k = j + 1;
                int l = nums.size() - 1;
                while (k < l){
                    if (long(nums[k]) + nums[l] + nums[i] + nums[j] < target){
                        k++;
                    }
                    else if (long(nums[k]) + nums[l] + nums[i] + nums[j] > target) l--;
                    else{
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(k < nums.size() - 1 && nums[k + 1] == nums[k]) k++;
                        while (l > k && nums[l - 1] == nums[l]) l--;
                        k++;
                        l--;
                    }
                }

            }
        }
        return res;
    }
};