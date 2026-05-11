class Solution {
public:
    int partition(vector<int> &nums,int low,int high) {
        int pivot = nums[high];

        int i = low;
        for(int j = low ;j <= high;j++) {
            if(nums[j] < pivot) {
                
                swap(nums[j],nums[i]);
                i++;
            }
        }
        swap(nums[high],nums[i]);
        return i;
    }
    void qc(vector<int> &nums,int low,int high) {
        if(low >= high)return;

        int pi = partition(nums,low,high);

        qc(nums,low,pi-1);
        qc(nums,pi+1,high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        qc(nums,0,n-1);
        return nums;
    }
        
};