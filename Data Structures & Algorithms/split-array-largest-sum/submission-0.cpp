class Solution {
public:

    bool lsum(vector<int> &nums,int k,int mid,int n) {
        int cnt = 1;
        int sum = 0;
        int i = 0;
        while(i < n) {
            if(sum + nums[i] > mid) {
                cnt++;
                sum = 0;
                if(cnt > k)return false;
            }
            sum += nums[i];
            i++;
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        

        int low = *max_element(nums.begin(),nums.end());
        if(k == n)return low;
        int high = accumulate(nums.begin(),nums.end(),0);
        int ans = high;

        while(low <= high) {
            int mid = low + (high-low)/2;
            
            if(lsum(nums,k,mid,n)) {
                ans = mid;
                high = mid-1;
            }else {
                low = mid+1;
            }

        }
        return ans;
    }
};