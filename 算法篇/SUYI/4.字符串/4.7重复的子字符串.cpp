//459. �ظ������ַ���
//����һ���ǿյ��ַ������ж����Ƿ����������һ���Ӵ��ظ���ι��ɡ�
//�������ַ���ֻ����СдӢ����ĸ�����ҳ��Ȳ�����10000��

#include <iostream>
using namespace std;

class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;    //jΪǰ׺ĩβ
        next[0] = 0;
        for (int i = 1;i < s.size();i++) {    //iΪ��׺ĩβ��ע��i��ʼ��Ϊ1��
            while (s[j] != s[i] && j > 0) {
                j = next[j - 1];
            }
            if (s[j] == s[i]) {
                j++;
            }
            next[i] = j;
        }
    }

    bool repeatedSubstringPattern(string s) {
        if (s.size() == 0) {
            return false;
        }
        int* next = new int[s.size()];
        getNext(next, s);
        if (s.size() % (s.size() - next[s.size() - 1]) == 0 && next[s.size() - 1] != 0) {   //ע���©��2������
            return true;
        }
        return false;
    }
};