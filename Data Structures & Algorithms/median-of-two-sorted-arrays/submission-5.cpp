class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1); 
        }

        int m = nums1.size(); 
        int n = nums2.size(); 

        int l = 0; 
        int r = m; 

        int half = (m + n + 1) / 2; 

        while (l <= r) {
            int i = l + (r - l) / 2; 
            int j = half - i; 

            int Aleft = (i == 0) ? INT_MIN : nums1[i - 1]; 
            int Aright = (i == m) ? INT_MAX : nums1[i]; 

            int Bleft = (j == 0) ? INT_MIN : nums2[j - 1]; 
            int Bright = (j == n) ? INT_MAX: nums2[j]; 

            if (Aleft <= Bright && Bleft <= Aright) {
                // correct partition

                if ((m + n) % 2 == 1) {
                    return max(Aleft, Bleft); 
                }

                return (
                    max(Aleft, Bleft) 
                    + min(Aright, Bright)
                ) / 2.0; 
            }

            if (Aleft > Bright) {
                // took too much from A
                r = i - 1; 
            } else {
                // took too little from A
                l = i + 1;  
            }
        }

        return 0.0;
    }
};
