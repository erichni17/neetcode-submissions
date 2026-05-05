class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; 
        for (int i : nums){
            freq[i]++;
        }  
        priority_queue<pair<int, int>> pq; 
        for (auto [num, frequency] : freq){
            pq.push({frequency, num});
        }
        vector<int> ans;
        while (k > 0){
            auto [frequency, num] = pq.top();
            pq.pop();
            ans.push_back(num);
            k--; 
        }
        return ans; 
    }
};
