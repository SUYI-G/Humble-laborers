//151. ��ת�ַ�����ĵ���
//����һ���ַ��� s �������ת�ַ����е����� ���� ��
//���� ���ɷǿո��ַ���ɵ��ַ�����s ��ʹ������һ���ո��ַ����е� ���� �ָ�����
//���㷵��һ����ת s �е���˳���õ����ո��������ַ�����
//
//˵����
//�����ַ��� s ������ǰ�桢������ߵ��ʼ��������Ŀո�
//��ת�󵥴ʼ�Ӧ������һ���ո�ָ���
//��ת����ַ����в�Ӧ��������Ŀո�

#include <iostream>
using namespace std;

class Solution {
public:
    void removeExtraSpacs(string& s) {
        int slowIndex = 0, fastIndex = 0;
        //Ϊ��ȥ���ַ���ǰ�Ŀո�����ʹfastIndexָ���1���ǿո��λ��
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        //ȥ�������ַ����������ǵ����Ŀո�
        for (;fastIndex < s.size();fastIndex++) {
            if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ') {
                continue;
            }
            else {
                s[slowIndex] = s[fastIndex];
                slowIndex++;
            }
        }
        //�������ȥ���ַ���ĩβ��1���ո�
        if (slowIndex - 1 > 0 && s[slowIndex - 1] == ' ') {
            s.resize(slowIndex - 1);
        }
        else {
            s.resize(slowIndex);
        }
    }

    void reverse(string& s, int start, int end) {
        for (int i = start, j = end;i < j;i++, j--) {
            swap(s[i], s[j]);
        }
    }

    string reverseWords(string s) {
        removeExtraSpacs(s);
        reverse(s, 0, s.size() - 1);
        for (int i = 0;i < s.size();i++) {
            int j = i;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            reverse(s, i, j - 1);
            i = j;
        }
        return s;
    }
};