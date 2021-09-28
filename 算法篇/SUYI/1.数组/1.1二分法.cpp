//��Ŀ��704.���ֲ���
//����һ�� n ��Ԫ������ģ������������� nums ��һ��Ŀ��ֵ target  ��
//дһ���������� nums �е� target�����Ŀ��ֵ���ڷ����±꣬���򷵻� - 1��

//д��1��[left, right]
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] > target) { //target�±���[l,m-1]
                r = m-1;
            }
            else if (nums[m] < target) {    //target�±���[m+1,r]
                l = m+1;
            }
            else {
                return m;
            }
        }
        return -1;
    }
};

//д��2��[left, right��
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] > target) { //target�±���[l,m)
                r = m;
            }
            else if (nums[m] < target) {   //target�±���[m+1,r)
                l = m + 1;
            }
            else {
                return m;
            }
        }
        return -1;
    }
}