class Solution {
public:
    string replaceSpace(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == ' ') count++;
        }
        int fasrPtr = s.size() - 1;
        s.resize(s.size() + count * 2);
        
        int slowPtr = s.size() - 1;
        while (fasrPtr >= 0){
            if (s[fasrPtr] != ' '){
                s[slowPtr] = s[fasrPtr];
                slowPtr--;
                fasrPtr--;
            }
            else{
                s[slowPtr--] = '0';
                s[slowPtr--] = '2';
                s[slowPtr--] = '%';
                fasrPtr--;
            }
        }
        return s;
    }
};