class Solution {
public:
    int sign(int val){
        return (val>0) - (val<0);
    }
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(auto curr : asteroids) {

            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && curr < 0) {

                // top explodes
                if(abs(st.top()) < abs(curr)) {
                    st.pop();
                }

                // both explode
                else if(abs(st.top()) == abs(curr)) {
                    st.pop();
                    destroyed = true;
                    break;
                }

                // current explodes
                else {
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) {
                st.push(curr);
            }
        }

        vector<int> ans(st.size());

        for(int i = st.size()-1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};