class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numZeros = 0;
        int prod = 1; 
        for (int i : nums){
            if (i == 0){
                numZeros++;
            }
            else {
                prod *= i; 
            }
        }
        if (numZeros >= 2){
            return vector<int>(nums.size(), 0); 
        }
        else if (numZeros == 1){
            vector<int> ans(nums.size(), 0);
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] == 0){
                    ans[i] = prod; 
                }
            }
            return ans; 
        }
        else {
            vector<int> ans;
            for (int i : nums){
                ans.push_back(prod / i); 
            }
            return ans; 
        }
    }
};
