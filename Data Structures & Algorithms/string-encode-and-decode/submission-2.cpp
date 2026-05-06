class Solution {
public:

    string encode(vector<string>& strs) {
        string res; 
        for (string word : strs){
            res += to_string(word.length());
            res += "#";
            res += word;
        }
        return res; 
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for (int i = 0; i < s.length(); i++){
            string len; 
            while (i < s.length() && isdigit(s[i])){
                len += s[i++];
            }
            int length = stoi(len);
            string part;
            part = s.substr(i + 1, length);
            ans.push_back(part); 
            i += length; 
        }
        return ans; 
    }
};
