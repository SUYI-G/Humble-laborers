//28. 实现 strStr()
//实现strStr()函数：给你两个字符串 haystack 和 needle ，
//请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。
//如果不存在，则返回 - 1 。

//好家伙，KMP算法看了整整4遍，最后又看了下面这篇，才搞明白Orz
//https://www.zhihu.com/question/21923021

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

    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int* next=new int[needle.size()];   //解决“表达式必须含有常量值”报错
        getNext(next, needle);
        int j = 0;
        for (int i = 0;i < haystack.size();i++) {
            while (haystack[i] != needle[j] && j > 0) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};