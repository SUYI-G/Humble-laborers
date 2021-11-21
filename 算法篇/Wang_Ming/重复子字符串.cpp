class Solution {
private:
    void getNext(vector<int>&next, string s){
        int j = -1;
        next[0] = -1;
        for (int i = 1; i < s.size(); i++){
            while(j >= 0 && s[i] != s[j + 1]){
                j = next[j];
            }
            if (s[i] == s[j + 1]) j++;
            next[i] = j;
        }
    }
public:
    bool repeatedSubstringPattern(string s) {
        vector<int>next(s.size(), -1);
        getNext(next, s);
        
        int a = next[s.size() - 1];
        int b = s.size() - a - 1;
        return (a + 1 != 0)&&(a + 1)%b == 0;
    }
};