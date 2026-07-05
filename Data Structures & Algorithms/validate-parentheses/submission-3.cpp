class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false; 

        stack<char> stk; 

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') stk.push(')');
            else if (s[i] == '{') stk.push('}');
            else if (s[i] == '[') stk.push(']');

            if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if (stk.empty()) return false; 
                char curr = stk.top();
                stk.pop(); 
                if (curr != s[i]) return false; 
            }
        }
        if (stk.empty()) return true;
        else return false; 
    }
};
