//541. ��ת�ַ���II
//����һ���ַ��� s ��һ������ k�����ַ�����ͷ����ÿ������ 2k ���ַ����ͷ�ת�� 2k �ַ��е�ǰ k ���ַ���
//-���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
//-���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����

#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0;i < s.size();i += 2 * k) {
            if (i + k < s.size()) {
                reverse(s.begin() + i, s.begin() + i + k);
                continue;
            }
            reverse(s.begin() + i, s.begin() + s.size());
        }
        return s;
    }
};