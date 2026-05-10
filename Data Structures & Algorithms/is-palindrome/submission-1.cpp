class Solution {
public:
    bool isPalindrome(string s) {
        size_t start = 0, end = s.length()-1; 
        while (start < end){
            if (!isalnum(s[start])) start++; 
            else if (!isalnum(s[end])) end--; 
            else { //start and end are both alphanuemric
                if (tolower(s[start]) != tolower(s[end])) return false;
                start++; end--;  
            }
        }
        return true; 
    }
};
