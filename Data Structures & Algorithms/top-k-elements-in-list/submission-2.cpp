class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; 
        for (int i : nums){
            freq[i]++;
        }  
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; 
        for (auto [num, frequency] : freq){
            pq.push({frequency, num});
            if (pq.size() > k) pq.pop(); 
        }
        vector<int> ans;
        while (!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans; 
    }
};
