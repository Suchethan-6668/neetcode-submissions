class FreqStack {
public:
    unordered_map<int,int> mp;
    unordered_map<int,stack<int>> mp1;
    int maxFreq = 0;
    FreqStack() {
        maxFreq = 0;
        mp.clear();
        mp1.clear();
        maxFreq = 0;
    }
    
    void push(int val) {
        
        mp[val]++;
        maxFreq = max(maxFreq,mp[val]);
        mp1[mp[val]].push(val);
    }
    
    int pop() {
        
        int ans = mp1[maxFreq].top();
        mp1[maxFreq].pop();
        mp[ans]--;

        if(mp1[maxFreq].empty())maxFreq--;

        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */