class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);

        dp[0] = 1; 
        for (int i = 1; i < n + 1; ++i) {
            int s1 = 0;
            int s2 = 0;
            if (i - 1 >= 0) s1 = dp[i-1]; 
            if (i - 2 >= 0) s2 = dp[i-2]; 
            dp[i] = s1 + s2; 
        }
        return dp[n]; 
    }
};
