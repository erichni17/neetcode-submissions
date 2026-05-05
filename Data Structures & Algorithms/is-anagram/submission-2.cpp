class Solution {
public:
    bool isAnagram(string s, string t) {
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
