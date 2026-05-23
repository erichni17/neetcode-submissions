class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last;
        int l = 0, maxLength = 0; 
        for (int r = 0; r < s.length(); r++) {
            if (last.count(s[r]) && last[s[r]] >= l){
                l = last[s[r]] + 1;
            }
            last[s[r]] = r; 
            maxLength = max(maxLength, r - l + 1); 
        }
        return maxLength;
    }
};
