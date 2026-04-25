class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0,j = n-1;
        vector<pair<int,int>> us;
        for(int i = 0;i < n;i++){
            us.push_back({nums[i],i});
        }
        sort(us.begin(),us.end());
        while( i < j) {
            int sum = us[i].first+us[j].first;
            if(sum == target){
                int l = min(us[i].second,us[j].second);
                int r = max(us[i].second,us[j].second);
                return {l,r};
            }
            if(sum > target)j--;
            else i++;
            
        }
        return {};
    }
};
