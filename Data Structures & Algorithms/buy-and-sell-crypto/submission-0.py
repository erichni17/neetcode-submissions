class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        result = 0
        minimum = prices[0]
        for i in range(len(prices)):
            minimum = min(prices[i], minimum)
            
            profit = prices[i]-minimum

            result = max(result, profit)
        return result