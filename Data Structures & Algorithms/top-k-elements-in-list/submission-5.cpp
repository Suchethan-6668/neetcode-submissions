class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        map<int,vector<int>>m1;
        for(int i: nums){
            m[i]++;
        }
        for(auto x:m){
            m1[x.second].push_back(x.first);
        }
        vector<int> res;
        for(auto it = m1.rbegin();it != m1.rend();it++) {
            for(int j:it->second){
                if(k == 0)break;
                res.push_back(j);
                k--;
            }
            if(k == 0)break;
        }
        return res;
    }
};
