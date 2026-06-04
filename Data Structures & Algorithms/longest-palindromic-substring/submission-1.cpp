class Solution {
public:
    string longestPalindrome(string s) {
        string res = ""; 
        for (int i = 0; i < s.length(); ++i){
            string temp1 = lp(i, i, s);
            if (temp1.length() > res.length()) {
                res = temp1; 
            }
            string temp2 = lp(i, i + 1, s);
            if (temp2.length() > res.length()) {
                res = temp2;
            }
        }
        return res; 
    }

    string lp(int start, int end, string &s){
        while (start >= 0 && end < s.length()
                && s[start] == s[end]) {
            start--;
            end++; 
        }
        int len = (end - 1) - (start + 1)  + 1; 
        return s.substr(start + 1, len); 
    }
};
