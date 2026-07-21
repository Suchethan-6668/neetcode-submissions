class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    //int sz = 0;
    int k = 0;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;

        for(int i: nums) {
            pq.push(i);
            if(pq.size() > k)pq.pop();
        }
    }
    
    int add(int val) {
        if(pq.empty())pq.push(val);

        pq.push(val);
        if(pq.size() > k)pq.pop();
        return pq.top();
    }
};
