class Solution {
private:
    void reverseString(string& s, int start, int end){
        while(start < end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
public:
    string reverseWords(string s) {
        //首先去除字符串中的单词
        //其次对整个字符串进行反转
        //然后对单个字符进行反转

        //去除字符串中的空格
        //去除开头的空格
        int slowPtr = 0;
        int fastPtr = 0;
        while(s[fastPtr] == ' ') fastPtr++;
        
        //去除中间空格
        while(fastPtr < s.size()){
            if (s[fastPtr] != ' ') s[slowPtr++] = s[fastPtr++];
            else if (s[fastPtr - 1] != ' ') s[slowPtr++] = s[fastPtr++];
            else fastPtr++;
        }

        //去除末尾的空格
        if (s[slowPtr - 1] == ' ') s.resize(slowPtr - 1);
        else s.resize(slowPtr);
        
        
        //进行整个字符串的反转
        reverseString(s, 0, s.size() - 1);
        
        //进行单个单词的反转
        slowPtr = 0;
        for (fastPtr = 0; fastPtr < s.size(); fastPtr++){
            if (s[fastPtr] == ' ') {
                reverseString(s, slowPtr, fastPtr - 1);
                slowPtr = fastPtr + 1;
            }
        }
        reverseString(s, slowPtr, s.size() - 1);
        return s;

    }
};