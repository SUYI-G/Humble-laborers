class MyStack {
public:
    queue<int>que1;
    queue<int>que2;
    MyStack() {

    }
    
    void push(int x) {
        if(que1.empty()){
            que2.push(x);
        }
        else que1.push(x);

    }
    
    int pop() {
        if (que1.empty()){
            while(que2.size()!=1){
                que1.push(que2.front());
                que2.pop();
            }
            int result = que2.front();
            que2.pop();
            return result;
        }
        else{
            while(que1.size()!=1){
                que2.push(que1.front());
                que1.pop();
            }
            int result = que1.front();
            que1.pop();
            return result;
        }

    }
    
    int top() {
        int result = this->pop();
        this->push(result);
        return result;
    }
    
    bool empty() {
        return que1.empty() && que2.empty();
    }
};