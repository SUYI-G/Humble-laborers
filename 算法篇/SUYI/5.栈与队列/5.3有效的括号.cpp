//20. 有效的括号
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。

#include <iostream>
using namespace std;
#include <stack>

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0;i < s.size();i++) {    //在匹配左括号的时候，右括号先入栈，就只需要比较当前元素和栈顶相不相等就可以了
            if (s[i] == '(') {
                st.push(')');
            }
            else if (s[i] == '{') {
                st.push('}');
            }
            else if (s[i] == '[') {
                st.push(']');
            }
            else if (st.empty() || st.top() != s[i]) { //右括号没有找到对应的左括号
                return false;
            }
            else if (st.top() == s[i]) {
                st.pop();
            }
        }
        return st.empty();  //栈不为空则左括号没有对应的右括号
    }
};