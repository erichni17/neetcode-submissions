class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(); 
        int l = 0, r = heights.size() - 1; 
        int currMax = 0; 
        while (l < r){ 
            int amount = min(heights[l], heights[r]) * (r - l);
            if (amount > currMax) {
                currMax = amount; 
            }
            if (heights[l] <= heights[r]){
                l++; 
            }
            else { // right height greater
                r--; 
            }
        }
        return currMax; 
    }
};
