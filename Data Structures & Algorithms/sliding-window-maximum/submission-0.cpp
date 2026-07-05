class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> pq; 
        vector<int> res;
        res.reserve(k); 
        unordered_map<int, int> seen; 

        for (int i = 0; i < k; ++i) {
            pq.push(nums[i]);
            seen[nums[i]]++; 
        }

        for (int j = k; j < nums.size(); j++) {
            while (seen[pq.top()] == 0) {
                pq.pop(); 
            }
            res.push_back(pq.top());

            seen[nums[j]]++;
            pq.push(nums[j]);
            seen[nums[j-k]]--; 
        }
        
        while (seen[pq.top()] == 0) {
            pq.pop(); 
        }
        res.push_back(pq.top()); 

        return res; 
    }
};
