class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int currMin = prices[0];  
        int maxProfit = 0; 
        for (int i = 1; i < prices.size(); ++i) { //iterate through prices to sell at
            currMin = min(currMin, prices[i]);
            maxProfit = max(maxProfit, prices[i] - currMin); 
        }
        return maxProfit; 
    }
};
