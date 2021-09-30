//977.���������ƽ��
//����һ�����ǵݼ�˳��������������� nums������ ÿ�����ֵ�ƽ�� ��ɵ������飬Ҫ��Ҳ���ǵݼ�˳������

#include <iostream>
#include <vector>
using namespace std;

//�ҵı����ⷨ��ð������
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0;i < nums.size();i++) {
            nums[i] = nums[i] * nums[i];
        }
        for (int i = 0;i < nums.size() - 1;i++) {
            for (int j = 0;j < nums.size() - i - 1;j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        return nums;
    }
};

//��ϰ��˫ָ�뷨
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, t = nums.size() - 1;
        vector<int> result = nums;
        while (l <= r) {
            if ((nums[l] * nums[l]) >= (nums[r] * nums[r])) {
                result[t] = nums[l] * nums[l];
                t--;
                l++;
            }
            else if ((nums[l] * nums[l]) < (nums[r] * nums[r])) {
                result[t] = nums[r] * nums[r];
                t--;
                r--;
            }
        }
        return result;
    }
};