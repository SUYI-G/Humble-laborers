//1047. 删除字符串中的所有相邻重复项
//给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
//在 S 上反复执行重复项删除操作，直到无法继续删除。
//在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

#include <iostream>
using namespace std;
#include <stack>

//法1：使用栈
class Solution1 {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for (char a : s) {  //遍历操作，a最初表示字符串S的第一个字符,显示第一个字符后,不断执行循环,而a依次表示字符串的其他字符
            if (st.empty() || st.top() != a) {
                st.push(a);
            }
            else {
                st.pop();
            }
        }
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

//法2：使用字符串作为栈
class Solution2 {
public:
    string removeDuplicates(string s) {
        string result;
        for (char a : s) {
            if (result.empty() || result.back() != a) {
                result.push_back(a);
            }
            else {
                result.pop_back();
            }
        }
        return result;
    }
};