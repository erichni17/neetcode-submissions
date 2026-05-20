class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0; 
        // min(maxLeft, maxRight) - height[i] = amount of water trapped on top of position i
        int l = 0, r = height.size() - 1;
        int leftMax = 0, rightMax = 0, res = 0;
        while (l < r) {
            leftMax = max(leftMax, height[l]); 
            rightMax = max(rightMax, height[r]); 
            if (leftMax < rightMax) {
                res += leftMax - height[l]; 
                l++; 
            }
            else {
                res += rightMax - height[r]; 
                r--; 
            }
        }
        return res; 
    }
};
