class Solution {
public:
    bool can(vector<int> &a,int d,int m) {
        int n = a.size();

        int cnt = 1;

        int sum =  0;

        for(int i = 0;i < n;i++) {
            if(sum + a[i] > m) {
                cnt ++;
                sum = a[i];
            }else {
                sum += a[i];
            }
        }
        return cnt <= d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans = high;
        while(low <= high) {
            int mid = low + (high-low)/2;

            if(can(weights,days,mid)) {
                ans = mid;
                high = mid-1;
            }else {
                low = mid+1;
            }
        }
        return ans;
        

        
    }
};