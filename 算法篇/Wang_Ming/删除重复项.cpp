class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char c : s) {
            if (st.empty() || c != st.top()) {
                st.push(c);
            } else {
                st.pop(); // s 与 st.top()相等的情况
            }
        }
        string result = "";
        while (!st.empty()) { // 将栈中元素放到result字符串汇总
            result += st.top();
            st.pop();
        }
        reverse (result.begin(), result.end()); // 此时字符串需要反转一下
        return result;

    }
};