//��ָ Offer 58 - II.����ת�ַ���
//�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����
//�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
//���磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��

#include <iostream>
using namespace std;

//��ת���裨�ֲ���ת+���巴ת��
//1.��ת����Ϊǰn���Ӵ�
//2.��ת����Ϊn��ĩβ���Ӵ�
//3.��ת�����ַ���

class Solution {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end;i < j;i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseLeftWords(string s, int n) {
        reverse(s, 0, n - 1);
        reverse(s, n, s.size() - 1);
        reverse(s, 0, s.size() - 1);
        return s;
    }
};