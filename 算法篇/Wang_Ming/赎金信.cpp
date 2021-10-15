class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int mag[26] = {0};
        for (int i = 0; i < magazine.size(); i++){
            mag[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++){
            if (mag[ransomNote[i] - 'a'] <= 0) return false;
            mag[ransomNote[i] - 'a']--;
        }
        return true;

    }
};