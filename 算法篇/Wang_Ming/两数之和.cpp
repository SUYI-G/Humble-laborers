class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int>map;
        for (int i = 0; i < nums.size(); i++){
            if (map.find(target - nums[i] )!= map.end()){
                res.push_back(map.find(target - nums[i]) -> second);
                res.push_back(i);
                return res;
            }
            map.insert(pair<int, int>(nums[i], i));
        }
        return res;

    }
};