class Solution {
public:
    bool canDo(vector<int> &a,int h,int m) {
        int n = a.size();
        int cnt = 0;

        for(int i = 0;i < n;i++) {
            if(a[i] <= m)cnt++;
            else{
                if(a[i]%m == 0) {
                    cnt += a[i]/m;
                }else {
                    cnt += (a[i]/m +1);
                }
            }
        }
        return cnt<= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int ans = *max_element(piles.begin(),piles.end());
        int high = ans;
        int low = 1;

        while(low <= high) {
            int mid = low + (high-low)/2;

            if(canDo(piles,h,mid)) {
                ans = mid;
                high = mid-1;
            }else {
                low = mid+1;
            }
        }
        return ans;
    }
};
