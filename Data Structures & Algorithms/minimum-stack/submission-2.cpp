class MinStack {
public:
    stack<int> st;
    stack<int> m;
    MinStack() {
        while(!st.empty()){
            st.pop();
        }
        while(!m.empty())m.pop();
        
    }
    
    void push(int val) {
        st.push(val);
        if(m.empty() || val <= m.top()){
            m.push(val);

        }
    }
    
    void pop() {
        if(st.top() == m.top())m.pop();
        st.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return m.top();
    }
};
