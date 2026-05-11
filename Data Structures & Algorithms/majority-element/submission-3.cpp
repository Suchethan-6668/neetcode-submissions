class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int mfreq = 1;
        int mele = nums[0];

        for(int i = 1;i < n;i++) {
            
            if(mfreq == 0){
                mfreq = 1;
                mele = nums[i];
            }else if(mele != nums[i])mfreq--;
            else mfreq++;
        }
        return mele;
    }
};