class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> st;
        int ans = 0;
        vector<int> pse(n,-1);
        vector<int> nse(n,n);
        for(int i =0 ;i < n;i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                nse[st.top()] = i;
                st.pop();
            }
            st.push(i);
            
        }
        while(!st.empty())st.pop();
        for(int i =n-1 ;i >= 0;i--) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                pse[st.top()] = i;
                st.pop();
            }
            st.push(i);
            
        }
        for(int i = 0;i < n;i++) {
            ans = max(ans,(heights[i]*(nse[i] - pse[i]-1)));
        }
        return ans;
    }
};
