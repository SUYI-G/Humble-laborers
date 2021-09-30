
//算法复杂度是O(n + nlogn)
class Solution {
private:
    static bool compare(int a, int b){
        return abs(a) < abs(b);
    }
public:
    vector<int> sortedSquares(vector<int>& nums) {
        sort(nums.begin(), nums.end(),compare);
        for (int i = 0; i < nums.size(); i++){
            nums[i] *= nums[i];
        }
        return nums;

    }
};

//算法复杂度是O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>res(nums.size());
        int leftPtr = 0;
        int rightPtr = nums.size() - 1;
        int Ptr = nums.size() - 1;
        while (leftPtr <= rightPtr){
            if( nums[rightPtr] * nums[rightPtr] >= nums[leftPtr] * nums[leftPtr]){
                res[Ptr] = nums[rightPtr] * nums[rightPtr];
                rightPtr--;
            }
            else{
                res[Ptr] = nums[leftPtr] * nums[leftPtr];
                leftPtr++;
            }
            Ptr--;

        }
        return res;

    }
};