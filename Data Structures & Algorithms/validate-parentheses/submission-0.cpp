class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int> st;
        for(int i = 0;i < n;i++) {
            // if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            //     st.push(s[i]);
            // }
            if(!st.empty() && s[i] == ')' && st.top() == '('){
                st.pop();
            }
            else if(!st.empty() && s[i] == '}' && st.top() == '{'){
                st.pop();
            }
            else if(!st.empty() && s[i] == ']' && st.top() == '['){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};
