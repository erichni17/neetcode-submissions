class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>> > mp; 

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp}); 
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return ""; 
        vector<pair<string, int>>& vec = mp[key]; 
        int l = 0, r = vec.size() - 1; 

        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            int timestamp_prev = vec[mid].second; 
            if (timestamp_prev > timestamp) {
                r = mid - 1; 
            } else {
                l = mid; 
            }
        }
        return vec[l].second <= timestamp ? vec[l].first : ""; 
    }  
};
