//344. ��ת�ַ���
//��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������
//��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i = 0, j = s.size() - 1;i < j;i++, j--) {
            int temp;
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            //swap(s[i], s[j]);     //����4�п��ô��д���
        }
    }
};