class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1; 

        while (l < r) {
            int mid = l + (r - l) / 2; 
            if (nums[mid] > nums[r]) {
                l = mid + 1; 
            } else {
                r = mid; 
            }
        }

        int cut = l;
        if (target > nums[nums.size() - 1]){
            l = 0;
            r = cut;
        } else {
            l = cut;
            r = nums.size(); 
        }

        while (l < r) {
            int mid = l + (r - l) / 2; 
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) {
                r = mid; 
            } else {
                l = mid + 1; 
            }
        }

        return -1; 
    }
};
