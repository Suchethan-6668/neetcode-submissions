class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;

        int left = 0,right = n-1;
        int lm = 0,rm = 0;

        while(left <= right) {
            if(height[left] <= height[right]){
                if(height[left] >= lm){
                    lm = height[left];
                    
                }
                else {ans += (lm-height[left]);}
                left++;
            }
            else{
                if(height[right] >= rm){
                    rm = height[right];
                }
                else {ans += (rm-height[right]);}
                right--;
            }
        }
        return ans;
        
    }
};
