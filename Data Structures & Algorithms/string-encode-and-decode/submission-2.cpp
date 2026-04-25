class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string &s:strs){
            res+= (to_string(s.length())+'@'+s);
            
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = s.length();

        int i = 0;
        while(i < n) {
            int k = s.find('@',i);
            int len = stoi(s.substr(i,k-i));
            res.push_back(s.substr(k+1,len));
            i = (k+1+len);
            
            
        }
        return res;
    }
};
