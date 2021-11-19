//151. 翻转字符串里的单词
//给你一个字符串 s ，逐个翻转字符串中的所有 单词 。
//单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
//请你返回一个翻转 s 中单词顺序并用单个空格相连的字符串。
//
//说明：
//输入字符串 s 可以在前面、后面或者单词间包含多余的空格。
//翻转后单词间应当仅用一个空格分隔。
//翻转后的字符串中不应包含额外的空格。

#include <iostream>
using namespace std;

class Solution {
public:
    void removeExtraSpacs(string& s) {
        int slowIndex = 0, fastIndex = 0;
        //为了去掉字符串前的空格，首先使fastIndex指向第1个非空格的位置
        while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ') {
            fastIndex++;
        }
        //去掉整个字符串里连续非单独的空格
        for (;fastIndex < s.size();fastIndex++) {
            if (fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ') {
                continue;
            }
            else {
                s[slowIndex] = s[fastIndex];
                slowIndex++;
            }
        }
        //如果有则去掉字符串末尾的1个空格
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