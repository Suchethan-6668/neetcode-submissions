class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();

        int cnt = 1;
        unordered_map<char,int>  mp;

        for(char&c: order) {
            mp[c] = cnt++;
        }
        //int prev = 0;
        for(int i = 1;i < n;i++) {
            string w1 = words[i-1];
            string w2 = words[i];
            int mini = min(w1.length(),w2.length());
            bool diff = false;
            for(int j = 0;j < mini;j++) {
                if(w1[j] != w2[j]) {
                    if(mp[w1[j]] > mp[w2[j]]) {
                        return false;
                    }
                    diff = true;
                    break;
                }
            }
            if(!diff && w1.length() > w2.length())return false;
            
        }
        return true;
    }
};