class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int leftPtr = 0;
        int rightPtr = nums.size() - 1;
        int Ptr = nums.size() - 1;
        while (rightPtr >= leftPtr){
            if(nums[rightPtr] * nums[rightPtr] >= nums[leftPtr] * nums[leftPtr]){
                result[Ptr] = nums[rightPtr] * nums[rightPtr];
                rightPtr--;
            }
            else{
                result[Ptr] = nums[leftPtr] * nums[leftPtr];
                leftPtr++;
            }
            Ptr--;
        }
        return result;

    }
};