class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        while(!s1.empty())s1.pop();
        while(!s1.empty())s2.pop();
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int n = s1.size();
        int i = 0;
        while(i < n-1){
            s2.push(s1.top());
            s1.pop();
            i++;
        }
        int ans = s1.top();
        s1.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    int peek() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int ans = s2.top();

        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return ans;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */