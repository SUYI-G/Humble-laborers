//383. �����
//����һ�������(ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ��� ransom �ܲ����ɵڶ����ַ���
//magazines ������ַ����ɡ�������Թ��ɣ����� true �����򷵻� false��
//(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼��
//��־�ַ����е�ÿ���ַ�ֻ����������ַ�����ʹ��һ�Ρ�)
//ע�⣺����Լ��������ַ�����ֻ����Сд��ĸ��

#include <iostream>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int result[26] = { 0 };
        for (int i = 0;i < magazine.length();i++) {
            result[magazine[i] - 'a']++;
        }
        for (int i = 0;i < ransomNote.length();i++) {
            result[ransomNote[i] - 'a']--;
            if (result[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};