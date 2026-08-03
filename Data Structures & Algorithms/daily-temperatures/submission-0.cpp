class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size()); 
        stack<int> stk; //indices/days of temperatures we still need a warmer

        for (int i = 0; i < temperatures.size(); ++i) {
            int curr = temperatures[i]; 
            while (!stk.empty() && curr > temperatures[stk.top()]) {
                ans[stk.top()] = i - stk.top(); 
                stk.pop(); 
            } 
            stk.push(i); 
        }
        return ans; 
    }
};
