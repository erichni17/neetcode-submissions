class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        array<int, 26> count;    
        for (char a : s1) {
            count[a - 'a']++; 
        }

        int l = 0;
        array<int, 26> window; 

        for (int i = 0; i < s1.length() - 1; i++) {
            window[s2[i] - 'a']++; 
        }

        for (int r = s1.length() - 1; r < s2.length(); r++) {
            window[s2[r] - 'a']++;

            if (window == count) return true; 
            window[s2[l] - 'a']--;
            l++; 
        }
        return false; 
    }
};
