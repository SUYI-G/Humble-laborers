//剑指 Offer 58 - II.左旋转字符串
//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
//请定义一个函数实现字符串左旋转操作的功能。
//比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

#include <iostream>
using namespace std;

//反转步骤（局部反转+整体反转）
//1.反转区间为前n的子串
//2.反转区间为n到末尾的子串
//3.反转整个字符串

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