class Solution {
private:
   static bool cmp(pair<int, int>&a, pair<int, int>&b){
        return a.second > b.second;

    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n;
        vector<pair<int, int>> table;
        vector<int> res;
        int i;
        for (i = 0; i < nums.size(); i++){
            if (i == 0) n = 1;
            else if (nums[i] != nums[i - 1]){
                table.push_back(pair<int,int>(nums[i - 1], n));
                n = 1;
            }
            else{
                n++;
            }
        }
        table.push_back(pair<int, int>(nums[i - 1], n));
        sort(table.begin(), table.end(),cmp);
        for (int i = 0; i < k; i++){
            res.push_back(table[i].first);
        }
        return res;
    }
};