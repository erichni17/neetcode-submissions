class Solution {
public:
    bool covers(const unordered_map<char,int>& mp,
            const unordered_map<char,int>& store) {
        for (auto& [c, need] : store) {
            auto it = mp.find(c);
            if (it == mp.end() || it->second < need) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        unordered_map<char, int> store;
        unordered_map<char, int> mp; 
        for (char x : t) {
            store[x]++; 
        }
        
        int end = 0, start = 0;
        int minStart = -1; 
        int minLen = INT_MAX; 
        while (end < s.length()) {
            auto it = store.find(s[end]); 
            if (it != store.end()) {
                mp[s[end]]++; 
            } 
            while (covers(mp, store)) {
                if (!store.count(s[start])) {
                    start++; 
                    continue; 
                }
                mp[s[start]]--;
                if (end - start + 1 < minLen) {
                    minStart = start; 
                    minLen = end - start + 1; 
                }
                
                start++; 
            }
            end++; 
        }
        return minStart != -1 ? s.substr(minStart, minLen) : "" ; 
    }
};
