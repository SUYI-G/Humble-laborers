class MyQueue{
public:
    deque<int> que;
    void push(int value){
        while(!this->que.empty() && this->que.back() < value){
            this->que.pop_back();
        }
        this -> que.push_back(value);
    }
    int top(){
        return this -> que.front();
    }
    void pop(){
        this->que.pop_front();
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        MyQueue que = MyQueue();
        for (int i = 0; i < k; i++){
            que.push(nums[i]);
        }
        res.push_back(que.top());
        for (int i = k; i < nums.size(); i++){
            if (que.top() == nums[i - k]) que.pop();
            que.push(nums[i]);
            res.push_back(que.top());
        }
        return res;

    }
};