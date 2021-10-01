//209.������С��������
//����һ������ n ���������������һ�������� s ���ҳ���������������� �� s �ĳ�����С�� ���� �����飬
//�������䳤�ȡ���������ڷ��������������飬���� 0��

#include <iostream>
#include <vector>
using namespace std;

//�ҵı����ⷨ���ҵ���ÿ��Ԫ��Ϊ�������һ��Ԫ�صķ�����������������飬Ȼ�󷵻����г�����̵�������ĳ���
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size()+1, sum = 0;
        for (int i = 0;i < nums.size();i++) {
            sum = 0;
            for (int j = 0;j < nums.size() - i;j++) {
                sum = sum + nums[i + j];
                if (sum >= target) {
                    if (minLen >= j + 1) {
                        minLen = j + 1;
                    }
                    break;
                }
            }
        }
        if (minLen == nums.size()+1) {    //û�з���������������ͷ���0
            minLen = 0;
        }
        return minLen;
    }
};

////�����ⷨ����
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int minLen = nums.size()+1, sum = 0;
//        for (int i = 0;i < nums.size();i++) {
//            cout << "��" << i << "��:";
//            sum = 0;
//            for (int j = 0;j < nums.size() - i;j++) {
//                sum = sum + nums[i + j];
//                if (sum >= target) {
//                    if (minLen >= j + 1) {
//                        minLen = j + 1;
//                        cout << "����:";
//                        for (int t = 0;t < j + 1;t++) {
//                            cout << nums[i + t] << " ";
//                        }
//                        cout << ", minLen:" << minLen << " ";
//                    }
//                    break;
//                }
//            }
//            cout << endl;
//        }
//        if (minLen == nums.size()+1) {    //û�з���������������ͷ���0
//            minLen = 0;
//        }
//        return minLen;
//    }
//};

//��ϰ����������
class Solution2 {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLen = nums.size() + 1, sum = 0, l = 0;
        for (int r = 0;r < nums.size();r++) {
            sum = sum + nums[r];
            while (sum >= target) {
                if ((l - r + 1) < minLen) {
                    minLen = r - l + 1;
                }
                sum = sum - nums[l];
                l++;
            }
        }
        return minLen;
    }
};

void main() {
    vector<int> a = { 1,1,2,3,2,6 };
    Solution solution;
    cout << "Solution:" << solution.minSubArrayLen(7, a) << endl;
    Solution solution2;
    cout << "Solution2:" << solution2.minSubArrayLen(7, a) << endl;
}