class Solution {
public:
    int integerBreak(int n) {
        

        int maxi = 1;
        for(int k = 2;k <= n;k++) {
            int r = n%k;
            int q = n/k;
            if(n%k == 0) {
                maxi = max(maxi,((int)pow(q,k)));
            }else {
                maxi = max(maxi,((int)pow(q,k-r)*(int)pow(q+1,r)));
            }
        }
        return maxi;
    }
};