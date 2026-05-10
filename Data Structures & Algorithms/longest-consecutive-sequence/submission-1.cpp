class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s (nums.begin(), nums.end());
        int maxLength = 0; 
        for (int i = 0; i < nums.size(); ++i){
            if (s.count(nums[i] - 1) == 0){ //start of sequence
                int length = 1;
                while (s.find(nums[i] + length) != s.end()){
                    length++;
                }
                maxLength = max(length, maxLength); 
            }
        }
        return maxLength; 
    }
};
