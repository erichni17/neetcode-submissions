class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> store;
        unordered_map<char, int> mp; 
        for (char x : t) {
            store[x]++; 
        }
        
        int end = 0, start = 0;
        int minStart = -1; 
        int minLen = INT_MAX;
        int have = 0, need = store.size(); 
        while (end < s.length()) {
            auto it = store.find(s[end]); 
            if (it != store.end()) {
                mp[s[end]]++;
                if (mp[s[end]] == store[s[end]]) have++;  
            } 
            while (have == need) {
                if (!store.count(s[start])) {
                    start++; 
                    continue; 
                }
                if (mp[s[start]] == store[s[start]]) have--; 
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
