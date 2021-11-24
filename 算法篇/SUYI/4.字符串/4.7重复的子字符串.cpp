//459. 重复的子字符串
//给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。
//给定的字符串只含有小写英文字母，并且长度不超过10000。

#include <iostream>
using namespace std;

class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;    //j为前缀末尾
        next[0] = 0;
        for (int i = 1;i < s.size();i++) {    //i为后缀末尾，注意i初始化为1！
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
        if (s.size() % (s.size() - next[s.size() - 1]) == 0 && next[s.size() - 1] != 0) {   //注意别漏第2个条件
            return true;
        }
        return false;
    }
};