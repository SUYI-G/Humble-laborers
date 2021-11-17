//剑指Offer 05.替换空格
//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

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