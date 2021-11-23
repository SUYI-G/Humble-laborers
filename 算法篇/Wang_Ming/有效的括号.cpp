class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        stack<char>st;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(') st.push(')');
            else if (s[i] == '[') st.push(']');
            else if (s[i] == '{') st.push('}');
            else{
                if (st.empty()) return false;
                if (st.top() != s[i]) return false;
                st.pop();
            }
        }
        if (!st.empty()) return false;
        return true;
    }
};