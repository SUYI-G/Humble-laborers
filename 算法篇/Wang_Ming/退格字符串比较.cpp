class Solution {
private:
    void backspaceString(string&s){
        int slowPtr = -1;
        int fastPtr = 0;
        for (;fastPtr < s.size(); fastPtr++){
            if (s[fastPtr] == '#' && slowPtr != -1) slowPtr--;
            else if (s[fastPtr]!='#'){
                slowPtr++;
                s[slowPtr] = s[fastPtr];
            }
        }
       s.resize(slowPtr + 1);
    }
public:
    bool backspaceCompare(string s, string t) {
        backspaceString(s);
        backspaceString(t);
        // for (int i = 0; i < s.size(); i++){
        //     cout << s[i];
        // }
        if(s.size() != t.size()) return false;
        for(int i = 0; i < s.size(); i++){
            if (s[i] != t[i]) return false;
        }
        return true;

    }
};