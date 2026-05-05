class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> words;
        for (const auto& w : strs){
            string sorted = w; 
            sort(sorted.begin(), sorted.end());
            words[sorted].push_back(w); 
        }
        
        vector<vector<string>> ans;
        for (auto& [sorted, vec] : words) {
            ans.push_back(vec);
        }
        return ans; 
    }
};
