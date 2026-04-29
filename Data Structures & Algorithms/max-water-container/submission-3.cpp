class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int i = 0,j = n-1;
        int ans =0;
        while(i < j) {
            int b = j-i;
            int l = min(heights[i],heights[j]);
            ans = max(ans,(l*b));

            if(heights[i] < heights[j]){
                i++;
            }else{
                j--;
            }

        }

        return ans;


    }
};
