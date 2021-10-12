class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int>map;
        while(1) {
            int sum = 0;
            while (n){
                sum += (n % 10) * (n % 10);
                n = n /10;
            }
            if (sum == 1) return true;
            if (map.find(sum) != map.end()) return false;
            map.insert(pair<int, int>(sum, 1));
            n = sum;
        }
        return true;
    }
};