//��ָOffer 05.�滻�ո�
//��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��

#include <iostream>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int n_space = 0;
        for (int i = 0;i < s.size();i++) {
            if (s[i] == ' ') {
                n_space++;
            }
        }
        int oldSize = s.size();
        s.resize(s.size() + n_space * 2);
        for (int i = oldSize - 1, j = s.size() - 1;i < j;i--, j--) {
            if (s[i] != ' ') {
                s[j] = s[i];
            }
            else {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};