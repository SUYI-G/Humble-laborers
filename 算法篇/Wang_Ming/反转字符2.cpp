class Solution {
private:
    void reversubStr(string& s, int start, int end){
        while (start < end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
public:
    string reverseStr(string s, int k) {
        int num = s.size() / (2 * k);
        if (s.size() % (2 * k) >= 2) num++;
        int e2 = s.size() - 1;
         for (int i = 0; i < num; i++){
            int start = i*(2*k);
            int e1 =start + k - 1;
            int end = min(e1, e2); //数据类型不一样，不能使用这个函数
            reversubStr(s, start, end);
         }
         return s;
    
    }
};