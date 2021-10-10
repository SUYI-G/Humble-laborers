class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> table(26, 0);
        //统计字符串s的信息
        for (int i = 0; i < s.size(); i++){
            table[s[i] - 'a']++;
        }
        //匹配t中的信息s中是否都有
        for (int i = 0; i < t.size(); i++){
            if (table[t[i] - 'a'] == 0) return false;
            table[t[i] - 'a']--;
        }
        //s中信息t中是否都有
        for (int i = 0; i < 25; i++){
            if (table[i]) return false;
        }
        return true;

    }
};