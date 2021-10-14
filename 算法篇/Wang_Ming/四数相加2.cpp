class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>map;
        for (int i = 0; i < nums1.size(); i++){
            for (int j = 0; j < nums2.size(); j++){
                if (map.find(nums1[i] + nums2[j]) != map.end()) map.find(nums1[i] + nums2[j]) -> second ++;
                else map.insert(pair<int, int>(nums1[i] + nums2[j], 1));
            }
        }
        int num = 0;
        for (int i = 0; i < nums3.size(); i++){
            for (int j = 0; j < nums4.size(); j++){
                if (map.find(- nums3[i] - nums4[j]) != map.end()) num +=map.find(-nums3[i] - nums4[j]) -> second;
            }
        }
        return num;

    }
};