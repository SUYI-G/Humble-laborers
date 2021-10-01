//算法的时间复杂度O(n)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = INT_MAX;
        int len = 0;
        int sum = 0;
        int slow = 0;
        int fast = 0;
        while (fast < nums.size()){
            if (sum + nums[fast] >= target){
                minLen = min(minLen, len+1);
                
                len--;
                sum -= nums[slow++];
                continue;
            }
            else{
            sum += nums[fast];
            len++;
            fast++;
            }
            
        }
        if (minLen < INT_MAX) return minLen;
        else return 0;
    }
};
