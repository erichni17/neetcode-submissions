class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums; 
        for (auto& s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = nums.top(); 
                nums.pop();
                int a = nums.top(); 
                nums.pop(); 
                int result = 0;
                if (s == "+") {
                    result = a + b;
                } else if (s == "-") {
                    result = a - b; 
                } else if (s == "*") {
                    result = a * b;
                } else if (s == "/") {
                    result = a / b; 
                }
                nums.push(result); 
            } else {
                nums.push(stoi(s)); 
            }
        }
        return nums.top(); 
    }
};
