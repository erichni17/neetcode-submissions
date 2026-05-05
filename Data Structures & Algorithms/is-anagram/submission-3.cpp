class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false; 
        unordered_map<char, int> letters;
        for (char a : s){
            letters[a]++; 
        }
        for (char b : t){
            letters[b]--;
        }
        for (const auto& [letter, freq] : letters){
            if (freq != 0) return false; 
        }
        return true; 
    }
};
