class TimeMap {
public:
    map<string,map<int,string>> mp;
    TimeMap() {
        mp.clear();
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        while(timestamp >= 0) {
            if(mp[key].find(timestamp) != mp[key].end()) {
                return mp[key][timestamp];
            } else {
                timestamp--;
            }
        }
        return "";
    }
};
