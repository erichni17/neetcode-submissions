class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> substr; 
        int maxLength = 0; 
        int l = 0, r = 0;
        while (r < s.length()) {
            if (substr.count(s[r])) {
                while (s[l] != s[r]){
                    substr.erase(s[l]); 
                    l++;
                }
                substr.erase(s[r]); 
                l++; 
            }
            substr.insert(s[r]);
            maxLength = max(maxLength, r - l + 1); 
            r++;
        }
        return maxLength; 
    }
};
