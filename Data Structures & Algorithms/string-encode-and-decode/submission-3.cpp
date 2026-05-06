class Solution {
public:

    string encode(vector<string>& strs) {
        string res; 
        for (const string& word : strs){
            res += to_string(word.length()) + "#" + word; 
        }
        return res; 
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0; 
        while (i < s.length()){
            int j = i;
            while (s[j] != '#') j++;
            int length = stoi(s.substr(i, j-i)); 
            ans.push_back(s.substr(j + 1, length)); 
            i = j + 1 + length; 
        }
        return ans; 
    }
};
