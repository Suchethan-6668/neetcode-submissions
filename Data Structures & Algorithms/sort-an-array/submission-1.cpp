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
    void merge(vector<int> &nums,int low,int mid,int high) {
        vector<int> temp;

        int left = low;int right = mid+1;

        while(left <= mid && right <= high) {
            if(nums[left] < nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left <= mid) {
            temp.push_back(nums[left]);
                left++;
        }
        while(right <= high){
            temp.push_back(nums[right]);
                right++;
        }
        for(int i = low ;i <= high;i++) {
            nums[i] = temp[i-low];
        }

    }
    void qc(vector<int> &nums,int low,int high) {
        if(low >= high)return;

        int pi = partition(nums,low,high);

        qc(nums,low,pi-1);
        qc(nums,pi+1,high);
    }
    void mc(vector<int> &nums,int low ,int high) {
        if(low >= high)return;
        int mid = low + (high-low)/2;

        mc(nums,low,mid);
        mc(nums,mid+1,high);
        merge(nums,low,mid,high);

    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        //qc(nums,0,n-1);
        mc(nums,0,n-1);
        return nums;
    }
        
};