//242. 有效的字母异位词
//给定两个字符串s和t，编写一个函数来判断t是否是s的字母异位词。
//注意：若s和t中每个字符出现的次数都相同，则称s和t互为字母异位词。

#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = { 0 };
        for (int i = 0;i < s.size();i++) {
            record[s[i] - 'a']++;     //-'a'是因为求一个相对数值就行了
        }
        for (int i = 0;i < t.size();i++) {
            record[t[i] - 'a']--;
        }
        for (int i = 0;i < 26;i++) {  //record中的元素全为0表示是字母异位词
            if (record[i] != 0) {
                return false;
            }
        }
        return true;
    }
};