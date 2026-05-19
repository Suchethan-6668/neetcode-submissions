class Solution {
public:
    string simplifyPath(string path) {
        int n  = path.size();
        stack<string> st;

        string curr = "";

        for(int i = 0; i <= path.size(); i++) {

            if(i == path.size() || path[i] == '/') {

                if(curr == "" || curr == ".") {
                    // ignore
                }

                else if(curr == "..") {

                    if(!st.empty()) {
                        st.pop();
                    }
                }

                else {

                    st.push(curr);
                }

                curr = "";
            }

            else {

                curr += path[i];
            }
        }

        if(st.empty()) return "/";

        vector<string> dirs;

        while(!st.empty()) {

            dirs.push_back(st.top());
            st.pop();
        }

        reverse(dirs.begin(), dirs.end());

        string ans = "";

        for(auto &dir : dirs) {

            ans += "/" + dir;
        }

        return ans;
        
    }
};