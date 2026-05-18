class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        if(n == 1)return 1;
        stack<float> st;
        vector<pair<int,int>> ps;
        for(int i = 0;i < n;i++) {
            ps.push_back({position[i],speed[i]});
        }
        sort(ps.begin(),ps.end());
        int ans = 0;
        for(int i = n-1;i >= 0;i--) {
            int diff = target - ps[i].first;
            float time = (float)diff/(float)ps[i].second;
            while(!st.empty() && st.top() < time){
                
                st.pop();
            }
            if(st.empty())ans++;
            st.push(time);
        }
        return ans;
    }
};
