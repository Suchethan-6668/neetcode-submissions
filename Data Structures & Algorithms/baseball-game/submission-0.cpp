class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();

        stack<int> st;

        for(int i =0;i < n;i++){
            char c = operations[i][0];
            string s = operations[i];
            if(c == '+'){
                int s1 = st.top();
                st.pop();
                int s2 = st.top();
                st.pop();
                int s3 = s1+s2;
                st.push(s2);
                st.push(s1);
                st.push(s3);
            }else if(c == 'D'){
                st.push(2*st.top());
            }else if(c == 'C'){
                st.pop();
            }else{
                st.push(stoi(s));
            }
        }

        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};