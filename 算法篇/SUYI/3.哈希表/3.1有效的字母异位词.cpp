//242. ��Ч����ĸ��λ��
//���������ַ���s��t����дһ���������ж�t�Ƿ���s����ĸ��λ�ʡ�
//ע�⣺��s��t��ÿ���ַ����ֵĴ�������ͬ�����s��t��Ϊ��ĸ��λ�ʡ�

#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = { 0 };
        for (int i = 0;i < s.size();i++) {
            record[s[i] - 'a']++;     //-'a'����Ϊ��һ�������ֵ������
        }
        for (int i = 0;i < t.size();i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0;i < 26;i++) {  //record�е�Ԫ��ȫΪ0��ʾ����ĸ��λ��
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};