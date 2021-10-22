class Solution {
public:
    string reverseLeftWords(string s, int n) {
        if (s.size() <= n) return s;
        string subString = s.substr(0,n);
        int j = 0;
        for (int i = n; i < s.size(); i++){
            s[j++] = s[i];
        }
        for (int i = 0; i < n; i++){
            s[j++] = subString[i];
        }
        return s;

    }
};